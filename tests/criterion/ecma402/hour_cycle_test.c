#include "../test.h"

#include "ecma402/hour_cycle.h"

#define TEST_SUITE ecma402HourCycle

Test(TEST_SUITE, hourCyclesOfLocaleReturnsPreferredHourCycle)
{
	ecma402_locale *locale = ecma402_initLocale("en-US-u-hc-h24");
	const char **values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
	const int valuesLength = ecma402_hourCyclesOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, 1));
	cr_expect(eq(str, (char *)values[0], "h24"));

	free((void *)values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, hourCyclesOfLocaleReturnsNoHourCyclesForInvalidLocaleId)
{
	ecma402_locale *locale = ecma402_initLocale("foobar-baz");
	const char **values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
	const int valuesLength = ecma402_hourCyclesOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, 0));

	free((void *)values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, hourCyclesOfLocaleReturnsExpectedHourCycles)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;

	// "en-US" has hour cycles of ["h12"]
	locale = ecma402_initLocale("en-US");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
	valuesLength = ecma402_hourCyclesOfLocale(locale, values);
	cr_assert(eq(int, valuesLength, 1));
	cr_expect(eq(str, (char *)values[0], "h12"));
	free((void *)values);
	ecma402_freeLocale(locale);

	// "de-DE" has hour cycles of ["h23"]
	locale = ecma402_initLocale("de-DE");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_HOUR_CYCLE_CAPACITY);
	valuesLength = ecma402_hourCyclesOfLocale(locale, values);
	cr_assert(eq(int, valuesLength, 1));
	cr_expect(eq(str, (char *)values[0], "h23"));
	free((void *)values);
	ecma402_freeLocale(locale);
}
