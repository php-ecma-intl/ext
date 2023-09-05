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

#include "php/classes/supportedlocalesoptions.h"

#include "php/classes/supportedlocalesoptions_arginfo.h"

#include <Zend/zend_interfaces.h>
#include <ext/json/php_json.h>

zend_class_entry *ecma_ce_IntlSupportedLocalesOptions = NULL;
zend_object_handlers ecma_handlers_IntlSupportedLocalesOptions;

static void freeSupportedLocalesOptionsObj(zend_object *object);
static const char *getPropertyNameForEnum(ecma_supportedLocalesOption option);
static bool isLocaleMatcherAlgorithm(const char *value);
static void setLocaleMatcher(zend_object *object, zend_string *paramStr,
                             zend_object *paramObj);
static bool setProperty(const char *name, zend_object *object,
                        zend_string *valueStr, zend_object *valueObj,
                        bool (*validator)(const char *));

PHP_MINIT_FUNCTION(ecma_intl_supportedlocalesoptions) {
  ecma_ce_IntlSupportedLocalesOptions =
      register_class_Ecma_Intl_SupportedLocalesOptions(
          zend_ce_iterator, php_json_serializable_ce);
  ecma_ce_IntlSupportedLocalesOptions->create_object =
      ecma_createIntlSupportedLocalesOptions;

  memcpy(&ecma_handlers_IntlSupportedLocalesOptions,
         zend_get_std_object_handlers(), sizeof(zend_object_handlers));

  ecma_handlers_IntlSupportedLocalesOptions.offset =
      XtOffsetOf(ecma_IntlSupportedLocalesOptions, std);
  ecma_handlers_IntlSupportedLocalesOptions.free_obj =
      freeSupportedLocalesOptionsObj;

  return SUCCESS;
}

zend_object *
ecma_createIntlSupportedLocalesOptions(zend_class_entry *classEntry) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;

  intlSupportedLocalesOptions = zend_object_alloc(
      sizeof(struct ecma_IntlSupportedLocalesOptions), classEntry);

  zend_object_std_init(&intlSupportedLocalesOptions->std, classEntry);
  object_properties_init(&intlSupportedLocalesOptions->std, classEntry);

  intlSupportedLocalesOptions->std.handlers =
      &ecma_handlers_IntlSupportedLocalesOptions;
  intlSupportedLocalesOptions->allNull = true;
  intlSupportedLocalesOptions->iteratorCurrent = LOCALE_MATCHER;

  return &intlSupportedLocalesOptions->std;
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, __construct) {
  zend_string *localeMatcher = NULL;
  zend_object *localeMatcherObj = NULL;
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;
  zend_object *this;
  zend_class_entry *stringable = zend_ce_stringable;

  ZEND_PARSE_PARAMETERS_START(0, 1)
  Z_PARAM_OPTIONAL
  Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(localeMatcherObj, stringable,
                                      localeMatcher)
  ZEND_PARSE_PARAMETERS_END();

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());
  this = &intlSupportedLocalesOptions->std;

  intlSupportedLocalesOptions->allNull = (localeMatcher == NULL);

  setLocaleMatcher(this, localeMatcher, localeMatcherObj);
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, jsonSerialize) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;
  zend_object *this;
  zval localeMatcher, rv;

  ZEND_PARSE_PARAMETERS_NONE();

  object_init(return_value);

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());
  this = &intlSupportedLocalesOptions->std;

  localeMatcher =
      *zend_read_property(ecma_ce_IntlSupportedLocalesOptions, this,
                          "localeMatcher", strlen("localeMatcher"), false, &rv);

  if (Z_TYPE(localeMatcher) != IS_NULL) {
    add_property_zval(return_value, "localeMatcher", &localeMatcher);
  }
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, current) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;
  zend_object *object;
  zval *value;

  ZEND_PARSE_PARAMETERS_NONE();

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());
  object = &intlSupportedLocalesOptions->std;

  // Advance to the first non-null value and return it. We want to allow
  // unpacking this object in an array, but we don't want null elements in the
  // unpacked array.
  do {
    const char *name =
        getPropertyNameForEnum(intlSupportedLocalesOptions->iteratorCurrent);
    value = zend_read_property(ecma_ce_IntlSupportedLocalesOptions, object,
                               name, strlen(name), true, NULL);

    if (!ZVAL_IS_NULL(value)) {
      break;
    }

    intlSupportedLocalesOptions->iteratorCurrent++;

  } while (intlSupportedLocalesOptions->iteratorCurrent <=
           ECMA_SUPPORTED_LOCALES_OPTION_COUNT);

  if (Z_TYPE_P(value) == IS_STRING) {
    RETURN_STRING(Z_STRVAL_P(value));
  }
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, key) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;

  ZEND_PARSE_PARAMETERS_NONE();

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());

  RETURN_STRING(
      getPropertyNameForEnum(intlSupportedLocalesOptions->iteratorCurrent));
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, next) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;
  zend_object *object;
  zval *value;

  ZEND_PARSE_PARAMETERS_NONE();

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());
  object = &intlSupportedLocalesOptions->std;

  // Advance to the next non-null value. We want to allow unpacking this object
  // in an array, but we don't want null elements in the unpacked array.
  do {
    intlSupportedLocalesOptions->iteratorCurrent++;

    const char *name =
        getPropertyNameForEnum(intlSupportedLocalesOptions->iteratorCurrent);

    if (name == NULL) {
      break;
    }

    value = zend_read_property(ecma_ce_IntlSupportedLocalesOptions, object,
                               name, strlen(name), true, NULL);

  } while (intlSupportedLocalesOptions->iteratorCurrent <=
               ECMA_SUPPORTED_LOCALES_OPTION_COUNT &&
           ZVAL_IS_NULL(value));
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, rewind) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;

  ZEND_PARSE_PARAMETERS_NONE();

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());
  intlSupportedLocalesOptions->iteratorCurrent = LOCALE_MATCHER;
}

PHP_METHOD(Ecma_Intl_SupportedLocalesOptions, valid) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions;

  ZEND_PARSE_PARAMETERS_NONE();

  intlSupportedLocalesOptions = ECMA_SUPPORTED_LOCALES_OPTIONS_P(getThis());

  if (intlSupportedLocalesOptions->allNull) {
    RETURN_FALSE;
  }

  if (intlSupportedLocalesOptions->iteratorCurrent <=
      ECMA_SUPPORTED_LOCALES_OPTION_COUNT) {
    RETURN_TRUE;
  }

  RETURN_FALSE;
}

static void freeSupportedLocalesOptionsObj(zend_object *object) {
  ecma_IntlSupportedLocalesOptions *intlSupportedLocalesOptions =
      ecma_IntlSupportedLocalesOptionsFromObj(object);
  zend_object_std_dtor(&intlSupportedLocalesOptions->std);
}

static const char *getPropertyNameForEnum(ecma_supportedLocalesOption option) {
  if (option == LOCALE_MATCHER) {
    return "localeMatcher";
  }

  return NULL;
}

static bool isLocaleMatcherAlgorithm(const char *value) {
  return strcmp(value, "lookup") == 0 || strcmp(value, "best fit") == 0;
}

static void setLocaleMatcher(zend_object *object, zend_string *paramStr,
                             zend_object *paramObj) {
  if (!setProperty("localeMatcher", object, paramStr, paramObj,
                   isLocaleMatcherAlgorithm)) {
    zend_value_error("localeMatcher must be either \"lookup\" or \"best fit\"");
  }
}

static bool setProperty(const char *name, zend_object *object,
                        zend_string *valueStr, zend_object *valueObj,
                        bool (*validator)(const char *)) {
  return setStringPropertyFromStringOrStringable(
      ecma_ce_IntlSupportedLocalesOptions, object, name, valueStr, valueObj,
      validator);
}
