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

#include "unit.h"
#include "util.h"

#include <cstring>
#include <unicode/measunit.h>
#include <unicode/strenum.h>

#define TYPES_CAPACITY 40
#define PER_UNIT "-per-"

#define SANCTIONED_UNIT_ACRE "acre"
#define SANCTIONED_UNIT_BIT "bit"
#define SANCTIONED_UNIT_BYTE "byte"
#define SANCTIONED_UNIT_CELSIUS "celsius"
#define SANCTIONED_UNIT_CENTIMETER "centimeter"
#define SANCTIONED_UNIT_DAY "day"
#define SANCTIONED_UNIT_DEGREE "degree"
#define SANCTIONED_UNIT_FAHRENHEIT "fahrenheit"
#define SANCTIONED_UNIT_FLUID_OUNCE "fluid-ounce"
#define SANCTIONED_UNIT_FOOT "foot"
#define SANCTIONED_UNIT_GALLON "gallon"
#define SANCTIONED_UNIT_GIGABIT "gigabit"
#define SANCTIONED_UNIT_GIGABYTE "gigabyte"
#define SANCTIONED_UNIT_GRAM "gram"
#define SANCTIONED_UNIT_HECTARE "hectare"
#define SANCTIONED_UNIT_HOUR "hour"
#define SANCTIONED_UNIT_INCH "inch"
#define SANCTIONED_UNIT_KILOBIT "kilobit"
#define SANCTIONED_UNIT_KILOBYTE "kilobyte"
#define SANCTIONED_UNIT_KILOGRAM "kilogram"
#define SANCTIONED_UNIT_KILOMETER "kilometer"
#define SANCTIONED_UNIT_LITER "liter"
#define SANCTIONED_UNIT_MEGABIT "megabit"
#define SANCTIONED_UNIT_MEGABYTE "megabyte"
#define SANCTIONED_UNIT_METER "meter"
#define SANCTIONED_UNIT_MICROSECOND "microsecond"
#define SANCTIONED_UNIT_MILE "mile"
#define SANCTIONED_UNIT_MILE_SCANDINAVIAN "mile-scandinavian"
#define SANCTIONED_UNIT_MILLILITER "milliliter"
#define SANCTIONED_UNIT_MILLIMETER "millimeter"
#define SANCTIONED_UNIT_MILLISECOND "millisecond"
#define SANCTIONED_UNIT_MINUTE "minute"
#define SANCTIONED_UNIT_MONTH "month"
#define SANCTIONED_UNIT_NANOSECOND "nanosecond"
#define SANCTIONED_UNIT_OUNCE "ounce"
#define SANCTIONED_UNIT_PERCENT "percent"
#define SANCTIONED_UNIT_PETABYTE "petabyte"
#define SANCTIONED_UNIT_POUND "pound"
#define SANCTIONED_UNIT_SECOND "second"
#define SANCTIONED_UNIT_STONE "stone"
#define SANCTIONED_UNIT_TERABIT "terabit"
#define SANCTIONED_UNIT_TERABYTE "terabyte"
#define SANCTIONED_UNIT_WEEK "week"
#define SANCTIONED_UNIT_YARD "yard"
#define SANCTIONED_UNIT_YEAR "year"

int ecma402_availableCanonicalUnits(const char **values) {
  icu::StringEnumeration *availableTypes;
  icu::MeasureUnit measureUnits[TYPES_CAPACITY];
  UErrorCode status = U_ZERO_ERROR;
  int typesCount, numUnitsInType, valuesCount = 0;
  const char *type;

  availableTypes = icu::MeasureUnit::getAvailableTypes(status);
  typesCount = availableTypes->count(status);
  availableTypes->reset(status);

  for (int i = 0; i < typesCount; i++) {
    type = availableTypes->next(nullptr, status);

    // Skip currency; we do not want to return currency identifiers as
    // measurement units.
    if (strcmp("currency", type) == 0) {
      continue;
    }

    numUnitsInType = icu::MeasureUnit::getAvailable(type, measureUnits,
                                                    TYPES_CAPACITY, status);

    for (int j = 0; j < numUnitsInType; j++) {
      if (!ecma402_isSanctionedSingleUnitIdentifier(
              measureUnits[j].getIdentifier())) {
        continue;
      }

      values[valuesCount] =
          (const char *)malloc(strlen(measureUnits[j].getIdentifier()) + 1);
      memcpy((void *)values[valuesCount], measureUnits[j].getIdentifier(),
             strlen(measureUnits[j].getIdentifier()) + 1);
      valuesCount++;
    }
  }

  delete availableTypes;

  return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount,
                                         ecma402_strToLower);
}

bool ecma402_isSanctionedSingleUnitIdentifier(const char *unitIdentifier) {
  if (strcasecmp(SANCTIONED_UNIT_ACRE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_BIT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_BYTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_CELSIUS, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_CENTIMETER, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_DAY, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_DEGREE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_FAHRENHEIT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_FLUID_OUNCE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_FOOT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_GALLON, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_GIGABIT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_GIGABYTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_GRAM, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_HECTARE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_HOUR, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_INCH, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_KILOBIT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_KILOBYTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_KILOGRAM, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_KILOMETER, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_LITER, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MEGABIT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MEGABYTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_METER, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MICROSECOND, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MILE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MILE_SCANDINAVIAN, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MILLILITER, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MILLIMETER, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MILLISECOND, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MINUTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_MONTH, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_NANOSECOND, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_OUNCE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_PERCENT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_PETABYTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_POUND, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_SECOND, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_STONE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_TERABIT, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_TERABYTE, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_WEEK, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_YARD, unitIdentifier) == 0 ||
      strcasecmp(SANCTIONED_UNIT_YEAR, unitIdentifier) == 0) {
    return true;
  }

  return false;
}

bool ecma402_isWellFormedUnitIdentifier(const char *unitIdentifier) {
  if (ecma402_isSanctionedSingleUnitIdentifier(unitIdentifier)) {
    return true;
  }

  std::string unitString(unitIdentifier);
  size_t perPosition = unitString.find(PER_UNIT);

  if (perPosition != std::string::npos) {
    std::string numerator = unitString.substr(0, perPosition);
    std::string denominator = unitString.substr(perPosition + strlen(PER_UNIT));

    if (ecma402_isSanctionedSingleUnitIdentifier(numerator.c_str()) &&
        ecma402_isSanctionedSingleUnitIdentifier(denominator.c_str())) {
      return true;
    }
  }

  return false;
}
