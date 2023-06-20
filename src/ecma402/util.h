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

#ifndef ECMA_INTL_ECMA402_UTIL_H
#define ECMA_INTL_ECMA402_UTIL_H

#include "src/common.h"

/**
 * Sorts an array and removes duplicate values. This operation is
 * case-sensitive.
 *
 * If callback is provided, it is applied to each element of the array before
 * sorting and removing duplicates. For example, you may wish to convert all
 * values to lowercase before sorting and removing duplicates.
 *
 * @param array The array to sort and de-dupe.
 * @param length The length of the array (before de-duping).
 * @param callback An optional callback to apply to each element of the array
 * (e.g., strToLower, strToUpper). Pass NULL if you do not wish to provide a
 * callback.
 *
 * @return The new length of the array (after de-duping).
 */
int sortAndRemoveDuplicates(char **array, int length,
                            char *(*callback)(char *));

/**
 * Converts a string to all lowercase characters.
 */
char *strToLower(char *string);

/**
 * Converts a string to all uppercase characters.
 */
char *strToUpper(char *string);

#endif /* ECMA_INTL_ECMA402_UTIL_H */
