#include "tests/criterion/test.h"

#include "src/ecma402/time_zone.h"

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
