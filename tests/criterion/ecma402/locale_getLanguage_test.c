#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleGetLanguage

ParameterizedTestParameters(TEST_SUITE, getLanguage)
{
	START_STRING_TEST_PARAMS(11)
	STRING_TEST("und", "-1")
	STRING_TEST("und-Latn-US", "-1")
	STRING_TEST("de", "de")
	STRING_TEST("de-DE", "de")
	STRING_TEST("cmn", "zh")
	STRING_TEST("cmn-hans-cn", "zh")
	STRING_TEST("es-419", "es")
	STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "zh")
	STRING_TEST("de-gregory-u-ca-gregory", "de")
	STRING_TEST("de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn", "de")
	STRING_TEST("ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "ja")
	STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn", "fr")
	END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getLanguage)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_LANG_CAPACITY);
	const int resultLength = ecma402_getLanguage(test->input, result, status, false);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (strcmp(test->expected, "-1") == 0) {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected), "Expected locale \"%s\" language of \"%s\"; got \"%s\" instead",
		          test->input, test->expected, result);
		cr_expect(eq(i8, resultLength, strlen(test->expected)));
	}

	free(result);
	ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, getLanguageReturnsNegativeOneForNullPointer)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_LANG_CAPACITY);
	const int resultLength = ecma402_getLanguage(NULL, result, status, false);

	cr_expect(eq(i8, resultLength, -1));
	cr_expect(eq(i8, ecma402_hasError(status), 0));

	free(result);
	ecma402_freeErrorStatus(status);
}
