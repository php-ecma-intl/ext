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

#include "php/classes/supported_locales_options.h"

#include "php/classes/supported_locales_options_arginfo.h"

#include <ext/json/php_json.h>
#include <Zend/zend_interfaces.h>

zend_class_entry *ecma_ce_IntlSupportedLocalesOptions = NULL;

static bool isLocaleMatcherAlgorithm(const char *value);
static void setLocaleMatcher(zend_object *object, zend_string *paramStr, zend_object *paramObj);

PHP_MINIT_FUNCTION(ecma_intl_supported_locales_options)
{
	ecma_ce_IntlSupportedLocalesOptions =
		register_class_Ecma_Intl_SupportedLocales_Options(zend_ce_iterator, php_json_serializable_ce);
	ecma_ce_IntlSupportedLocalesOptions->create_object = ecma_createIntlOptions;
#if PHP_VERSION_ID >= 80300
	ecma_ce_IntlSupportedLocalesOptions->default_object_handlers = &ecma_handlers_IntlOptions;
#endif

	memcpy(&ecma_handlers_IntlOptions, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	ecma_handlers_IntlOptions.offset = XtOffsetOf(ecma_IntlOptions, std);
	ecma_handlers_IntlOptions.free_obj = ecma_freeIntlOptionsObj;

	return SUCCESS;
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, __construct)
{
	zend_string *localeMatcher = NULL;
	zend_object *localeMatcherObj = NULL;
	ecma_IntlOptions *intlOptions;
	zend_object *this;
	zend_class_entry *stringable = zend_ce_stringable;

	ZEND_PARSE_PARAMETERS_START(0, 1)
	Z_PARAM_OPTIONAL
	Z_PARAM_OBJ_OF_CLASS_OR_STR_OR_NULL(localeMatcherObj, stringable, localeMatcher)
	ZEND_PARSE_PARAMETERS_END();

	intlOptions = ECMA_OPTIONS_P(getThis());
	this = &intlOptions->std;

	setLocaleMatcher(this, localeMatcher, localeMatcherObj);
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, jsonSerialize)
{
	ZEND_PARSE_PARAMETERS_NONE();
	serializeObjectProperties(return_value, getThis(), false);
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, current)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_getCurrentOptionValue(return_value, getThis(), false);
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, key)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_getCurrentOptionKey(return_value, getThis(), false);
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, next)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_nextOption(getThis(), false);
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, rewind)
{
	ZEND_PARSE_PARAMETERS_NONE();
	ecma_rewindOptions(getThis());
}

PHP_METHOD(Ecma_Intl_SupportedLocales_Options, valid)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if (!ecma_endOfOptions(getThis(), false)) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

static bool isLocaleMatcherAlgorithm(const char *value)
{
	return strcmp(value, "lookup") == 0 || strcmp(value, "best fit") == 0;
}

static void setLocaleMatcher(zend_object *object, zend_string *paramStr, zend_object *paramObj)
{
	if (!setStringPropertyFromStringOrStringable(ecma_ce_IntlSupportedLocalesOptions, object, "localeMatcher", paramStr,
	                                             paramObj, isLocaleMatcherAlgorithm)) {
		zend_value_error("localeMatcher must be either \"lookup\" or \"best fit\"");
	}
}
