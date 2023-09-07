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

#include "php/classes/locale_options_arginfo.h"

#include "ecma402/language_tag.h"

#include <ext/json/php_json.h>
#include <Zend/zend_interfaces.h>

zend_class_entry *ecma_ce_IntlLocaleOptions = NULL;

static bool isCaseFirst(const char *value);
static bool isHourCycle(const char *value);
static bool isValidCaseFirstParam(zval *param);
static void setCalendar(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setCaseFirst(zend_object *object, zval *param);
static void setCollation(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setCurrency(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setHourCycle(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setLanguage(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setNumberingSystem(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setNumeric(zend_object *object, bool numeric, bool isNumericNull);
static bool setProperty(const char *name, zend_object *object, zend_string *valueStr, zend_object *valueObj,
                        bool (*validator)(const char *));
static void setRegion(zend_object *object, zend_string *paramStr, zend_object *paramObj);
static void setScript(zend_object *object, zend_string *paramStr, zend_object *paramObj);

PHP_MINIT_FUNCTION(ecma_intl_locale_options)
{
	ecma_ce_IntlLocaleOptions = register_class_Ecma_Intl_Locale_Options(zend_ce_iterator, php_json_serializable_ce);
	ecma_ce_IntlLocaleOptions->create_object = ecma_createIntlOptions;
#if PHP_VERSION_ID >= 80300
	ecma_ce_IntlLocaleOptions->default_object_handlers = &ecma_handlers_IntlOptions;
#endif

	memcpy(&ecma_handlers_IntlOptions, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	ecma_handlers_IntlOptions.offset = XtOffsetOf(ecma_IntlOptions, std);
	ecma_handlers_IntlOptions.free_obj = ecma_freeIntlOptionsObj;

	return SUCCESS;
}

PHP_METHOD(Ecma_Intl_Locale_Options, __construct)
{
	zend_string *calendar = NULL, *collation = NULL, *currency = NULL, *hourCycle = NULL, *language = NULL,
				*numberingSystem = NULL, *region = NULL, *script = NULL;
	zend_object *calendarObj = NULL, *collationObj = NULL, *currencyObj = NULL, *hourCycleObj = NULL,
				*languageObj = NULL, *numberingSystemObj = NULL, *regionObj = NULL, *scriptObj = NULL;
	zval *caseFirst = NULL;
	bool numeric = false, isNumericNull = true;
	ecma_IntlOptions *intlOptions;
	zend_object *object;
	zend_class_entry *stringable = zend_ce_stringable;

	ZEND_PARSE_PARAMETERS_START(0, 10)
	Z_PARAM_OPTIONAL
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(calendarObj, stringable, calendar)
	Z_PARAM_ZVAL_OR_NULL(caseFirst)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(collationObj, stringable, collation)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(currencyObj, stringable, currency)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(hourCycleObj, stringable, hourCycle)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(languageObj, stringable, language)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(numberingSystemObj, stringable, numberingSystem)
	Z_PARAM_BOOL_OR_NULL(numeric, isNumericNull)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(regionObj, stringable, region)
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(scriptObj, stringable, script)
	ZEND_PARSE_PARAMETERS_END();

	if (caseFirst != NULL && !isValidCaseFirstParam(caseFirst)) {
		RETURN_THROWS();
	}

	intlOptions = ECMA_OPTIONS_P(getThis());
	object = &intlOptions->std;

	setCalendar(object, calendar, calendarObj);
	setCaseFirst(object, caseFirst);
	setCollation(object, collation, collationObj);
	setCurrency(object, currency, currencyObj);
	setHourCycle(object, hourCycle, hourCycleObj);
	setLanguage(object, language, languageObj);
	setNumberingSystem(object, numberingSystem, numberingSystemObj);
	setNumeric(object, numeric, isNumericNull);
	setRegion(object, region, regionObj);
	setScript(object, script, scriptObj);
}

PHP_METHOD(Ecma_Intl_Locale_Options, jsonSerialize)
{
	ZEND_PARSE_PARAMETERS_NONE();
	serializeObjectProperties(return_value, getThis(), false);
}

PHP_METHOD(Ecma_Intl_Locale_Options, current)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_getCurrentOptionValue(return_value, getThis(), false);
}

PHP_METHOD(Ecma_Intl_Locale_Options, key)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_getCurrentOptionKey(return_value, getThis(), false);
}

PHP_METHOD(Ecma_Intl_Locale_Options, next)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_nextOption(getThis(), false);
}

PHP_METHOD(Ecma_Intl_Locale_Options, rewind)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_rewindOptions(getThis());
}

PHP_METHOD(Ecma_Intl_Locale_Options, valid)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if (!ecma_endOfOptions(getThis(), false)) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

static bool isCaseFirst(const char *value)
{
	return strcmp(value, "upper") == 0 || strcmp(value, "lower") == 0 || strcmp(value, "false") == 0;
}

static bool isHourCycle(const char *value)
{
	return strcmp(value, "h11") == 0 || strcmp(value, "h12") == 0 || strcmp(value, "h23") == 0 ||
	       strcmp(value, "h24") == 0;
}

static bool isValidCaseFirstParam(zval *param)
{
	if (param == NULL || isFalse(param) || isString(param) || isStringable(param)) {
		return true;
	}

	const char *type;
	if (Z_TYPE_P(param) == IS_TRUE) {
		type = "true";
	} else {
		type = zend_zval_type_name(param);
	}

	zend_argument_type_error(2, "must be of type Stringable|string|false|null, %s given", type);

	return false;
}

static void setCalendar(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("calendar", object, paramStr, paramObj, ecma402_isUnicodeLocaleIdentifierType)) {
		zend_value_error("calendar is not a well-formed calendar value");
	}
}

static void setCaseFirst(zend_object *object, zval *param)
{
	bool success = false;

	if (param == NULL) {
		success = setProperty("caseFirst", object, NULL, NULL, NULL);
	} else if (isFalse(param)) {
		zend_string *tmp = zend_string_init("false", 5, false);
		success = setProperty("caseFirst", object, tmp, NULL, isCaseFirst);
		zend_string_free(tmp);
	} else if (isString(param)) {
		success = setProperty("caseFirst", object, Z_STR_P(param), NULL, isCaseFirst);
	} else if (isStringable(param)) {
		success = setProperty("caseFirst", object, NULL, Z_OBJ_P(param), isCaseFirst);
	}

	if (!success) {
		zend_value_error("caseFirst must be either \"upper\", \"lower\", or \"false\"");
	}
}

static void setCollation(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("collation", object, paramStr, paramObj, ecma402_isUnicodeLocaleIdentifierType)) {
		zend_value_error("collation is not a well-formed collation value");
	}
}

static void setCurrency(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("currency", object, paramStr, paramObj, ecma402_isUnicodeCurrencyType)) {
		zend_value_error("currency is not a well-formed currency value");
	}
}

static void setHourCycle(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("hourCycle", object, paramStr, paramObj, isHourCycle)) {
		zend_value_error("hourCycle must be \"h11\", \"h12\", \"h23\", or \"h24\"");
	}
}

static void setLanguage(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("language", object, paramStr, paramObj, ecma402_isUnicodeLanguageSubtag)) {
		zend_value_error("language is not a well-formed language value");
	}
}

static void setNumberingSystem(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("numberingSystem", object, paramStr, paramObj, ecma402_isUnicodeLocaleIdentifierType)) {
		zend_value_error("numberingSystem is not a well-formed numbering system value");
	}
}

static void setNumeric(zend_object *object, bool numeric, bool isNumericNull)
{
	const char *name = "numeric";
	const size_t length = strlen(name);
	zend_class_entry *ce = ecma_ce_IntlLocaleOptions;

	if (isNumericNull) {
		zend_update_property_null(ce, object, name, length);
		return;
	}

	zend_update_property_bool(ce, object, name, length, numeric);
}

static bool setProperty(const char *name, zend_object *object, zend_string *valueStr, zend_object *valueObj,
                        bool (*validator)(const char *))
{
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

static void setRegion(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("region", object, paramStr, paramObj, ecma402_isUnicodeRegionSubtag)) {
		zend_value_error("region is not a well-formed region value");
	}
}

static void setScript(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setProperty("script", object, paramStr, paramObj, ecma402_isUnicodeScriptSubtag)) {
		zend_value_error("script is not a well-formed script value");
	}
}
