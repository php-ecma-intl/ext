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

#ifndef ECMA_INTL_ECMA402_CATEGORY_H
#define ECMA_INTL_ECMA402_CATEGORY_H

#include "src/common.h"

#define CATEGORY_CALENDAR "calendar"
#define CATEGORY_COLLATION "collation"
#define CATEGORY_CURRENCY "currency"
#define CATEGORY_NUMBERING_SYSTEM "numberingSystem"
#define CATEGORY_TIME_ZONE "timeZone"
#define CATEGORY_UNIT "unit"

#define CATEGORY_CALENDAR_CAPACITY 25
#define CATEGORY_COLLATION_CAPACITY 25
#define CATEGORY_CURRENCY_CAPACITY 325
#define CATEGORY_NUMBERING_SYSTEM_CAPACITY 100
#define CATEGORY_TIME_ZONE_CAPACITY 650
#define CATEGORY_UNIT_CAPACITY 200

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns the recommended const char ** capacity for the given category.
 */
int getCapacityForCategory(const char *category);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_CATEGORY_H */
