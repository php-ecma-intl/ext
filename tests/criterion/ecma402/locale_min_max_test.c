#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleMinMax

ParameterizedTestParameters(TEST_SUITE, maximize)
{
	START_STRING_TEST_PARAMS(11)
	STRING_TEST("en", "en-Latn-US")
	STRING_TEST("de", "de-Latn-DE")
	STRING_TEST("sr", "sr-Cyrl-RS")
	STRING_TEST("sh", "sr-Latn-RS")
	STRING_TEST("zh", "zh-Hans-CN")
	STRING_TEST("posix", "posix")
	STRING_TEST("mo", "ro-Latn-RO")
	STRING_TEST("es-ES-preeuro", "es-Latn-ES-preeuro")
	STRING_TEST("uz-UZ-cyrillic", "uz-Latn-UZ-cyrillic")
	STRING_TEST("hi-direct", "hi-Deva-IN-direct")
	STRING_TEST("heb-x-private", "he-Hebr-IL-x-private")
	END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, maximize)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	const int resultLength = ecma402_maximize(test->input, result, status, false);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (strcmp(test->expected, "-1") == 0) {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected),
		          "Expected maximized value of \"%s\" for language tag \"%s\"; got \"%s\" instead",
		          test->expected, test->input, result);
		cr_expect(eq(i8, resultLength, strlen(test->expected)));
	}

	free(result);
	ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, minimize)
{
	START_STRING_TEST_PARAMS(10)
	STRING_TEST("en-Latn-US", "en")
	STRING_TEST("de-Latn-DE", "de")
	STRING_TEST("sr-Cyrl-RS", "sr")
	STRING_TEST("zh-Hant-TW", "zh-TW")
	STRING_TEST("posix", "posix")
	STRING_TEST("mo", "ro")
	STRING_TEST("es-ES-preeuro", "es-preeuro")
	STRING_TEST("uz-UZ-cyrillic", "uz-cyrillic")
	STRING_TEST("hi-direct", "hi-direct")
	STRING_TEST("heb-x-private", "he-x-private")
	END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, minimize)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	const int resultLength = ecma402_minimize(test->input, result, status, false);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (strcmp(test->expected, "-1") == 0) {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected),
		          "Expected minimized value of \"%s\" for language tag \"%s\"; got \"%s\" instead", test->expected,
		          test->input, result);
		cr_expect(eq(i8, resultLength, strlen(test->expected)));
	}

	free(result);
	ecma402_freeErrorStatus(status);
}
