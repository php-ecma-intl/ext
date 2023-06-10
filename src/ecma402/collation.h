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

#ifndef ECMA_INTL_ECMA402_COLLATION_H
#define ECMA_INTL_ECMA402_COLLATION_H

#include "src/common.h"

#include <stdbool.h>

#define COLLATION_CAPACITY 25

#define COLLATION_BIG5HAN "big5han"
#define COLLATION_COMPAT "compat"
#define COLLATION_DICT "dict"
#define COLLATION_DIRECT "direct"
#define COLLATION_DUCET "ducet"
#define COLLATION_EMOJI "emoji"
#define COLLATION_EOR "eor"
#define COLLATION_GB2312 "gb2312"
#define COLLATION_PHONEBK "phonebk"
#define COLLATION_PHONETIC "phonetic"
#define COLLATION_PINYIN "pinyin"
#define COLLATION_REFORMED "reformed"
#define COLLATION_SEARCH "search"
#define COLLATION_SEARCHJL "searchjl"
#define COLLATION_STANDARD "standard"
#define COLLATION_STROKE "stroke"
#define COLLATION_TRAD "trad"
#define COLLATION_UNIHAN "unihan"
#define COLLATION_ZHUYIN "zhuyin"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns a list of unique canonical collation types supported by this
 * implementation.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * COLLATION_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * COLLATION_CAPACITY)
 *
 * @param values A pointer in which to store the resulting char array of
 * collation values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int getAvailableCanonicalCollations(const char **values);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_COLLATION_H */
