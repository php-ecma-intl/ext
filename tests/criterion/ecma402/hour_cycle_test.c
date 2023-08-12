#include "../test.h"

#include "ecma402/hour_cycle.h"

#define TEST_SUITE ecma402HourCycle

Test(TEST_SUITE, hourCyclesOfLocaleReturnsPreferredHourCycle) {
  const char **values;
  int valuesLength;

  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
  valuesLength = ecma402_hourCyclesOfLocale("en-US-u-hc-h24", values);

  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "h24"));

  free(values);
}

Test(TEST_SUITE, hourCyclesOfLocaleReturnsNoHourCyclesForInvalidLocaleId) {
  const char **values;
  int valuesLength;

  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
  valuesLength = ecma402_hourCyclesOfLocale("foobar-baz", values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
}

Test(TEST_SUITE, hourCyclesOfLocaleReturnsExpectedHourCycles) {
  const char **values;
  int valuesLength;

  // "en-US" has hour cycles of ["h12"]
  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
  valuesLength = ecma402_hourCyclesOfLocale("en-US", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "h12"));
  free(values);

  // "de-DE" has hour cycles of ["h23"]
  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
  valuesLength = ecma402_hourCyclesOfLocale("de-DE", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "h23"));
  free(values);
}
