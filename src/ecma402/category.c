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

#include "category.h"

#include <string.h>

int getCapacityForCategory(const char *category) {
  if (strcmp(CATEGORY_CALENDAR, category) == 0) {
    return CATEGORY_CALENDAR_CAPACITY;
  } else if (strcmp(CATEGORY_COLLATION, category) == 0) {
    return CATEGORY_COLLATION_CAPACITY;
  } else if (strcmp(CATEGORY_CURRENCY, category) == 0) {
    return CATEGORY_CURRENCY_CAPACITY;
  } else if (strcmp(CATEGORY_NUMBERING_SYSTEM, category) == 0) {
    return CATEGORY_NUMBERING_SYSTEM_CAPACITY;
  } else if (strcmp(CATEGORY_TIME_ZONE, category) == 0) {
    return CATEGORY_TIME_ZONE_CAPACITY;
  } else if (strcmp(CATEGORY_UNIT, category) == 0) {
    return CATEGORY_UNIT_CAPACITY;
  }

  return 0;
}
