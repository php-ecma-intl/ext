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
                           sizeof(#property) - 1, true, NULL);                 \
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
static void setCalendar(zend_object *object, zend_string *calendar);
static void setCaseFirst(zend_object *object, zend_string *caseFirst);
static void setCollation(zend_object *object, zend_string *collation);
static void setHourCycle(zend_object *object, zend_string *hourCycle);
static void setLanguage(zend_object *object, zend_string *language);
static void setNumberingSystem(zend_object *object,
                               zend_string *numberingSystem);
static void setNumeric(zend_object *object, bool numeric, bool isNumericNull);
static void setRegion(zend_object *object, zend_string *region);
static void setScript(zend_object *object, zend_string *script);

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
  zend_string *calendar = NULL, *caseFirst = NULL, *collation = NULL,
              *hourCycle = NULL, *language = NULL, *numberingSystem = NULL,
              *region = NULL, *script = NULL;
  bool numeric = false, isNumericNull = true;
  ecma_IntlLocaleOptions *intlLocaleOptions;
  zend_object *object;

  ZEND_PARSE_PARAMETERS_START(0, 9)
  Z_PARAM_OPTIONAL
  Z_PARAM_STR_OR_NULL(calendar)
  Z_PARAM_STR_OR_NULL(caseFirst)
  Z_PARAM_STR_OR_NULL(collation)
  Z_PARAM_STR_OR_NULL(hourCycle)
  Z_PARAM_STR_OR_NULL(language)
  Z_PARAM_STR_OR_NULL(numberingSystem)
  Z_PARAM_BOOL_OR_NULL(numeric, isNumericNull)
  Z_PARAM_STR_OR_NULL(region)
  Z_PARAM_STR_OR_NULL(script)
  ZEND_PARSE_PARAMETERS_END();

  intlLocaleOptions = ECMA_LOCALE_OPTIONS_P(getThis());
  object = &intlLocaleOptions->std;

  if (calendar != NULL || caseFirst != NULL || collation != NULL ||
      hourCycle != NULL || language != NULL || numberingSystem != NULL ||
      !isNumericNull || region != NULL || script != NULL) {
    // We know not all values are null, so set this for future reference.
    intlLocaleOptions->allNull = false;
  }

  setCalendar(object, calendar);
  setCaseFirst(object, caseFirst);
  setCollation(object, collation);
  setHourCycle(object, hourCycle);
  setLanguage(object, language);
  setNumberingSystem(object, numberingSystem);
  setNumeric(object, numeric, isNumericNull);
  setRegion(object, region);
  setScript(object, script);
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

static void setCalendar(zend_object *object, zend_string *calendar) {
  const char *name = "calendar";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (calendar == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (ecma402_isUnicodeLocaleIdentifierType(ZSTR_VAL(calendar))) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(calendar));
    return;
  }

  zend_value_error("calendar is not a well-formed calendar value");
}

static void setCaseFirst(zend_object *object, zend_string *caseFirst) {
  const char *name = "caseFirst";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (caseFirst == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (strcmp(ZSTR_VAL(caseFirst), "upper") == 0 ||
      strcmp(ZSTR_VAL(caseFirst), "lower") == 0 ||
      strcmp(ZSTR_VAL(caseFirst), "false") == 0) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(caseFirst));
    return;
  }

  zend_value_error(
      "caseFirst must be either \"upper\", \"lower\", or \"false\"");
}

static void setCollation(zend_object *object, zend_string *collation) {
  const char *name = "collation";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (collation == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (ecma402_isUnicodeLocaleIdentifierType(ZSTR_VAL(collation))) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(collation));
    return;
  }

  zend_value_error("collation is not a well-formed collation value");
}

static void setHourCycle(zend_object *object, zend_string *hourCycle) {
  const char *name = "hourCycle";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (hourCycle == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (strcmp(ZSTR_VAL(hourCycle), "h11") == 0 ||
      strcmp(ZSTR_VAL(hourCycle), "h12") == 0 ||
      strcmp(ZSTR_VAL(hourCycle), "h23") == 0 ||
      strcmp(ZSTR_VAL(hourCycle), "h24") == 0) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(hourCycle));
    return;
  }

  zend_value_error("hourCycle must be \"h11\", \"h12\", \"h23\", or \"h24\"");
}

static void setLanguage(zend_object *object, zend_string *language) {
  const char *name = "language";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (language == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (ecma402_isUnicodeLanguageSubtag(ZSTR_VAL(language))) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(language));
    return;
  }

  zend_value_error("language is not a well-formed language value");
}

static void setNumberingSystem(zend_object *object,
                               zend_string *numberingSystem) {
  const char *name = "numberingSystem";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (numberingSystem == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (ecma402_isUnicodeLocaleIdentifierType(ZSTR_VAL(numberingSystem))) {
    zend_update_property_string(ce, object, name, length,
                                ZSTR_VAL(numberingSystem));
    return;
  }

  zend_value_error(
      "numberingSystem is not a well-formed numbering system value");
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

static void setRegion(zend_object *object, zend_string *region) {
  const char *name = "region";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (region == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (ecma402_isUnicodeRegionSubtag(ZSTR_VAL(region))) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(region));
    return;
  }

  zend_value_error("region is not a well-formed region value");
}

static void setScript(zend_object *object, zend_string *script) {
  const char *name = "script";
  const size_t length = strlen(name);
  zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

  if (script == NULL) {
    zend_update_property_null(ce, object, name, length);
    return;
  }

  if (ecma402_isUnicodeScriptSubtag(ZSTR_VAL(script))) {
    zend_update_property_string(ce, object, name, length, ZSTR_VAL(script));
    return;
  }

  zend_value_error("script is not a well-formed script value");
}
