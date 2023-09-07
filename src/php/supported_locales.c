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

#include "php/supported_locales.h"

#include "ecma402/locale.h"
#include "php/classes/supported_locales_options.h"

#include <ext/spl/spl_iterators.h>
#include <unicode/uloc.h>

int ecma_bestFitSupportedLocales(zval *rv, char **availableLocales, int availableLocalesLength, char **requestedLocales,
                                 int requestedLocalesLength)
{
	return ecma_lookupSupportedLocales(rv, availableLocales, availableLocalesLength, requestedLocales,
	                                   requestedLocalesLength);
}

int ecma_lookupSupportedLocales(zval *rv, char **availableLocales, int availableLocalesLength, char **requestedLocales,
                                int requestedLocalesLength)
{
	int i, added = 0;

	for (i = 0; i < requestedLocalesLength; i++) {
		char *bestAvailable = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
		if (ecma402_bestAvailableLocale(availableLocales, availableLocalesLength, requestedLocales[i], bestAvailable,
		                                true) > 0) {
			add_next_index_string(rv, requestedLocales[i]);
			added++;
		}
		efree(bestAvailable);
	}

	return added;
}

void ecma_supportedLocalesOf(zend_execute_data *execute_data, zval *return_value)
{
	zval *localesArg, *loopItem;
	HashTable *localesHt;
	const char **locales;
	char **canonicalized, **availableLocales;
	int canonicalizedLength, availableLocalesLength, localesLength = 0;
	ecma402_errorStatus *errorStatus;
	zend_object *options = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 2)
	Z_PARAM_ZVAL(localesArg)
	Z_PARAM_OPTIONAL
	Z_PARAM_OBJ_OF_CLASS_OR_NULL(options, ecma_ce_IntlSupportedLocalesOptions)
	ZEND_PARSE_PARAMETERS_END();

	if (!isString(localesArg) && !isNull(localesArg) && !isStringable(localesArg) && !isIterable(localesArg)) {
		zend_argument_type_error(1,
		                         "must be of type iterable<Stringable|string>|Stringable|string|null, "
		                         "%s given",
		                         zend_zval_type_name(localesArg));
		RETURN_THROWS();
	}

	array_init(return_value);

	if (EXPECTED(Z_TYPE_P(localesArg) == IS_NULL)) {
		return;
	}

	ALLOC_HASHTABLE(localesHt);
	zend_hash_init(localesHt, 0, NULL, ZVAL_PTR_DTOR, 0);

	if (isString(localesArg)) {
		zval localeString;
		ZVAL_STR_COPY(&localeString, Z_STR_P(localesArg));
		zend_hash_next_index_insert(localesHt, &localeString);
	} else if (isStringable(localesArg)) {
		zval localeString;
		zend_std_cast_object_tostring(Z_OBJ_P(localesArg), &localeString, IS_STRING);
		zend_hash_next_index_insert(localesHt, &localeString);
	} else if (isArray(localesArg)) {
		zend_hash_copy(localesHt, Z_ARRVAL_P(localesArg), (copy_ctor_func_t)zval_add_ref);
	} else {
		spl_iterator_apply(localesArg, iteratorToHashTable, (void *)localesHt);
	}

	locales = (const char **)emalloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);

	ZEND_HASH_FOREACH_VAL(localesHt, loopItem)

	if (isString(loopItem)) {
		locales[localesLength] = Z_STRVAL_P(loopItem);
		localesLength++;
	} else if (isStringable(loopItem)) {
		zval localeString;
		zend_std_cast_object_tostring(Z_OBJ_P(loopItem), &localeString, IS_STRING);
		locales[localesLength] = Z_STRVAL(localeString);
		localesLength++;
	} else {
		zend_string *method = get_active_function_or_method_name();
		zend_type_error("%s(): Argument #1 ($%s) must be of type "
		                "iterable<Stringable|string>|Stringable|string|null, %s given in iterable",
		                ZSTR_VAL(method), get_active_function_arg_name(1), zend_zval_type_name(loopItem));
		zend_string_free(method);
	}

	ZEND_HASH_FOREACH_END();

	errorStatus = ecma402_initErrorStatus();

	if (locales) {
		canonicalized = (char **)emalloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);
		canonicalizedLength = ecma402_canonicalizeLocaleList(locales, localesLength, canonicalized, errorStatus);

		if (ecma402_hasError(errorStatus)) {
			zend_value_error("%s", errorStatus->errorMessage);
		} else {
			availableLocales = (char **)emalloc(sizeof(char *) * uloc_countAvailable());
			availableLocalesLength = ecma402_intlAvailableLocales(availableLocales);

			const char *localeMatcher =
				ecma_getOptionString(ecma_ce_IntlSupportedLocalesOptions, options, "localeMatcher");
			if (localeMatcher != NULL && strcmp(localeMatcher, "best fit") == 0) {
				ecma_bestFitSupportedLocales(return_value, availableLocales, availableLocalesLength, canonicalized,
				                             canonicalizedLength);
			} else {
				ecma_lookupSupportedLocales(return_value, availableLocales, availableLocalesLength, canonicalized,
				                            canonicalizedLength);
			}

			efree(availableLocales);
		}

		efree(canonicalized);
	}

	efree(locales);

	ecma402_freeErrorStatus(errorStatus);

	zend_hash_destroy(localesHt);
	FREE_HASHTABLE(localesHt);

	if (EG(exception)) {
		RETURN_THROWS();
	}
}
