#include "../test.h"

#include "ecma402/time_zone.h"

#define TEST_SUITE ecma402TimeZone

Test(TEST_SUITE, availableCanonicalTimeZonesIsSorted)
{
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

Test(TEST_SUITE, timeZonesOfLocaleReturnsAllTimeZonesEvenIfPreferredIsSet)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;

	locale = ecma402_initLocale("en-US-u-tz-uschi");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
	valuesLength = ecma402_timeZonesOfLocale(locale, values);

	// Assert there are more than 20 time zones.
	cr_assert(gt(int, valuesLength, 20));

	free(values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsNoTimeZonesForInvalidLocaleId)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;

	locale = ecma402_initLocale("foobar-baz");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
	valuesLength = ecma402_timeZonesOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, 0));

	free(values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsNegativeOneForLocaleWithoutRegion)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;

	locale = ecma402_initLocale("en");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
	valuesLength = ecma402_timeZonesOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, -1));

	free(values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsZeroForLocaleWithUnknownRegion)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;

	locale = ecma402_initLocale("en-999");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
	valuesLength = ecma402_timeZonesOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, 0));

	free(values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, timeZonesOfLocaleReturnsExpectedTimeZones)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;
	bool foundAmericaNewYork = false, foundAmericaChicago = false, foundAmericaDenver = false,
		 foundAmericaLosAngeles = false;

	// "en-US" has a lot of time zone identifiers. We'll check a few known ones.
	locale = ecma402_initLocale("en-US");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_TIME_ZONE_CAPACITY);
	valuesLength = ecma402_timeZonesOfLocale(locale, values);

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

	free(values);
	ecma402_freeLocale(locale);
}
