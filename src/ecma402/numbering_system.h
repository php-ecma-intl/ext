/*
   +----------------------------------------------------------------------+
   | ecma_intl extension for PHP                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Ben Ramsey <ben@benramsey.com>                         |
   | This source file is subject to the MIT license that is bundled with  |
   | this package in the file LICENSE, and is available at the following  |
   | web address: https://opensource.org/license/mit/                     |
   +----------------------------------------------------------------------+
*/

#ifndef ECMA_INTL_ECMA402_NUMBERING_SYSTEM_H
#define ECMA_INTL_ECMA402_NUMBERING_SYSTEM_H

#include "src/common.h"

/**
 * Maximum capacity to allocate for a list of numbering systems.
 *
 * There are 91 numbering systems in the Unicode CLDR. This allows for some
 * unexpected growth. See:
 * https://github.com/unicode-org/cldr/blob/2bdb200756fc483c106f8879734a32d279ef43ed/common/bcp47/number.xml
 */
#define ECMA402_NUMBERING_SYSTEM_CAPACITY 120

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

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_NUMBERING_SYSTEM_H */
