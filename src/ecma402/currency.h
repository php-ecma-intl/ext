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

#ifndef ECMA_INTL_ECMA402_CURRENCY_H
#define ECMA_INTL_ECMA402_CURRENCY_H

#include "common.h"

/**
 * A sufficient capacity for storing all currencies supported by this
 * implementation.
 *
 * There are 305 currencies in the Unicode CLDR. This allows for some unexpected
 * growth.
 *
 * @link
 * https://github.com/unicode-org/cldr/blob/41d1fbf1cee9ddc05893ea525db94d77614c8594/common/bcp47/currency.xml
 */
#define ECMA402_CURRENCY_CAPACITY 325

/**
 * A sufficient capacity for storing a list of currency types for a given
 * locale.
 */
#define ECMA402_LOCALE_CURRENCY_CAPACITY 10

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns a list of unique canonical currency types supported by this
 * implementation.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_CURRENCY_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_CURRENCY_CAPACITY)
 *
 * @param values A pointer in which to store the resulting char array of
 * currency values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_availableCanonicalCurrencies(const char **values);

/**
 * Returns a list of one or more unique canonical currency identifiers for the
 * given locale identifier.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_LOCALE_CURRENCY_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_LOCALE_CURRENCY_CAPACITY)
 *
 * @param localeId The locale identifier to get the currencies for.
 * @param values A pointer in which to store the resulting char array of
 * currency values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_currenciesOfLocale(const char *localeId, const char **values);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_CURRENCY_H */
