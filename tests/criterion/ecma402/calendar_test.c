#include "../test.h"

#include "ecma402/calendar.h"

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

Test(TEST_SUITE, calendarsOfLocaleReturnsPreferredCalendar) {
  const char **calendars;
  int calendarsLength;

  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("en-US-u-ca-buddhist", calendars);

  cr_assert(eq(int, calendarsLength, 1));
  cr_expect(eq(str, (char *)calendars[0], "buddhist"));

  free(calendars);
}

Test(TEST_SUITE, calendarsOfLocaleReturnsExpectedCalendars) {
  const char **calendars;
  int calendarsLength;

  // "en-US" has calendars of ["gregory"]
  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("en-US", calendars);
  cr_assert(eq(int, calendarsLength, 1));
  cr_expect(eq(str, (char *)calendars[0], "gregory"));
  free(calendars);

  // "und" has calendars of ["gregory"]
  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("und", calendars);
  cr_assert(eq(int, calendarsLength, 1));
  cr_expect(eq(str, (char *)calendars[0], "gregory"));
  free(calendars);

  // "zh" has calendars of ["gregory", "chinese"]
  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("zh", calendars);
  cr_assert(eq(int, calendarsLength, 2));
  cr_expect(eq(str, (char *)calendars[0], "gregory"));
  cr_expect(eq(str, (char *)calendars[1], "chinese"));
  free(calendars);

  // "jp" has calendars of ["gregory"]
  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("jp", calendars);
  cr_assert(eq(int, calendarsLength, 1));
  cr_expect(eq(str, (char *)calendars[0], "gregory"));
  free(calendars);

  // "jp-JP" has calendars of ["gregory", "japanese"]
  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("jp-JP", calendars);
  cr_assert(eq(int, calendarsLength, 2));
  cr_expect(eq(str, (char *)calendars[0], "gregory"));
  cr_expect(eq(str, (char *)calendars[1], "japanese"));
  free(calendars);

  // "und-Thai" has calendars of ["buddhist", "gregory"]
  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("und-Thai", calendars);
  cr_assert(eq(int, calendarsLength, 2));
  cr_expect(eq(str, (char *)calendars[0], "buddhist"));
  cr_expect(eq(str, (char *)calendars[1], "gregory"));
  free(calendars);
}

Test(TEST_SUITE, calendarsOfLocaleReturnsNoCalendarsForInvalidLocaleId) {
  const char **calendars;
  int calendarsLength;

  calendars = (const char **)malloc(sizeof(char *) * ECMA402_CALENDAR_CAPACITY);
  calendarsLength = ecma402_calendarsOfLocale("foobar-baz", calendars);

  cr_assert(eq(int, calendarsLength, 0));

  free(calendars);
}
