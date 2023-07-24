/**
 * Copyright (c) php-ecma-intl contributors.
 *
 * This source file is subject to the BSD-3-Clause license that is bundled with
 * this package in the file LICENSE and is available at the following web
 * address: https://opensource.org/license/bsd-3-clause/
 *
 * This source file may utilize copyrighted material from third-party open
 * source projects, the use of which is acknowledged in the NOTICE file bundled
 * with this package.
 */

#include "php/classes/locale.h"

#include "ecma402/language_tag.h"
#include "ecma402/locale.h"

#include <Zend/zend_interfaces.h>
#include <ext/json/php_json.h>
#include <string.h>
#include <unicode/uloc.h>

#define BASE_NAME "baseName"
#define CALENDAR "calendar"
#define CASE_FIRST "caseFirst"
#define COLLATION "collation"
#define HOUR_CYCLE "hourCycle"
#define LANGUAGE "language"
#define NUMBERING_SYSTEM "numberingSystem"
#define NUMERIC "numeric"
#define REGION "region"
#define SCRIPT "script"

#define ADD_ASSOC_STRING_OR_NULL(arg, key, value)                              \
  do {                                                                         \
    if ((value) == NULL) {                                                     \
      add_assoc_null(arg, key);                                                \
    } else {                                                                   \
      add_assoc_string(arg, key, value);                                       \
    }                                                                          \
  } while (0)

#define SET_PROPERTY_NULL(object, property)                                    \
  do {                                                                         \
    zend_update_property_null(ecma_ce_IntlLocale, object, property,            \
                              sizeof(property) - 1);                           \
  } while (0)

#define SET_PROPERTY_STRING_OR_NULL(object, property, value)                   \
  do {                                                                         \
    if ((value) == NULL) {                                                     \
      SET_PROPERTY_NULL(object, property);                                     \
    } else {                                                                   \
      zend_update_property_string(ecma_ce_IntlLocale, object, property,        \
                                  sizeof(property) - 1, value);                \
    }                                                                          \
  } while (0)

zend_class_entry *ecma_ce_IntlLocale = NULL;
zend_object_handlers ecma_handlers_IntlLocale;

static void freeLocaleObj(zend_object *object);

void registerEcmaIntlLocale() {
  ecma_ce_IntlLocale = register_class_Ecma_Intl_Locale(php_json_serializable_ce,
                                                       zend_ce_stringable);
  ecma_ce_IntlLocale->create_object = ecma_createIntlLocale;

  memcpy(&ecma_handlers_IntlLocale, zend_get_std_object_handlers(),
         sizeof(zend_object_handlers));

  ecma_handlers_IntlLocale.offset = XtOffsetOf(ecma_IntlLocale, std);
  ecma_handlers_IntlLocale.free_obj = freeLocaleObj;
}

zend_object *ecma_createIntlLocale(zend_class_entry *classEntry) {
  ecma_IntlLocale *intlLocale;

  intlLocale = zend_object_alloc(sizeof(struct ecma_IntlLocale), classEntry);

  zend_object_std_init(&intlLocale->std, classEntry);
  object_properties_init(&intlLocale->std, classEntry);

  intlLocale->std.handlers = &ecma_handlers_IntlLocale;
  intlLocale->locale = NULL;

  return &intlLocale->std;
}

PHP_METHOD(Ecma_Intl_Locale, __construct) {
  char *tagArg = NULL;
  size_t tagArgLength = 0;
  ecma_IntlLocale *intlLocale;
  ecma402_locale *locale;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STRING(tagArg, tagArgLength)
  ZEND_PARSE_PARAMETERS_END();

  locale = ecma402_initLocale(tagArg);

  if (ecma402_hasError(locale->status)) {
    zend_value_error("%s", locale->status->errorMessage);
    ecma402_freeLocale(locale);
  } else {
    intlLocale = ECMA_LOCALE_P(getThis());
    intlLocale->locale = locale;

    object = &intlLocale->std;
    SET_PROPERTY_STRING_OR_NULL(object, BASE_NAME, locale->baseName);
    SET_PROPERTY_STRING_OR_NULL(object, CALENDAR, locale->calendar);
    SET_PROPERTY_STRING_OR_NULL(object, CASE_FIRST, locale->caseFirst);
    SET_PROPERTY_STRING_OR_NULL(object, COLLATION, locale->collation);
    SET_PROPERTY_STRING_OR_NULL(object, HOUR_CYCLE, locale->hourCycle);
    SET_PROPERTY_STRING_OR_NULL(object, LANGUAGE, locale->language);
    SET_PROPERTY_STRING_OR_NULL(object, NUMBERING_SYSTEM,
                                locale->numberingSystem);
    zend_update_property_bool(ecma_ce_IntlLocale, object, NUMERIC,
                              strlen(NUMERIC), locale->numeric);
    SET_PROPERTY_STRING_OR_NULL(object, REGION, locale->region);
    SET_PROPERTY_STRING_OR_NULL(object, SCRIPT, locale->script);
  }
}

PHP_METHOD(Ecma_Intl_Locale, __toString) {
  ecma_IntlLocale *intlLocale;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  RETURN_STRING(intlLocale->locale->canonical);
}

PHP_METHOD(Ecma_Intl_Locale, jsonSerialize) {
  ecma_IntlLocale *intlLocale;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  array_init(return_value);

  ADD_ASSOC_STRING_OR_NULL(return_value, BASE_NAME,
                           intlLocale->locale->baseName);
  ADD_ASSOC_STRING_OR_NULL(return_value, CALENDAR,
                           intlLocale->locale->calendar);
  ADD_ASSOC_STRING_OR_NULL(return_value, CASE_FIRST,
                           intlLocale->locale->caseFirst);
  ADD_ASSOC_STRING_OR_NULL(return_value, COLLATION,
                           intlLocale->locale->collation);
  ADD_ASSOC_STRING_OR_NULL(return_value, HOUR_CYCLE,
                           intlLocale->locale->hourCycle);
  ADD_ASSOC_STRING_OR_NULL(return_value, LANGUAGE,
                           intlLocale->locale->language);
  ADD_ASSOC_STRING_OR_NULL(return_value, NUMBERING_SYSTEM,
                           intlLocale->locale->numberingSystem);
  add_assoc_bool(return_value, NUMERIC, intlLocale->locale->numeric);
  ADD_ASSOC_STRING_OR_NULL(return_value, REGION, intlLocale->locale->region);
  ADD_ASSOC_STRING_OR_NULL(return_value, SCRIPT, intlLocale->locale->script);
}

static void freeLocaleObj(zend_object *object) {
  ecma_IntlLocale *intlLocale = ecma_IntlLocaleFromObj(object);
  zend_object_std_dtor(&intlLocale->std);
  ecma402_freeLocale(intlLocale->locale);
}
