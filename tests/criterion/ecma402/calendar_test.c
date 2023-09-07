#include "../test.h"

#include "ecma402/calendar.h"

#define TEST_SUITE ecma402Calendar

Test(TEST_SUITE, availableCanonicalCalendarsIsSorted)
{
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

Test(TEST_SUITE, availableCanonicalCalendarsReturnsOnlyBcp47Values)
{
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

Test(TEST_SUITE, calendarsOfLocaleReturnsPreferredCalendar)
{
	ecma402_locale *locale;
	const char **calendars;
	int calendarsLength;

	locale = ecma402_initLocale("en-US-u-ca-buddhist");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);

	cr_assert(eq(int, calendarsLength, 1));
	cr_expect(eq(str, (char *)calendars[0], "buddhist"));

	free(calendars);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, calendarsOfLocaleReturnsExpectedCalendars)
{
	ecma402_locale *locale;
	const char **calendars;
	int calendarsLength;

	// "en-US" has calendars of ["gregory"]
	locale = ecma402_initLocale("en-US");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);
	cr_assert(eq(int, calendarsLength, 1));
	cr_expect(eq(str, (char *)calendars[0], "gregory"));
	free(calendars);
	ecma402_freeLocale(locale);

	// "und" has calendars of ["gregory"]
	locale = ecma402_initLocale("und");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);
	cr_assert(eq(int, calendarsLength, 1));
	cr_expect(eq(str, (char *)calendars[0], "gregory"));
	free(calendars);
	ecma402_freeLocale(locale);

	// "zh" has calendars of ["gregory", "chinese"]
	locale = ecma402_initLocale("zh");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);
	cr_assert(eq(int, calendarsLength, 2));
	cr_expect(eq(str, (char *)calendars[0], "gregory"));
	cr_expect(eq(str, (char *)calendars[1], "chinese"));
	free(calendars);
	ecma402_freeLocale(locale);

	// "jp" has calendars of ["gregory"]
	locale = ecma402_initLocale("jp");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);
	cr_assert(eq(int, calendarsLength, 1));
	cr_expect(eq(str, (char *)calendars[0], "gregory"));
	free(calendars);
	ecma402_freeLocale(locale);

	// "jp-JP" has calendars of ["gregory", "japanese"]
	locale = ecma402_initLocale("jp-JP");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);
	cr_assert(eq(int, calendarsLength, 2));
	cr_expect(eq(str, (char *)calendars[0], "gregory"));
	cr_expect(eq(str, (char *)calendars[1], "japanese"));
	free(calendars);
	ecma402_freeLocale(locale);

	// "und-Thai" has calendars of ["buddhist", "gregory"]
	locale = ecma402_initLocale("und-Thai");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);
	cr_assert(eq(int, calendarsLength, 2));
	cr_expect(eq(str, (char *)calendars[0], "buddhist"));
	cr_expect(eq(str, (char *)calendars[1], "gregory"));
	free(calendars);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, calendarsOfLocaleReturnsNoCalendarsForInvalidLocaleId)
{
	ecma402_locale *locale;
	const char **calendars;
	int calendarsLength;

	locale = ecma402_initLocale("foobar-baz");
	calendars = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CALENDAR_CAPACITY);
	calendarsLength = ecma402_calendarsOfLocale(locale, calendars);

	cr_assert(eq(int, calendarsLength, 0));

	free(calendars);
	ecma402_freeLocale(locale);
}
