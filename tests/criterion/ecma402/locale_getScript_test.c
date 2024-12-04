#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleGetScript

ParameterizedTestParameters(TEST_SUITE, getScript)
{
	START_STRING_TEST_PARAMS(11)
	STRING_TEST("und", "-1")
	STRING_TEST("und-Latn-US", "Latn")
	STRING_TEST("de", "-1")
	STRING_TEST("de-DE", "-1")
	STRING_TEST("cmn", "-1")
	STRING_TEST("cmn-hans-cn", "Hans")
	STRING_TEST("es-419", "-1")
	STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "Hans")
	STRING_TEST("de-gregory-u-ca-gregory", "-1")
	STRING_TEST("de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn", "Latn")
	STRING_TEST("ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "Jpan")
	STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn", "Latn")
	END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getScript)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_SCRIPT_CAPACITY);
	const int resultLength = ecma402_getScript(test->input, result, status, false);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (strcmp(test->expected, "-1") == 0) {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected), "Expected locale \"%s\" script of \"%s\"; got \"%s\" instead",
		          test->input, test->expected, result);
		cr_expect(eq(i8, resultLength, strlen(test->expected)));
	}

	free(result);
	ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, getScriptReturnsNegativeOneForNullPointer)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_SCRIPT_CAPACITY);
	const int resultLength = ecma402_getScript(NULL, result, status, false);

	cr_expect(eq(i8, resultLength, -1));
	cr_expect(eq(i8, ecma402_hasError(status), 0));

	free(result);
	ecma402_freeErrorStatus(status);
}
