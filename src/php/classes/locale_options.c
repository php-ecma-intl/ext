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

#include "php/classes/locale_options.h"

#include "ecma402/language_tag.h"

#include <Zend/zend_interfaces.h>
#include <ext/json/php_json.h>

#define ADD_PROPERTY_IF_SET(arg, property)                                     \
  do {                                                                         \
    zval *property =                                                           \
        zend_read_property(ecma_ce_IntlLocaleOptions, object, #property,       \
                           strlen(#property), true, NULL);                     \
    if (Z_TYPE_P(property) == IS_STRING) {                                     \
      add_property_string(arg, #property, Z_STRVAL_P(property));               \
    } else if (Z_TYPE_P(property) == IS_FALSE) {                               \
      add_property_bool(arg, #property, false);                                \
    } else if (Z_TYPE_P(property) == IS_TRUE) {                                \
      add_property_bool(arg, #property, true);                                 \
    }                                                                          \
  } while (0)

zend_class_entry *ecma_ce_IntlLocaleOptions = NULL;
zend_object_handlers ecma_handlers_IntlLocaleOptions;

static void freeLocaleOptionsObj(zend_object *object);
static const char *getPropertyNameForEnum(ecma_localeOption option);
static bool isCaseFirst(const char *value);
static bool isHourCycle(const char *value);
static bool isValidCaseFirstParam(zval *param);
static void setCalendar(zend_object *object, zend_string *paramStr,
                        zend_object *paramObj);
static void setCaseFirst(zend_object *object, zval *param);
static void setCollation(zend_object *object, zend_string *paramStr,
                         zend_object *paramObj);
static void setHourCycle(zend_object *object, zend_string *paramStr,
                         zend_object *paramObj);
static void setLanguage(zend_object *object, zend_string *paramStr,
                        zend_object *paramObj);
static void setNumberingSystem(zend_object *object, zend_string *paramStr,
                               zend_object *paramObj);
static void setNumeric(zend_object *object, bool numeric, bool isNumericNull);
static bool setProperty(const char *name, zend_object *object,
                        zend_string *valueStr, zend_object *valueObj,
                        bool (*validator)(const char *));
static void setRegion(zend_object *object, zend_string *paramStr,
                      zend_object *paramObj);
static void setScript(zend_object *object, zend_string *paramStr,
                      zend_object *paramObj);

void registerEcmaIntlLocaleOptions() {
  ecma_ce_IntlLocaleOptions = register_class_Ecma_Intl_Locale_Options(
      zend_ce_iterator, php_json_serializable_ce);
  ecma_ce_IntlLocaleOptions->create_object = ecma_createIntlLocaleOptions;

  memcpy(&ecma_handlers_IntlLocaleOptions, zend_get_std_object_handlers(),
         sizeof(zend_object_handlers));

  ecma_handlers_IntlLocaleOptions.offset =
      XtOffsetOf(ecma_IntlLocaleOptions, std);
  ecma_handlers_IntlLocaleOptions.free_obj = freeLocaleOptionsObj;
}

zend_object *ecma_createIntlLocaleOptions(zend_class_entry *classEntry) {
  ecma_IntlLocaleOptions *intlLocaleOptions;

  intlLocaleOptions =
      zend_object_alloc(sizeof(struct ecma_IntlLocaleOptions), classEntry);

  zend_object_std_init(&intlLocaleOptions->std, classEntry);
  object_properties_init(&intlLocaleOptions->std, classEntry);

  intlLocaleOptions->std.handlers = &ecma_handlers_IntlLocaleOptions;
  intlLocaleOptions->allNull = true;
  intlLocaleOptions->iteratorCurrent = CALENDAR;

  return &intlLocaleOptions->std;
}

PHP_METHOD(Ecma_Intl_Locale_Options, __construct) {
  zend_string *calendar = NULL, *collation = NULL, *hourCycle = NULL,
              *language = NULL, *numberingSystem = NULL, *region = NULL,
              *script = NULL;
  zend_object *calendarObj = NULL, *collationObj = NULL, *hourCycleObj = NULL,
              *languageObj = NULL, *numberingSystemObj = NULL,
              *regionObj = NULL, *scriptObj = NULL;
  zval *caseFirst = NULL;
  bool numeric = false, isNumericNull = true;
  ecma_IntlLocaleOptions *intlLocaleOptions;
  zend_object *object;
  zend_class_entry *stringable = zend_ce_stringable;

  ZEND_PARSE_PARAMETERS_START(0, 9)
  Z_PARAM_OPTIONAL
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(calendarObj, stringable, calendar)
  Z_PARAM_ZVAL_OR_NULL(caseFirst)
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(collationObj, stringable, collation)
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(hourCycleObj, stringable, hourCycle)
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(languageObj, stringable, language)
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(numberingSystemObj, stringable,
                                      numberingSystem)
  Z_PARAM_BOOL_OR_NULL(numeric, isNumericNull)
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(regionObj, stringable, region)
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(scriptObj, stringable, script)
  ZEND_PARSE_PARAMETERS_END();

  if (caseFirst != NULL && !isValidCaseFirstParam(caseFirst)) {
    RETURN_THROWS();
  }

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());
  object = &intlLocaleOptions->std;

  intlLocaleOptions->allNull =
      (calendar == NULL && calendarObj == NULL && caseFirst == NULL &&
       collation == NULL && collationObj == NULL && hourCycle == NULL &&
       hourCycleObj == NULL && language == NULL && languageObj == NULL &&
       numberingSystem == NULL && numberingSystemObj == NULL && isNumericNull &&
       region == NULL && regionObj == NULL && script == NULL &&
       scriptObj == NULL);

  setCalendar(object, calendar, calendarObj);
  setCaseFirst(object, caseFirst);
  setCollation(object, collation, collationObj);
  setHourCycle(object, hourCycle, hourCycleObj);
  setLanguage(object, language, languageObj);
  setNumberingSystem(object, numberingSystem, numberingSystemObj);
  setNumeric(object, numeric, isNumericNull);
  setRegion(object, region, regionObj);
  setScript(object, script, scriptObj);
}

PHP_METHOD(Ecma_Intl_Locale_Options, jsonSerialize) {
  ecma_IntlLocaleOptions *intlLocaleOptions;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_NONE();

  object_init(return_value);

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());
  object = &intlLocaleOptions->std;

  ADD_PROPERTY_IF_SET(return_value, calendar);
  ADD_PROPERTY_IF_SET(return_value, caseFirst);
  ADD_PROPERTY_IF_SET(return_value, collation);
  ADD_PROPERTY_IF_SET(return_value, hourCycle);
  ADD_PROPERTY_IF_SET(return_value, language);
  ADD_PROPERTY_IF_SET(return_value, numberingSystem);
  ADD_PROPERTY_IF_SET(return_value, numeric);
  ADD_PROPERTY_IF_SET(return_value, region);
  ADD_PROPERTY_IF_SET(return_value, script);
}

PHP_METHOD(Ecma_Intl_Locale_Options, current) {
  ecma_IntlLocaleOptions *intlLocaleOptions;
  zend_object *object;
  zval *value;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());
  object = &intlLocaleOptions->std;

  // Advance to the first non-null value and return it. We want to allow
  // unpacking this object in an array, but we don't want null elements in the
  // unpacked array.
  do {
    const char *name =
        getPropertyNameForEnum(intlLocaleOptions->iteratorCurrent);
    value = zend_read_property(ecma_ce_IntlLocaleOptions, object, name,
                               strlen(name), true, NULL);

    if (!ZVAL_IS_NULL(value)) {
      break;
    }

    intlLocaleOptions->iteratorCurrent++;

  } while (intlLocaleOptions->iteratorCurrent <= ECMA_LOCALE_OPTION_COUNT);

  if (Z_TYPE_P(value) == IS_STRING) {
    RETURN_STRING(Z_STRVAL_P(value));
  } else if (Z_TYPE_P(value) == IS_TRUE) {
    RETURN_TRUE;
  } else if (Z_TYPE_P(value) == IS_FALSE) {
    RETURN_FALSE;
  }
}

PHP_METHOD(Ecma_Intl_Locale_Options, key) {
  ecma_IntlLocaleOptions *intlLocaleOptions;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());

  RETURN_STRING(getPropertyNameForEnum(intlLocaleOptions->iteratorCurrent));
}

PHP_METHOD(Ecma_Intl_Locale_Options, next) {
  ecma_IntlLocaleOptions *intlLocaleOptions;
  zend_object *object;
  zval *value;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());
  object = &intlLocaleOptions->std;

  // Advance to the next non-null value. We want to allow unpacking this object
  // in an array, but we don't want null elements in the unpacked array.
  do {
    intlLocaleOptions->iteratorCurrent++;

    const char *name =
        getPropertyNameForEnum(intlLocaleOptions->iteratorCurrent);

    if (name == NULL) {
      break;
    }

    value = zend_read_property(ecma_ce_IntlLocaleOptions, object, name,
                               strlen(name), true, NULL);

  } while (intlLocaleOptions->iteratorCurrent <= ECMA_LOCALE_OPTION_COUNT &&
           ZVAL_IS_NULL(value));
}

PHP_METHOD(Ecma_Intl_Locale_Options, rewind) {
  ecma_IntlLocaleOptions *intlLocaleOptions;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());
  intlLocaleOptions->iteratorCurrent = CALENDAR;
}

PHP_METHOD(Ecma_Intl_Locale_Options, valid) {
  ecma_IntlLocaleOptions *intlLocaleOptions;

  ZEND_PARSE_PARAMETERS_NONE();

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());

  if (intlLocaleOptions->allNull) {
    RETURN_FALSE;
  }

  if (intlLocaleOptions->iteratorCurrent <= ECMA_LOCALE_OPTION_COUNT) {
    RETURN_TRUE;
  }

  RETURN_FALSE;
}

static void freeLocaleOptionsObj(zend_object *object) {
  ecma_IntlLocaleOptions *intlLocaleOptions =
      ecma_IntlLocaleOptionsFromObj(object);
  zend_object_std_dtor(&intlLocaleOptions->std);
}

static const char *getPropertyNameForEnum(ecma_localeOption option) {
  if (option == CALENDAR) {
    return "calendar";
  } else if (option == CASE_FIRST) {
    return "caseFirst";
  } else if (option == COLLATION) {
    return "collation";
  } else if (option == HOUR_CYCLE) {
    return "hourCycle";
  } else if (option == LANGUAGE) {
    return "language";
  } else if (option == NUMBERING_SYSTEM) {
    return "numberingSystem";
  } else if (option == NUMERIC) {
    return "numeric";
  } else if (option == REGION) {
    return "region";
  } else if (option == SCRIPT) {
    return "script";
  }

  return NULL;
}

static bool isCaseFirst(const char *value) {
  return strcmp(value, "upper") == 0 || strcmp(value, "lower") == 0 ||
         strcmp(value, "false") == 0;
}

static bool isHourCycle(const char *value) {
  return strcmp(value, "h11") == 0 || strcmp(value, "h12") == 0 ||
         strcmp(value, "h23") == 0 || strcmp(value, "h24") == 0;
}

static bool isValidCaseFirstParam(zval *param) {
  if (param == NULL || isFalse(param) || isString(param) ||
      isStringable(param)) {
    return true;
  }

  const char *type;
  if (Z_TYPE_P(param) == IS_TRUE) {
    type = "true";
  } else {
    type = zend_zval_type_name(param);
  }

  zend_argument_type_error(
      2, "must be of type Stringable|string|false|null, %s given", type);

  return false;
}

static void setCalendar(zend_object *object, zend_string *paramStr,
                        zend_object *paramObj) {
  if (!setProperty("calendar", object, paramStr, paramObj,
                   ecma402_isUnicodeLocaleIdentifierType)) {
    zend_value_error("calendar is not a well-formed calendar value");
  }
}

static void setCaseFirst(zend_object *object, zval *param) {
  bool success = false;

  if (param == NULL) {
    success = setProperty("caseFirst", object, NULL, NULL, NULL);
  } else if (isFalse(param)) {
    zend_string *tmp = zend_string_init("false", 5, false);
    success = setProperty("caseFirst", object, tmp, NULL, isCaseFirst);
    zend_string_free(tmp);
  } else if (isString(param)) {
    success =
        setProperty("caseFirst", object, Z_STR_P(param), NULL, isCaseFirst);
  } else if (isStringable(param)) {
    success =
        setProperty("caseFirst", object, NULL, Z_OBJ_P(param), isCaseFirst);
  }

  if (!success) {
    zend_value_error(
        "caseFirst must be either \"upper\", \"lower\", or \"false\"");
  }
}

static void setCollation(zend_object *object, zend_string *paramStr,
                         zend_object *paramObj) {
  if (!setProperty("collation", object, paramStr, paramObj,
                   ecma402_isUnicodeLocaleIdentifierType)) {
    zend_value_error("collation is not a well-formed collation value");
  }
}

static void setHourCycle(zend_object *object, zend_string *paramStr,
                         zend_object *paramObj) {
  if (!setProperty("hourCycle", object, paramStr, paramObj, isHourCycle)) {
    zend_value_error("hourCycle must be \"h11\", \"h12\", \"h23\", or \"h24\"");
  }
}

static void setLanguage(zend_object *object, zend_string *paramStr,
                        zend_object *paramObj) {
  if (!setProperty("language", object, paramStr, paramObj,
                   ecma402_isUnicodeLanguageSubtag)) {
    zend_value_error("language is not a well-formed language value");
  }
}

static void setNumberingSystem(zend_object *object, zend_string *paramStr,
                               zend_object *paramObj) {
  if (!setProperty("numberingSystem", object, paramStr, paramObj,
                   ecma402_isUnicodeLocaleIdentifierType)) {
    zend_value_error(
        "numberingSystem is not a well-formed numbering system value");
  }
}

static void setNumeric(zend_object *object, bool numeric, bool isNumericNull) {
  const char *name = "numeric";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (isNumericNull) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  zend_update_property_bool(ce, object, name, length, numeric);
}

static bool setProperty(const char *name, zend_object *object,
                        zend_string *valueStr, zend_object *valueObj,
                        bool (*validator)(const char *)) {
  const char *value;
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;
  zval tmp;
  bool destroyTmp = false;

  if (valueStr == NULL && valueObj == NULL) {
    zend_update_property_null(ce, object, name, length);

    return true;
  }

  if (valueStr != NULL) {
    value = ZSTR_VAL(valueStr);
  } else {
    zend_std_cast_object_tostring(valueObj, &tmp, IS_STRING);

    if (EG(exception)) {
      // We return true in order to bubble-up the exception thrown when casting
      // the object to a string. If we returned false, the calling code would
      // assume property validation failed and throw a ValueError instead.
      return true;
    }

    value = Z_STRVAL(tmp);
    destroyTmp = true;
  }

  if (validator(value)) {
    zend_update_property_string(ce, object, name, length, value);

    if (destroyTmp) {
      zval_ptr_dtor(&tmp);
    }

    return true;
  }

  if (destroyTmp) {
    zval_ptr_dtor(&tmp);
  }

  return false;
}

static void setRegion(zend_object *object, zend_string *paramStr,
                      zend_object *paramObj) {
  if (!setProperty("region", object, paramStr, paramObj,
                   ecma402_isUnicodeRegionSubtag)) {
    zend_value_error("region is not a well-formed region value");
  }
}

static void setScript(zend_object *object, zend_string *paramStr,
                      zend_object *paramObj) {
  if (!setProperty("script", object, paramStr, paramObj,
                   ecma402_isUnicodeScriptSubtag)) {
    zend_value_error("script is not a well-formed script value");
  }
}
