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

#include "ecma402/calendar.h"
#include "ecma402/collation.h"
#include "ecma402/language_tag.h"
#include "ecma402/locale.h"
#include "php/classes/locale_options.h"

#include <Zend/zend_interfaces.h>
#include <ext/json/php_json.h>
#include <string.h>
#include <unicode/uloc.h>

#define ADD_PROPERTY_OR_NULL(arg, property)                                    \
  do {                                                                         \
    zval *property = zend_read_property(ecma_ce_IntlLocale, object, #property, \
                                        strlen(#property), true, NULL);        \
    ZVAL_DEREF(property);                                                      \
    if (Z_TYPE_P(property) == IS_STRING) {                                     \
      add_property_string(arg, #property, Z_STRVAL_P(property));               \
    } else if (Z_TYPE_P(property) == IS_FALSE) {                               \
      add_property_bool(arg, #property, false);                                \
    } else if (Z_TYPE_P(property) == IS_TRUE) {                                \
      add_property_bool(arg, #property, true);                                 \
    } else {                                                                   \
      add_property_null(arg, #property);                                       \
    }                                                                          \
  } while (0)

zend_class_entry *ecma_ce_IntlLocale = NULL;
zend_object_handlers ecma_handlers_IntlLocale;

static ecma402_locale *applyOptions(ecma402_locale *locale,
                                    zend_object *options);
static void freeLocaleObj(zend_object *object);
static int getNumericProperty(zend_object *options);
static const char *getProperty(zend_object *options, const char *property);
static void maxOrMin(bool doMaximize, ecma_IntlLocale *locale, zval *dest);
static void setBaseName(zend_object *object, ecma402_locale *locale);
static void setCalendar(zend_object *object, ecma402_locale *locale);
static void setCalendars(zend_object *object, ecma402_locale *locale);
static void setCaseFirst(zend_object *object, ecma402_locale *locale);
static void setCollation(zend_object *object, ecma402_locale *locale);
static void setCollations(zend_object *object, ecma402_locale *locale);
static void setHourCycle(zend_object *object, ecma402_locale *locale);
static void setLanguage(zend_object *object, ecma402_locale *locale);
static void setNumberingSystem(zend_object *object, ecma402_locale *locale);
static void setNumeric(zend_object *object, ecma402_locale *locale);
static void setRegion(zend_object *object, ecma402_locale *locale);
static void setScript(zend_object *object, ecma402_locale *locale);

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
  ecma_IntlLocale *intlLocale;
  ecma402_locale *locale;
  zend_object *object, *options = NULL, *tagArgObj = NULL;
  zend_string *tagArgString = NULL;

  ZEND_PARSE_PARAMETERS_START(1, 2)
  Z_PARAM_OBJ_OF_CLASS_OR_STR(tagArgObj, zend_ce_stringable, tagArgString)
  Z_PARAM_OPTIONAL
  Z_PARAM_OBJ_OF_CLASS_OR_NULL(options, ecma_ce_IntlLocaleOptions)
  ZEND_PARSE_PARAMETERS_END();

  if (tagArgString != NULL) {
    locale = ecma402_initLocale(ZSTR_VAL(tagArgString));
  } else {
    zval tagString;
    zend_std_cast_object_tostring(tagArgObj, &tagString, IS_STRING);

    if (EG(exception)) {
      RETURN_THROWS();
    }

    locale = ecma402_initLocale(Z_STRVAL(tagString));
    zval_ptr_dtor(&tagString);
  }

  if (ecma402_hasError(locale->status)) {
    zend_value_error("%s", locale->status->errorMessage);
    ecma402_freeLocale(locale);
  } else {
    if (options != NULL) {
      ecma402_locale *newLocale = applyOptions(locale, options);
      ecma402_freeLocale(locale);

      if (ecma402_hasError(newLocale->status)) {
        zend_value_error("%s", newLocale->status->errorMessage);
        ecma402_freeLocale(newLocale);
        RETURN_THROWS();
      }

      locale = newLocale;
    }

    intlLocale = ECMA_LOCALE_P(getThis());
    intlLocale->locale = locale;
    object = &intlLocale->std;

    setBaseName(object, locale);
    setCalendar(object, locale);
    setCalendars(object, locale);
    setCaseFirst(object, locale);
    setCollation(object, locale);
    setCollations(object, locale);
    setHourCycle(object, locale);
    setLanguage(object, locale);
    setNumberingSystem(object, locale);
    setNumeric(object, locale);
    setRegion(object, locale);
    setScript(object, locale);
  }
}

PHP_METHOD(Ecma_Intl_Locale, __toString) {
  ecma_IntlLocale *intlLocale;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  RETURN_STRING(intlLocale->locale->canonical);
}

PHP_METHOD(Ecma_Intl_Locale, getCalendars) {
  ecma_IntlLocale *intlLocale;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());
  object = &intlLocale->std;

  zval *property = zend_read_property(ecma_ce_IntlLocale, object, "calendars",
                                      strlen("calendars"), true, NULL);

  RETURN_COPY_DEREF(property);
}

PHP_METHOD(Ecma_Intl_Locale, getCollations) {
  ecma_IntlLocale *intlLocale;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());
  object = &intlLocale->std;

  zval *property = zend_read_property(ecma_ce_IntlLocale, object, "collations",
                                      strlen("collations"), true, NULL);

  RETURN_COPY_DEREF(property);
}

PHP_METHOD(Ecma_Intl_Locale, jsonSerialize) {
  ecma_IntlLocale *intlLocale;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());
  object = &intlLocale->std;

  object_init(return_value);

  ADD_PROPERTY_OR_NULL(return_value, baseName);
  ADD_PROPERTY_OR_NULL(return_value, calendar);
  ADD_PROPERTY_OR_NULL(return_value, caseFirst);
  ADD_PROPERTY_OR_NULL(return_value, collation);
  ADD_PROPERTY_OR_NULL(return_value, hourCycle);
  ADD_PROPERTY_OR_NULL(return_value, language);
  ADD_PROPERTY_OR_NULL(return_value, numberingSystem);
  ADD_PROPERTY_OR_NULL(return_value, numeric);
  ADD_PROPERTY_OR_NULL(return_value, region);
  ADD_PROPERTY_OR_NULL(return_value, script);
}

PHP_METHOD(Ecma_Intl_Locale, maximize) {
  ecma_IntlLocale *intlLocale, *new;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  new = ecma_IntlLocaleFromObj(ecma_createIntlLocale(ecma_ce_IntlLocale));
  RETVAL_OBJ(&new->std);

  maxOrMin(true, intlLocale, return_value);
}

PHP_METHOD(Ecma_Intl_Locale, minimize) {
  ecma_IntlLocale *intlLocale, *new;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  new = ecma_IntlLocaleFromObj(ecma_createIntlLocale(ecma_ce_IntlLocale));
  RETVAL_OBJ(&new->std);

  maxOrMin(false, intlLocale, return_value);
}

static ecma402_locale *applyOptions(ecma402_locale *locale,
                                    zend_object *options) {
  const char *calendar = getProperty(options, "calendar");
  const char *caseFirst = getProperty(options, "caseFirst");
  const char *collation = getProperty(options, "collation");
  const char *hourCycle = getProperty(options, "hourCycle");
  const char *language = getProperty(options, "language");
  const char *numberingSystem = getProperty(options, "numberingSystem");
  int numeric = getNumericProperty(options);
  const char *region = getProperty(options, "region");
  const char *script = getProperty(options, "script");

  return ecma402_applyLocaleOptions(locale, calendar, caseFirst, collation,
                                    hourCycle, language, numberingSystem,
                                    numeric, region, script);
}

static void freeLocaleObj(zend_object *object) {
  ecma_IntlLocale *intlLocale = ecma_IntlLocaleFromObj(object);
  zend_object_std_dtor(&intlLocale->std);
  ecma402_freeLocale(intlLocale->locale);
}

static int getNumericProperty(zend_object *options) {
  zval *optionProperty =
      zend_read_property(ecma_ce_IntlLocaleOptions, options, "numeric",
                         strlen("numeric"), true, NULL);
  ZVAL_DEREF(optionProperty);

  if (Z_TYPE_P(optionProperty) == IS_TRUE) {
    return true;
  }

  if (Z_TYPE_P(optionProperty) == IS_FALSE) {
    return false;
  }

  return -1;
}

static const char *getProperty(zend_object *options, const char *property) {
  zval *optionProperty =
      zend_read_property(ecma_ce_IntlLocaleOptions, options, property,
                         strlen(property), true, NULL);
  ZVAL_DEREF(optionProperty);

  if (Z_TYPE_P(optionProperty) == IS_STRING) {
    return Z_STRVAL_P(optionProperty);
  }

  return NULL;
}

static void maxOrMin(bool doMaximize, ecma_IntlLocale *locale, zval *dest) {
  ecma402_errorStatus *status;
  zval arg1;
  char *value;
  size_t length;

  value = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  status = ecma402_initErrorStatus();

  if (doMaximize) {
    length = ecma402_maximize(locale->locale->canonical, value, status);
  } else {
    length = ecma402_minimize(locale->locale->canonical, value, status);
  }

  if (ecma402_hasError(status)) {
    strcpy(value, locale->locale->canonical);
    length = strlen(locale->locale->canonical);
  }

  ZVAL_STRINGL(&arg1, value, length);
  zend_call_method_with_1_params(Z_OBJ_P(dest), ecma_ce_IntlLocale,
                                 &ecma_ce_IntlLocale->constructor,
                                 "__construct", NULL, &arg1);

  zval_ptr_dtor(&arg1);
  ecma402_freeErrorStatus(status);
  efree(value);
}

static void setBaseName(zend_object *object, ecma402_locale *locale) {
  const char *name = "baseName";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->baseName == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->baseName);
  }
}

static void setCalendar(zend_object *object, ecma402_locale *locale) {
  const char *name = "calendar";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->calendar == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->calendar);
  }
}

static void setCalendars(zend_object *object, ecma402_locale *locale) {
  const char *name = "calendars", **values;
  const size_t length = strlen(name);
  int valuesCount;
  zend_class_entry *ce = ecma_ce_IntlLocale;
  zval propertyValue;

  values = (const char **)emalloc(sizeof(const char *) *
                                  ECMA402_LOCALE_CALENDAR_CAPACITY);
  valuesCount = ecma402_calendarsOfLocale(locale->canonical, values);

  ZVAL_ARR(&propertyValue, zend_new_array(valuesCount));
  for (int i = 0; i < valuesCount; i++) {
    add_next_index_string(&propertyValue, values[i]);
  }

  if (values) {
    efree(values);
  }

  zend_update_property(ce, object, name, length, &propertyValue);
  zval_ptr_dtor(&propertyValue);
}

static void setCaseFirst(zend_object *object, ecma402_locale *locale) {
  const char *name = "caseFirst";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->caseFirst == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->caseFirst);
  }
}

static void setCollation(zend_object *object, ecma402_locale *locale) {
  const char *name = "collation";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->collation == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->collation);
  }
}

static void setCollations(zend_object *object, ecma402_locale *locale) {
  const char *name = "collations", **values;
  const size_t length = strlen(name);
  int valuesCount;
  zend_class_entry *ce = ecma_ce_IntlLocale;
  zval propertyValue;

  values = (const char **)emalloc(sizeof(const char *) *
                                  ECMA402_LOCALE_COLLATION_CAPACITY);
  valuesCount = ecma402_collationsOfLocale(locale->canonical, values);

  ZVAL_ARR(&propertyValue, zend_new_array(valuesCount));
  for (int i = 0; i < valuesCount; i++) {
    add_next_index_string(&propertyValue, values[i]);
  }

  if (values) {
    efree(values);
  }

  zend_update_property(ce, object, name, length, &propertyValue);
  zval_ptr_dtor(&propertyValue);
}

static void setHourCycle(zend_object *object, ecma402_locale *locale) {
  const char *name = "hourCycle";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->hourCycle == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->hourCycle);
  }
}

static void setLanguage(zend_object *object, ecma402_locale *locale) {
  const char *name = "language";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->language == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->language);
  }
}

static void setNumberingSystem(zend_object *object, ecma402_locale *locale) {
  const char *name = "numberingSystem";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->numberingSystem == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length,
                                locale->numberingSystem);
  }
}

static void setNumeric(zend_object *object, ecma402_locale *locale) {
  const char *name = "numeric";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  zend_update_property_bool(ce, object, name, length, locale->numeric);
}

static void setRegion(zend_object *object, ecma402_locale *locale) {
  const char *name = "region";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->region == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->region);
  }
}

static void setScript(zend_object *object, ecma402_locale *locale) {
  const char *name = "script";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocale;

  if (locale->script == NULL) {
    zend_update_property_null(ce, object, name, length);
  } else {
    zend_update_property_string(ce, object, name, length, locale->script);
  }
}
