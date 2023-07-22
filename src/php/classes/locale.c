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

#define PROPERTY_BASE_NAME "baseName"

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
    SET_PROPERTY_STRING_OR_NULL(object, PROPERTY_BASE_NAME, locale->baseName);
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

  add_assoc_string(return_value, PROPERTY_BASE_NAME,
                   intlLocale->locale->baseName);
}

static void freeLocaleObj(zend_object *object) {
  ecma_IntlLocale *intlLocale = ecma_IntlLocaleFromObj(object);
  zend_object_std_dtor(&intlLocale->std);
  ecma402_freeLocale(intlLocale->locale);
}
