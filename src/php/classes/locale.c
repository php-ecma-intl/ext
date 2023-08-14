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
#include "ecma402/currency.h"
#include "ecma402/hour_cycle.h"
#include "ecma402/language_tag.h"
#include "ecma402/locale.h"
#include "ecma402/numbering_system.h"
#include "ecma402/time_zone.h"
#include "php/classes/locale_character_direction.h"
#include "php/classes/locale_options.h"
#include "php/classes/locale_text_info.h"

#include <Zend/zend_interfaces.h>
#include <ext/json/php_json.h>
#include <string.h>
#include <unicode/uloc.h>

#define ADD_TO_JSON(property)                                                  \
  do {                                                                         \
    addToJson(ecma_ce_IntlLocale, intlLocale, #property, return_value);        \
  } while (0)

#define RETURN_PROPERTY(property)                                              \
  do {                                                                         \
    ZEND_PARSE_PARAMETERS_NONE();                                              \
    returnProperty(ecma_ce_IntlLocale, ECMA_LOCALE_P(getThis()), #property,    \
                   return_value);                                              \
  } while (0)

#define SET_PROPERTY_ARRAY(property, capacity)                                 \
  do {                                                                         \
    setPropertyArray(ecma_ce_IntlLocale, intlLocale, #property, capacity,      \
                     ecma402_##property##OfLocale);                            \
  } while (0)

#define SET_PROPERTY_STRING(property)                                          \
  do {                                                                         \
    setPropertyString(ecma_ce_IntlLocale, intlLocale, #property,               \
                      locale->property);                                       \
  } while (0)

zend_class_entry *ecma_ce_IntlLocale = NULL;
zend_object_handlers ecma_handlers_IntlLocale;

static void addToJson(zend_class_entry *ce, ecma_IntlLocale *this,
                      const char *name, zval *jsonObject);
static ecma402_locale *applyOptions(ecma402_locale *locale,
                                    zend_object *options);
static void freeLocaleObj(zend_object *object);
static const char *getOption(zend_object *options, const char *name);
static int getOptionNumeric(zend_object *options);
static void maxOrMin(bool doMaximize, ecma_IntlLocale *locale, zval *dest);
static void returnProperty(zend_class_entry *ce, ecma_IntlLocale *this,
                           const char *name, zval *returnValue);
static void setPropertyArray(zend_class_entry *ce, ecma_IntlLocale *this,
                             const char *name, int capacity,
                             int (*callback)(ecma402_locale *, const char **));
static void setPropertyString(zend_class_entry *ce, ecma_IntlLocale *this,
                              const char *name, const char *value);

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

    SET_PROPERTY_STRING(baseName);
    SET_PROPERTY_STRING(calendar);
    SET_PROPERTY_ARRAY(calendars, ECMA402_LOCALE_CALENDAR_CAPACITY);
    SET_PROPERTY_STRING(caseFirst);
    SET_PROPERTY_STRING(collation);
    SET_PROPERTY_ARRAY(collations, ECMA402_LOCALE_COLLATION_CAPACITY);
    SET_PROPERTY_ARRAY(currencies, ECMA402_LOCALE_CURRENCY_CAPACITY);
    SET_PROPERTY_STRING(hourCycle);
    SET_PROPERTY_ARRAY(hourCycles, ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
    SET_PROPERTY_STRING(language);
    SET_PROPERTY_STRING(numberingSystem);
    SET_PROPERTY_ARRAY(numberingSystems,
                       ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
    zend_update_property_bool(ecma_ce_IntlLocale, object, "numeric",
                              strlen("numeric"), locale->numeric);
    SET_PROPERTY_STRING(region);
    SET_PROPERTY_STRING(script);
    SET_PROPERTY_ARRAY(timeZones, ECMA402_LOCALE_TIME_ZONE_CAPACITY);
  }
}

PHP_METHOD(Ecma_Intl_Locale, __toString) {
  ecma_IntlLocale *intlLocale;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  RETURN_STRING(intlLocale->locale->canonical);
}

PHP_METHOD(Ecma_Intl_Locale, getCalendars) { RETURN_PROPERTY(calendars); }

PHP_METHOD(Ecma_Intl_Locale, getCollations) { RETURN_PROPERTY(collations); }

PHP_METHOD(Ecma_Intl_Locale, getCurrencies) { RETURN_PROPERTY(currencies); }

PHP_METHOD(Ecma_Intl_Locale, getHourCycles) { RETURN_PROPERTY(hourCycles); }

PHP_METHOD(Ecma_Intl_Locale, getNumberingSystems) {
  RETURN_PROPERTY(numberingSystems);
}

PHP_METHOD(Ecma_Intl_Locale, getTimeZones) { RETURN_PROPERTY(timeZones); }

PHP_METHOD(Ecma_Intl_Locale, jsonSerialize) {
  ecma_IntlLocale *intlLocale;

  ZEND_PARSE_PARAMETERS_NONE();

  object_init(return_value);
  intlLocale = ECMA_LOCALE_P(getThis());

  ADD_TO_JSON(baseName);
  ADD_TO_JSON(calendar);
  ADD_TO_JSON(calendars);
  ADD_TO_JSON(caseFirst);
  ADD_TO_JSON(collation);
  ADD_TO_JSON(collations);
  ADD_TO_JSON(currencies);
  ADD_TO_JSON(hourCycle);
  ADD_TO_JSON(hourCycles);
  ADD_TO_JSON(language);
  ADD_TO_JSON(numberingSystem);
  ADD_TO_JSON(numberingSystems);
  ADD_TO_JSON(numeric);
  ADD_TO_JSON(region);
  ADD_TO_JSON(script);
  ADD_TO_JSON(timeZones);
}

PHP_METHOD(Ecma_Intl_Locale, maximize) {
  ecma_IntlLocale *intlLocale;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  object = ecma_createIntlLocale(ecma_ce_IntlLocale);
  RETVAL_OBJ(object);

  maxOrMin(true, intlLocale, return_value);
}

PHP_METHOD(Ecma_Intl_Locale, minimize) {
  ecma_IntlLocale *intlLocale;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocale = ECMA_LOCALE_P(getThis());

  object = ecma_createIntlLocale(ecma_ce_IntlLocale);
  RETVAL_OBJ(object);

  maxOrMin(false, intlLocale, return_value);
}

static void addToJson(zend_class_entry *ce, ecma_IntlLocale *this,
                      const char *name, zval *jsonObject) {
  zval *property, rv;
  property = zend_read_property(ce, &this->std, name, strlen(name), false, &rv);
  Z_TRY_ADDREF_P(property);
  add_property_zval(jsonObject, name, property);
}

static ecma402_locale *applyOptions(ecma402_locale *locale,
                                    zend_object *options) {
  const char *calendar = getOption(options, "calendar");
  const char *caseFirst = getOption(options, "caseFirst");
  const char *collation = getOption(options, "collation");
  const char *hourCycle = getOption(options, "hourCycle");
  const char *language = getOption(options, "language");
  const char *numberingSystem = getOption(options, "numberingSystem");
  int numeric = getOptionNumeric(options);
  const char *region = getOption(options, "region");
  const char *script = getOption(options, "script");

  return ecma402_applyLocaleOptions(locale, calendar, caseFirst, collation,
                                    hourCycle, language, numberingSystem,
                                    numeric, region, script);
}

static void freeLocaleObj(zend_object *object) {
  ecma_IntlLocale *intlLocale = ecma_IntlLocaleFromObj(object);
  zend_object_std_dtor(&intlLocale->std);
  ecma402_freeLocale(intlLocale->locale);
}

static const char *getOption(zend_object *options, const char *name) {
  zval *property, rv;

  property = zend_read_property(ecma_ce_IntlLocaleOptions, options, name,
                                strlen(name), false, &rv);
  ZVAL_DEREF(property);

  if (Z_TYPE_P(property) == IS_STRING) {
    return Z_STRVAL_P(property);
  }

  return NULL;
}

static int getOptionNumeric(zend_object *options) {
  zval *property, rv;

  property = zend_read_property(ecma_ce_IntlLocaleOptions, options, "numeric",
                                strlen("numeric"), false, &rv);
  ZVAL_DEREF(property);

  if (Z_TYPE_P(property) == IS_TRUE) {
    return true;
  }

  if (Z_TYPE_P(property) == IS_FALSE) {
    return false;
  }

  return -1;
}

static void maxOrMin(bool doMaximize, ecma_IntlLocale *locale, zval *dest) {
  ecma402_errorStatus *status;
  zval arg1;
  char *value;
  size_t length;

  value = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  status = ecma402_initErrorStatus();

  if (doMaximize) {
    length = ecma402_maximize(locale->locale->canonical, value, status, true);
  } else {
    length = ecma402_minimize(locale->locale->canonical, value, status, true);
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

static void returnProperty(zend_class_entry *ce, ecma_IntlLocale *this,
                           const char *name, zval *returnValue) {
  zval *property, rv;
  property = zend_read_property(ce, &this->std, name, strlen(name), false, &rv);
  ZVAL_DEREF(property);
  ZVAL_COPY(returnValue, property);
}

static void setPropertyArray(zend_class_entry *ce, ecma_IntlLocale *this,
                             const char *name, int capacity,
                             int (*callback)(ecma402_locale *, const char **)) {
  const char **values;
  int valuesCount;
  zval propertyValue;

  values = (const char **)emalloc(sizeof(const char *) * capacity);
  valuesCount = (callback)(this->locale, values);

  if (valuesCount == -1) {
    zend_update_property_null(ce, &this->std, name, strlen(name));
    efree(values);
    return;
  }

  ZVAL_ARR(&propertyValue, zend_new_array(valuesCount));
  for (int i = 0; i < valuesCount; i++) {
    add_next_index_string(&propertyValue, values[i]);
  }

  zend_update_property(ce, &this->std, name, strlen(name), &propertyValue);

  zval_ptr_dtor(&propertyValue);
  efree(values);
}

static void setPropertyString(zend_class_entry *ce, ecma_IntlLocale *this,
                              const char *name, const char *value) {
  if (value == NULL) {
    zend_update_property_null(ce, &this->std, name, strlen(name));
  } else {
    zend_update_property_string(ce, &this->std, name, strlen(name), value);
  }
}
