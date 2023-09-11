#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402Locale

struct bestAvailableTest {
	char *localeId;
	bool isCanonicalized;
	char *expected;
	int expectedLength;
};

static int addTest(struct bestAvailableTest *tests, int index, const char *localeId, bool isCanonicalized,
                   const char *expected, int expectedLength)
{
	if (localeId == NULL) {
		tests[index].localeId = NULL;
	} else {
		tests[index].localeId = testStrDup(localeId);
	}

	tests[index].isCanonicalized = isCanonicalized;

	if (expected == NULL) {
		tests[index].expected = NULL;
	} else {
		tests[index].expected = testStrDup(expected);
	}

	tests[index].expectedLength = expectedLength;

	return ++index;
}

void freeTests(struct criterion_test_params *criterionParams)
{
	struct bestAvailableTest *tests = (struct bestAvailableTest *)criterionParams->params;

	for (size_t i = 0; i < criterionParams->length; ++i) {
		if (tests[i].localeId != NULL) {
			cr_free(tests[i].localeId);
		}
		if (tests[i].expected != NULL) {
			cr_free(tests[i].expected);
		}
	}

	cr_free(tests);
}

Test(TEST_SUITE, keywordsOfLocaleReturnsZeroForUnknownKeyword)
{
	ecma402_locale *locale = ecma402_initLocale("foobar");
	cr_expect(eq(int, ecma402_keywordsOfLocale(locale, "unknown", NULL), 0));
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, intlAvailableLocales)
{
	char **locales;
	int count;
	bool foundEn = false, foundDe = false, foundFr = false, foundZh = false;

	locales = (char **)malloc(sizeof(char *) * uloc_countAvailable());
	count = ecma402_intlAvailableLocales(locales);

	cr_assert(gt(i16, count, 0));

	// Search for a few well-known locales that should be included.
	for (int i = 0; i < count; i++) {
		if (strcmp(locales[i], "en") == 0) {
			foundEn = true;
		} else if (strcmp(locales[i], "de") == 0) {
			foundDe = true;
		} else if (strcmp(locales[i], "fr") == 0) {
			foundFr = true;
		} else if (strcmp(locales[i], "zh") == 0) {
			foundZh = true;
		}
	}

	cr_expect(eq(i8, foundEn, true));
	cr_expect(eq(i8, foundDe, true));
	cr_expect(eq(i8, foundFr, true));
	cr_expect(eq(i8, foundZh, true));

	free(locales);
}

ParameterizedTestParameters(TEST_SUITE, bestAvailableLocale)
{
	struct bestAvailableTest *tests;
	int idx = 0;

	tests = (struct bestAvailableTest *)cr_malloc(sizeof(struct bestAvailableTest) * 100);
	idx = addTest(tests, idx, NULL, true, NULL, -1);
	idx = addTest(tests, idx, NULL, false, NULL, -1);
	idx = addTest(tests, idx, "", true, NULL, -1);
	idx = addTest(tests, idx, "", false, NULL, -1);
	idx = addTest(tests, idx, "en-US", true, "en-US", 5);
	idx = addTest(tests, idx, "en-US", false, "en-US", 5);
	idx = addTest(tests, idx, "en-GB", true, "en-GB", 5);
	idx = addTest(tests, idx, "en-GB", false, "en-GB", 5);
	idx = addTest(tests, idx, "en", true, "en", 2);
	idx = addTest(tests, idx, "en", false, "en", 2);
	idx = addTest(tests, idx, "en_US", true, NULL, -1);
	idx = addTest(tests, idx, "en_US", false, "en-US", 5);
	idx = addTest(tests, idx, "en-Latn-US", true, "en", 2);
	idx = addTest(tests, idx, "en-Latn-US", false, "en", 2);
	idx = addTest(tests, idx, "xx-XX", true, NULL, -1);
	idx = addTest(tests, idx, "xx-XX", false, NULL, -1);
	idx = addTest(tests, idx, "xx", true, NULL, -1);
	idx = addTest(tests, idx, "xx", false, NULL, -1);
	idx = addTest(tests, idx, "foobarbaz", true, NULL, -1);
	idx = addTest(tests, idx, "foobarbaz", false, NULL, -1);
	idx = addTest(tests, idx, "en-US-u-ca-gregory-co-emoji", true, "en-US", 5);
	idx = addTest(tests, idx, "en-US-u-ca-gregory-co-emoji", false, "en-US", 5);
	idx = addTest(tests, idx, "en_US@calendar=gregory;collation=emoji", true, NULL, -1);
	idx = addTest(tests, idx, "en_US@calendar=gregory;collation=emoji", false, "en-US", 5);
	idx = addTest(tests, idx, "hi-t-en-h0-hybrid", true, "hi", 2);

	return cr_make_param_array(struct bestAvailableTest, tests, idx, freeTests);
}

ParameterizedTest(struct bestAvailableTest *test, TEST_SUITE, bestAvailableLocale)
{
	char **available = (char **)malloc(sizeof(char *) * uloc_countAvailable());
	int count = ecma402_intlAvailableLocales(available);

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	int resultLength = ecma402_bestAvailableLocale(available, count, test->localeId, result, test->isCanonicalized);

	cr_expect(eq(i8, resultLength, test->expectedLength), "Expected length of %d for localeId \"%s\"; received %d",
	          test->expectedLength, test->localeId, resultLength);

	if (test->expected != NULL) {
		cr_expect(eq(str, result, test->expected), "Expected value of \"%s\" for localeId \"%s\"; received \"%s\"",
		          test->expected, test->localeId, result);
	}

	free(result);
	free(available);
}
