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

#ifndef ECMA_INTL_ECMA402_NUMBERING_SYSTEM_H
#define ECMA_INTL_ECMA402_NUMBERING_SYSTEM_H

#include "common.h"

/**
 * A sufficient capacity for storing all numbering systems supported by this
 * implementation.
 *
 * There are 91 numbering systems in the Unicode CLDR. This allows for some
 * unexpected growth.
 *
 * @link
 * https://github.com/unicode-org/cldr/blob/2bdb200756fc483c106f8879734a32d279ef43ed/common/bcp47/number.xml
 */
#define ECMA402_NUMBERING_SYSTEM_CAPACITY 120

/**
 * A sufficient capacity for storing a list of numbering systems for a given
 * locale.
 */
#define ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY 1

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns a list of unique numbering systems supported by this implementation.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_NUMBERING_SYSTEM_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_NUMBERING_SYSTEM_CAPACITY)
 *
 * @param values A pointer in which to store the resulting char array of
 * currency values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_availableCanonicalNumberingSystems(const char **values);

/**
 * Returns a list of one or more unique canonical numbering system identifiers
 * for the given locale identifier.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY)
 *
 * @param localeId The locale identifier to get the numbering systems for.
 * @param values A pointer in which to store the resulting char array of
 * numbering system values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_numberingSystemsOfLocale(const char *localeId, const char **values);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_NUMBERING_SYSTEM_H */
