#include "../test.h"

#include "ecma402/time_zone.h"

#define TEST_SUITE ecma402TimeZone

Test(TEST_SUITE, availableCanonicalTimeZonesIsSorted) {
  const char **timeZones;
  int timeZonesLength;

  timeZones = malloc(sizeof(char *) * ECMA402_TIME_ZONE_CAPACITY);
  timeZonesLength = ecma402_availableCanonicalTimeZones(timeZones);

  cr_expect(gt(int, timeZonesLength, 0));

  const char *previous = "";
  for (int i = 0; i < timeZonesLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(timeZones[i], previous), 0));

    previous = timeZones[i];
  }

  free(timeZones);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsAllTimeZonesEvenIfPreferredIsSet) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
  valuesLength = ecma402_timeZonesOfLocale("en-US-u-tz-uschi", values);

  // Assert there are more than 20 time zones.
  cr_assert(gt(int, valuesLength, 20));

  free(values);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsNoTimeZonesForInvalidLocaleId) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
  valuesLength = ecma402_timeZonesOfLocale("foobar-baz", values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsNegativeOneForLocaleWithoutRegion) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
  valuesLength = ecma402_timeZonesOfLocale("en", values);

  cr_assert(eq(int, valuesLength, -1));

  free(values);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsZeroForLocaleWithUnknownRegion) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
  valuesLength = ecma402_timeZonesOfLocale("en-999", values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsExpectedTimeZones) {
  const char **values;
  int valuesLength;
  bool foundAmericaNewYork = false, foundAmericaChicago = false,
       foundAmericaDenver = false, foundAmericaLosAngeles = false;

  // "en-US" has a lot of time zone identifiers. We'll check a few known ones.
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
  valuesLength = ecma402_timeZonesOfLocale("en-US", values);

  // Assert there are more than 20 time zones.
  cr_assert(gt(int, valuesLength, 20));

  for (int i = 0; i < valuesLength; i++) {
    if (strcmp(values[i], "America/New_York") == 0) {
      foundAmericaNewYork = true;
    } else if (strcmp(values[i], "America/Chicago") == 0) {
      foundAmericaChicago = true;
    } else if (strcmp(values[i], "America/Denver") == 0) {
      foundAmericaDenver = true;
    } else if (strcmp(values[i], "America/Los_Angeles") == 0) {
      foundAmericaLosAngeles = true;
    }
  }

  cr_expect(eq(i8, foundAmericaNewYork, true));
  cr_expect(eq(i8, foundAmericaChicago, true));
  cr_expect(eq(i8, foundAmericaDenver, true));
  cr_expect(eq(i8, foundAmericaLosAngeles, true));
}
