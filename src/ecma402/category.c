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

#include "ecma402/category.h"

#include "ecma402/calendar.h"
#include "ecma402/collation.h"
#include "ecma402/currency.h"
#include "ecma402/numbering_system.h"
#include "ecma402/time_zone.h"
#include "ecma402/unit.h"

#include <string.h>

int ecma402_supportedValuesForCategory(const char *category,
                                       const char **values) {
  if (strcmp(ECMA402_CATEGORY_CALENDAR, category) == 0) {
    return ecma402_availableCanonicalCalendars(values);
  } else if (strcmp(ECMA402_CATEGORY_COLLATION, category) == 0) {
    return ecma402_availableCanonicalCollations(values);
  } else if (strcmp(ECMA402_CATEGORY_CURRENCY, category) == 0) {
    return ecma402_availableCanonicalCurrencies(values);
  } else if (strcmp(ECMA402_CATEGORY_NUMBERING_SYSTEM, category) == 0) {
    return ecma402_availableCanonicalNumberingSystems(values);
  } else if (strcmp(ECMA402_CATEGORY_TIME_ZONE, category) == 0) {
    return ecma402_availableCanonicalTimeZones(values);
  } else if (strcmp(ECMA402_CATEGORY_UNIT, category) == 0) {
    return ecma402_availableCanonicalUnits(values);
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
    return ECMA402_NUMBERING_SYSTEM_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_TIME_ZONE, category) == 0) {
    return ECMA402_TIME_ZONE_CAPACITY;
  } else if (strcmp(ECMA402_CATEGORY_UNIT, category) == 0) {
    return ECMA402_UNIT_CAPACITY;
  }

  return 0;
}
