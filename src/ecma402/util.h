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
 * case-insensitive.
 *
 * @param array The array to sort and de-dupe.
 * @param length The length of the array (before de-duping).
 *
 * @return The new length of the array (after de-duping).
 */
int sortAndRemoveDuplicates(char **array, int length);

#endif /* ECMA_INTL_ECMA402_UTIL_H */
