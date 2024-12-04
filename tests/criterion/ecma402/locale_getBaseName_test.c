#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleGetBaseName

ParameterizedTestParameters(TEST_SUITE, getBaseName)
{
	START_STRING_TEST_PARAMS(25)
	STRING_TEST("de", "de")
	STRING_TEST("DE-de", "de-DE")
	STRING_TEST("de-DE", "de-DE")
	STRING_TEST("cmn", "zh")
	STRING_TEST("CMN-hANS", "zh-Hans")
	STRING_TEST("cmn-hans-cn", "zh-Hans-CN")
	STRING_TEST("es-419", "es-419")
	STRING_TEST("es-419-u-nu-latn", "es-419")
	STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "zh-Hans-CN")
	STRING_TEST("de-gregory-u-ca-gregory", "de-gregory")
	STRING_TEST("sgn-GR", "gss")
	STRING_TEST("ji", "yi")
	STRING_TEST("de-DD", "de-DE")
	STRING_TEST("in", "id")
	STRING_TEST("sr-cyrl-ekavsk", "sr-Cyrl-ekavsk")
	STRING_TEST("en-ca-newfound", "en-CA-newfound")
	STRING_TEST("sl-rozaj-biske-1994", "sl-1994-biske-rozaj")
	STRING_TEST("da-u-attr", "da")
	STRING_TEST("da-u-attr-co-search", "da")
	STRING_TEST("und", "-1")
	STRING_TEST("en-US", "en-US")
	STRING_TEST("zh-xiang-u-nu-thai-x-0", "hsn")
	STRING_TEST("de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn", "de-Latn-DE")
	STRING_TEST("ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "ja-Jpan-JP")
	STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn", "fr-Latn-CA")
	END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getBaseName)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	const int resultLength = ecma402_getBaseName(test->input, result, status, false);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (strcmp(test->expected, "-1") == 0) {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected), "Expected locale \"%s\" base name of \"%s\"; got \"%s\" instead",
		          test->input, test->expected, result);
		cr_expect(eq(i8, resultLength, strlen(test->expected)), "Expected length %d for locale \"%s\"; got %d instead",
		          strlen(test->expected), test->input, resultLength);
	}

	free(result);
	ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, getBaseNameHasErrorForStructurallyInvalidLocaleId)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	const int resultLength = ecma402_getBaseName("en_US_POSIX", result, status, false);

	cr_expect(eq(i8, resultLength, -1));
	cr_expect(eq(i8, ecma402_hasError(status), 1));
	cr_expect(eq(i16, status->ecma, STRUCTURALLY_INVALID_LOCALE_ID));
	cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
	cr_expect(eq(str, status->errorMessage, "Invalid language tag \"en_US_POSIX\""));

	free(result);
	ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, getBaseNameReturnsNegativeOneForNullPointer)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	const int resultLength = ecma402_getBaseName(NULL, result, status, false);

	cr_expect(eq(i8, resultLength, -1));
	cr_expect(eq(i8, ecma402_hasError(status), 0));

	free(result);
	ecma402_freeErrorStatus(status);
}
