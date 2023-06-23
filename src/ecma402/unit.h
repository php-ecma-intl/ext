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

#ifndef ECMA_INTL_ECMA402_UNIT_H
#define ECMA_INTL_ECMA402_UNIT_H

#include "common.h"

#define ECMA402_UNIT_CAPACITY 200

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

/**
 * Returns a list of unique sanctioned unit identifiers supported by this
 * implementation.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_UNIT_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_UNIT_CAPACITY)
 *
 * @param values A pointer in which to store the resulting char array of
 * currency values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_availableCanonicalUnits(const char **values);

/**
 * Verifies that the unitIdentifier argument is among the single unit
 * identifiers sanctioned in the current version of ECMA-402, which are a subset
 * of the Common Locale Data Repository release 38 unit validity data.
 *
 * @link https://tc39.es/ecma402/#sec-issanctionedsingleunitidentifier
 */
bool ecma402_isSanctionedSingleUnitIdentifier(const char *unitIdentifier);

/**
 * Verifies that the unitIdentifier argument represents a well-formed core unit
 * identifier that is either a sanctioned single unit or a complex unit formed
 * by division of two sanctioned single units.
 *
 * @link https://tc39.es/ecma402/#sec-iswellformedunitidentifier
 */
bool ecma402_isWellFormedUnitIdentifier(const char *unitIdentifier);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_UNIT_H */
