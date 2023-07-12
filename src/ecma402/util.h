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

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Removes duplicate values. This operation is case-sensitive.
 *
 * If callback is provided, it is applied to each element of the array before
 * sorting and removing duplicates. For example, you may wish to convert all
 * values to lowercase before and removing duplicates.
 *
 * @param array The array to sort and de-dupe.
 * @param length The length of the array (before de-duping).
 * @param callback An optional callback to apply to each element of the array
 * (e.g., ecma402_strToLower, ecma402_strToUpper). Pass NULL if you do not wish
 * to provide a callback.
 *
 * @return The new length of the array (after de-duping).
 */
int ecma402_removeDuplicates(char **array, int length,
                             char *(*callback)(char *));

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
 * (e.g., ecma402_strToLower, ecma402_strToUpper). Pass NULL if you do not wish
 * to provide a callback.
 *
 * @return The new length of the array (after de-duping).
 */
int ecma402_sortAndRemoveDuplicates(char **array, int length,
                                    char *(*callback)(char *));

/**
 * Converts a string to all lowercase characters.
 */
char *ecma402_strToLower(char *string);

/**
 * Converts a string to all uppercase characters.
 */
char *ecma402_strToUpper(char *string);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace ecma402 {
namespace util {

/**
 * Returns true if character is an ASCII alphanumeric value.
 */
bool isAsciiAlnum(unsigned char character);

/**
 * Returns true if character is an ASCII alphabet value.
 */
bool isAsciiAlpha(unsigned char character);

/**
 * Returns true if character is an ASCII numeric digit value.
 */
bool isAsciiDigit(unsigned char character);

/**
 * Returns true if character is an ASCII lowercase alphabet value.
 */
bool isAsciiLower(unsigned char character);

/**
 * Returns true if character is an ASCII uppercase alphabet value.
 */
bool isAsciiUpper(unsigned char character);

/**
 * Returns the ASCII lowercase variant of the character, if possible.
 */
unsigned char toAsciiLower(unsigned char character);

/**
 * Returns the ASCII uppercase variant of the character, if possible.
 */
unsigned char toAsciiUpper(unsigned char character);

} // namespace util
} // namespace ecma402

#endif

#endif /* ECMA_INTL_ECMA402_UTIL_H */
