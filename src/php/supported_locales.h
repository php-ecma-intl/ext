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

#ifndef ECMA_INTL_PHP_SUPPORTED_LOCALES_H
#define ECMA_INTL_PHP_SUPPORTED_LOCALES_H

#include "php/php_common.h"

/**
 * Uses the Best Fit Matcher algorithm to return a subset of requestedLocales
 * for which a matching locale was found in availableLocales.
 *
 * At present, this simply calls ecma_lookupSupportedLocales(); this
 * implementation does not define a Best Fit Matcher algorithm (neither does
 * WebKit).
 *
 * @link https://tc39.es/ecma402/#sec-bestfitsupportedlocales
 * @link
 * https://github.com/WebKit/WebKit/blob/c734176258bc8893f77db22bb27f668485b53671/Source/JavaScriptCore/runtime/IntlObject.cpp#L1046-L1053
 *
 * @param rv A zval (usually return_value) already initialized as a PHP array for storing matched locales.
 * @param availableLocales An array of locales available to this implementation.
 * @param availableLocalesLength The number of items in availableLocales.
 * @param requestedLocales An array of the requested locales to match.
 * @param requestedLocalesLength The number of items in requestedLocales.
 *
 * @return The number of items added to rv.
 */
int ecma_bestFitSupportedLocales(zval *rv, char **availableLocales, int availableLocalesLength, char **requestedLocales,
                                 int requestedLocalesLength);

/**
 * Uses the BCP 47 Lookup algorithm to return a subset of requestedLocales
 * for which a matching locale was found in availableLocales.
 *
 * @link https://tc39.es/ecma402/#sec-lookupsupportedlocales
 * @link https://www.rfc-editor.org/rfc/rfc4647.html#section-3.4
 *
 * @param rv A zval (usually return_value) already initialized as a PHP array for storing matched locales.
 * @param availableLocales An array of locales available to this implementation.
 * @param availableLocalesLength The number of items in availableLocales.
 * @param requestedLocales An array of the requested locales to match.
 * @param requestedLocalesLength The number of items in requestedLocales.
 *
 * @return The number of items added to rv.
 */
int ecma_lookupSupportedLocales(zval *rv, char **availableLocales, int availableLocalesLength, char **requestedLocales,
                                int requestedLocalesLength);

/**
 * Handles calls to supportedLocalesOf() static methods on various Ecma\\Intl classes.
 */
void ecma_supportedLocalesOf(zend_execute_data *execute_data, zval *return_value);

#endif /* ECMA_INTL_PHP_SUPPORTED_LOCALES_H */
