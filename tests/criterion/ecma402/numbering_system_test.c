#include "../test.h"

#include "ecma402/numbering_system.h"

#define TEST_SUITE ecma402NumberingSystem

Test(TEST_SUITE, availableCanonicalNumberingSystemsIsSorted)
{
	const char **numberingSystems = (const char **)malloc(sizeof(char *) * ECMA402_NUMBERING_SYSTEM_CAPACITY);
	const int numberingSystemsLength = ecma402_availableCanonicalNumberingSystems(numberingSystems);

	cr_expect(gt(int, numberingSystemsLength, 0));

	const char *previous = "";
	for (int i = 0; i < numberingSystemsLength; i++) {
		// Expect sorted values (i.e., this value is greater than the previous).
		cr_expect(gt(int, strcmp(numberingSystems[i], previous), 0));

		previous = numberingSystems[i];
	}

	free((void *)numberingSystems);
}

Test(TEST_SUITE, numberingSystemsOfLocaleReturnsPreferredNumberingSystem)
{
	ecma402_locale *locale = ecma402_initLocale("en-US-u-nu-arab");
	const char **values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
	const int valuesLength = ecma402_numberingSystemsOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, 1));
	cr_expect(eq(str, (char *)values[0], "arab"));

	free((void *)values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, numberingSystemsOfLocaleReturnsNoNumberingSystemsForInvalidLocaleId)
{
	ecma402_locale *locale = ecma402_initLocale("foobar-baz");
	const char **values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
	const int valuesLength = ecma402_numberingSystemsOfLocale(locale, values);

	cr_assert(eq(int, valuesLength, 0));

	free((void *)values);
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, numberingSystemsOfLocaleReturnsExpectedNumberingSystems)
{
	ecma402_locale *locale;
	const char **values;
	int valuesLength;

	// "en-US" has numbering systems of ["latn"]
	locale = ecma402_initLocale("en-US");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
	valuesLength = ecma402_numberingSystemsOfLocale(locale, values);
	cr_assert(eq(int, valuesLength, 1));
	cr_expect(eq(str, (char *)values[0], "latn"));
	free((void *)values);
	ecma402_freeLocale(locale);

	// "fa" has numbering systems of ["arabext"]
	locale = ecma402_initLocale("fa");
	values = (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
	valuesLength = ecma402_numberingSystemsOfLocale(locale, values);
	cr_assert(eq(int, valuesLength, 1));
	cr_expect(eq(str, (char *)values[0], "arabext"));
	free((void *)values);
	ecma402_freeLocale(locale);
}
