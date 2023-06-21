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
#include "calendar.h"
#include "collation.h"
#include "currency.h"

#include <string.h>

int ecma402_supportedValuesForCategory(const char *category,
                                       const char **values) {
  if (strcmp(ECMA402_CATEGORY_CALENDAR, category) == 0) {
    return ecma402_availableCanonicalCalendars(values);
  } else if (strcmp(ECMA402_CATEGORY_COLLATION, category) == 0) {
    return ecma402_availableCanonicalCollations(values);
  } else if (strcmp(ECMA402_CATEGORY_CURRENCY, category) == 0) {
    return ecma402_availableCanonicalCurrencies(values);
  }

  return 0;
}

int ecma402_capacityForCategory(const char *category) {
  if (strcmp(ECMA402_CATEGORY_CALENDAR, category) == 0) {
    return ECMA402_CALENDAR_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_COLLATION, category) == 0) {
    return ECMA402_COLLATION_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_CURRENCY, category) == 0) {
    return ECMA402_CURRENCY_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_NUMBERING_SYSTEM, category) == 0) {
    return CATEGORY_NUMBERING_SYSTEM_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_TIME_ZONE, category) == 0) {
    return CATEGORY_TIME_ZONE_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_UNIT, category) == 0) {
    return CATEGORY_UNIT_CAPACITY;
  }

  return 0;
}
