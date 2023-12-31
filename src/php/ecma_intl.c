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

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "php/ecma_intl.h"

#include "ecma402/error.h"
#include "ecma402/locale.h"
#include "php/classes/category.h"
#include "php/classes/collator.h"
#include "php/classes/intl.h"
#include "php/classes/locale.h"
#include "php/classes/locale_character_direction.h"
#include "php/classes/locale_options.h"
#include "php/classes/locale_text_info.h"
#include "php/classes/locale_week_day.h"
#include "php/classes/locale_week_info.h"
#include "php/classes/supported_locales_options.h"

#include <ext/standard/info.h>
#include <php_ini.h>
#include <string.h>
#include <unicode/ucal.h>

static ZEND_INI_MH(onUpdateLocale);

PHP_INI_BEGIN()
PHP_INI_ENTRY(PHP_ECMA_INI_DEFAULT_LOCALE, "", PHP_INI_ALL, onUpdateLocale)
PHP_INI_END()

zend_module_entry ecma_intl_module_entry = {STANDARD_MODULE_HEADER,
                                            "ecma_intl",
                                            NULL,
                                            PHP_MINIT(ecma_intl_all),
                                            PHP_MSHUTDOWN(ecma_intl),
                                            PHP_RINIT(ecma_intl),
                                            NULL,
                                            PHP_MINFO(ecma_intl),
                                            PHP_ECMA_INTL_VERSION,
                                            STANDARD_MODULE_PROPERTIES};

#ifdef COMPILE_DL_ECMA_INTL
#	ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#	endif
ZEND_GET_MODULE(ecma_intl)
#endif

PHP_MINIT_FUNCTION(ecma_intl_all)
{
	REGISTER_INI_ENTRIES();

	PHP_MINIT(ecma_intl)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_category)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_collator)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_locale)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_locale_character_direction)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_locale_options)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_locale_textinfo)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_locale_weekday)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_locale_weekinfo)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(ecma_intl_supported_locales_options)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(ecma_intl)
{
	UNREGISTER_INI_ENTRIES();

	return SUCCESS;
}

PHP_RINIT_FUNCTION(ecma_intl)
{
#if defined(ZTS) && defined(COMPILE_DL_ECMA_INTL)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}

PHP_MINFO_FUNCTION(ecma_intl)
{
	UErrorCode status = U_ZERO_ERROR;
	const char *timeZoneDataVersion = NULL;

	timeZoneDataVersion = ucal_getTZDataVersion(&status);
	if (U_FAILURE(status)) {
		timeZoneDataVersion = "n/a";
	}

	php_info_print_table_start();
	php_info_print_table_header(2, "Internationalization Support, Ecma-style (ECMA-402)", "enabled");
	php_info_print_table_row(2, "ecma_intl version", PHP_ECMA_INTL_VERSION);
	php_info_print_table_row(2, "ICU version", U_ICU_VERSION);
	php_info_print_table_row(2, "ICU Data version", U_ICU_DATA_VERSION);
	php_info_print_table_row(2, "ICU TZData version", timeZoneDataVersion);
	php_info_print_table_row(2, "ICU Unicode version", U_UNICODE_VERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

char *ecma_defaultLocale()
{
	char *ini, *defaultLocale;
	const char *icu;
	size_t length;
	ecma402_errorStatus *status;

	ini = INI_STR(PHP_ECMA_INI_DEFAULT_LOCALE);

	if (ini != NULL && strlen(ini) > 0) {
		status = ecma402_initErrorStatus();
		defaultLocale = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);

		length = ecma402_validateAndCanonicalizeUnicodeLocaleId(ini, defaultLocale, status);

		if (!ecma402_hasError(status) && length > 0) {
			ecma402_freeErrorStatus(status);

			return defaultLocale;
		}

		efree(defaultLocale);
		ecma402_freeErrorStatus(status);
	}

	// Fall back to ICU default, if we don't have a default locale set.
	icu = uloc_getDefault();
	if (icu != NULL && strlen(icu) > 0) {
		status = ecma402_initErrorStatus();
		defaultLocale = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);

		length = ecma402_validateAndCanonicalizeUnicodeLocaleId(icu, defaultLocale, status);

		if (!ecma402_hasError(status) && length > 0) {
			ecma402_freeErrorStatus(status);

			return defaultLocale;
		}

		efree(defaultLocale);
		ecma402_freeErrorStatus(status);
	}

	// If all else fails, use "en" as the default locale. This isn't perfect,
	// but it ensures we have at least something.
	return estrdup(PHP_ECMA_FALLBACK_LOCALE);
}

static ZEND_INI_MH(onUpdateLocale)
{
	char *canonicalized;
	int length;
	ecma402_errorStatus *status;
	zend_result result = FAILURE;

	if (new_value && strcmp(ZSTR_VAL(new_value), "") == 0) {
		return SUCCESS;
	}

	if (!new_value || !ZSTR_VAL(new_value)[0]) {
		return result;
	}

	status = ecma402_initErrorStatus();
	canonicalized = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);

	length = ecma402_validateAndCanonicalizeUnicodeLocaleId(ZSTR_VAL(new_value), canonicalized, status);

	if (!ecma402_hasError(status) && length > 0) {
		result = SUCCESS;
	}

	efree(canonicalized);
	ecma402_freeErrorStatus(status);

	return result;
}
