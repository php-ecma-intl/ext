#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleGetRegion

ParameterizedTestParameters(TEST_SUITE, getRegion)
{
	START_STRING_TEST_PARAMS(11)
	STRING_TEST("und", "-1")
	STRING_TEST("und-Latn-US", "US")
	STRING_TEST("de", "-1")
	STRING_TEST("de-DE", "DE")
	STRING_TEST("cmn", "-1")
	STRING_TEST("cmn-hans-cn", "CN")
	STRING_TEST("es-419", "419")
	STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "CN")
	STRING_TEST("de-gregory-u-ca-gregory", "-1")
	STRING_TEST("de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn", "DE")
	STRING_TEST("ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "JP")
	STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn", "CA")
	END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getRegion)
{
	char *result;
	int resultLength;
	ecma402_errorStatus *status;

	status = ecma402_initErrorStatus();

	result = (char *)malloc(sizeof(char) * ULOC_COUNTRY_CAPACITY);
	resultLength = ecma402_getRegion(test->input, result, status, false);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (strcmp(test->expected, "-1") == 0) {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected), "Expected locale \"%s\" region of \"%s\"; got \"%s\" instead",
		          test->input, test->expected, result);
		cr_expect(eq(i8, resultLength, strlen(test->expected)));
	}

	free(result);
}

Test(TEST_SUITE, getRegionReturnsNegativeOneForNullPointer)
{
	char *result;
	ecma402_errorStatus *status;
	int resultLength;

	status = ecma402_initErrorStatus();

	result = (char *)malloc(sizeof(char) * ULOC_COUNTRY_CAPACITY);
	resultLength = ecma402_getRegion(NULL, result, status, false);

	cr_expect(eq(i8, resultLength, -1));
	cr_expect(eq(i8, ecma402_hasError(status), 0));

	free(result);
	ecma402_freeErrorStatus(status);
}
