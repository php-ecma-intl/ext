#include "tests/criterion/test.h"

#include "src/ecma402/calendar.h"

#define TEST_SUITE ecma402Calendar

Test(TEST_SUITE, availableCanonicalCalendarsIsSorted) {
  const char **calendars;
  int calendarsLength;

  calendars = malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_availableCanonicalCalendars(calendars);

  cr_expect(gt(int, calendarsLength, 0));

  const char *previous = "";
  for (int i = 0; i < calendarsLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(calendars[i], previous), 0));

    previous = calendars[i];
  }

  free(calendars);
}

Test(TEST_SUITE, availableCanonicalCalendarsReturnsOnlyBcp47Values) {
  const char **calendars;
  int calendarsLength;

  calendars = malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_availableCanonicalCalendars(calendars);

  cr_expect(gt(int, calendarsLength, 0));

  for (int i = 0; i < calendarsLength; i++) {
    cr_expect(ne(str, (char *)calendars[i], "ethiopic-amete-alem"));
    cr_expect(ne(str, (char *)calendars[i], "gregorian"));
    cr_expect(ne(str, (char *)calendars[i], "islamicc"));
  }

  free(calendars);
}
