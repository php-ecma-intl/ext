#include "../test.h"

#include "src/ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleValidation

// NOLINTBEGIN(cert-err58-cpp, misc-const-correctness,
//             misc-use-anonymous-namespace)

using string = std::basic_string<char, std::char_traits<char>, criterion::allocator<char>>;

struct localeIdValidationTest
{
	string localeId;
	string expected;

	localeIdValidationTest(string localeId, string expected) : localeId(localeId), expected(expected)
	{
	}
};

ParameterizedTestParameters(TEST_SUITE, validateAndCanonicalizeUnicodeLocaleId)
{
	static criterion::parameters<struct localeIdValidationTest> tests;

	tests.emplace_back("en-US", "en-US");
	tests.emplace_back("en_US", "en-US");
	tests.emplace_back("en-Latn-US", "en-Latn-US");
	tests.emplace_back("en-US-u-nu-latn-ca-gregory", "en-US-u-ca-gregory-nu-latn");
	tests.emplace_back("foobar", "-1");
	tests.emplace_back("zz-ZZ", "-1");
	tests.emplace_back("und-u-va-posix", "-1");
	tests.emplace_back("en-US-POSIX", "en-US-u-va-posix");
	tests.emplace_back("en_US_POSIX", "en-US-u-va-posix");

	return tests;
}

ParameterizedTest(struct localeIdValidationTest *test, TEST_SUITE, validateAndCanonicalizeUnicodeLocaleId)
{
	ecma402_errorStatus *status = ecma402_initErrorStatus();

	char *result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
	const size_t resultLength = ecma402_validateAndCanonicalizeUnicodeLocaleId(test->localeId.c_str(), result, status);

	cr_assert(eq(i8, ecma402_hasError(status), 0));

	if (test->expected == "-1") {
		cr_expect(eq(i8, resultLength, -1));
	} else {
		cr_expect(eq(str, result, test->expected.c_str()),
		          "Expected canonicalized value of \"%s\" for language tag \"%s\"; got \"%s\" instead",
		          test->expected.c_str(), test->localeId.c_str(), result);
		cr_expect(eq(i8, resultLength, test->expected.length()));
	}

	free(result);
	ecma402_freeErrorStatus(status);
}

// NOLINTEND(cert-err58-cpp, misc-const-correctness,
//           misc-use-anonymous-namespace)
