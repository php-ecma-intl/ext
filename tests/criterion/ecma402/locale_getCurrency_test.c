#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleGetCurrency

ParameterizedTestParameters(TEST_SUITE, getCurrency) {
  START_STRING_TEST_PARAMS(14)
  STRING_TEST("en-US", "-1")
  STRING_TEST("en-US-u-cu-usn", "USN")
  STRING_TEST("de", "-1")
  STRING_TEST("de-DE", "-1")
  STRING_TEST("cmn", "-1")
  STRING_TEST("cmn-hans-cn-u-cu-cny", "CNY")
  STRING_TEST("es-419", "-1")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "-1")
  STRING_TEST("de-gregory-u-ca-gregory", "-1")
  STRING_TEST("de-latn-de-u-ca-gregory-co-phonebk-cu-usd-hc-h23-kf-true-kn-"
              "false-nu-latn",
              "USD")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-cu-eur-hc-h24-kf-false-kn-nu-jpanfin",
      "EUR")
  STRING_TEST(
      "fr-latn-ca-u-ca-gregory-co-standard-cu-cad-hc-h11-kf-kn-false-nu-latn",
      "CAD")
  STRING_TEST("en-US-u-cu-foo", "FOO")
  STRING_TEST("en-US-u-cu-fo", "-1")
  STRING_TEST("en-US-u-cu-foobar", "-1")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getCurrency) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCurrency(test->input, result, status, false);

  cr_assert(eq(i8, ecma402_hasError(status), 0),
            "Error encountered for locale %s: %s", test->input,
            status->errorMessage);

  if (strcmp(test->expected, "-1") == 0) {
    cr_assert(eq(i8, resultLength, -1),
              "Unexpected length returned for locale %s", test->input);
  } else {
    cr_assert(eq(str, result, test->expected),
              "Expected locale \"%s\" currency of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_assert(eq(i8, resultLength, strlen(test->expected)),
              "Expected length %d for locale currency \"%s\"; got %d instead "
              "for locale \"%s\"",
              strlen(test->expected), test->expected, resultLength,
              test->input);
  }

  free(result);
}

Test(TEST_SUITE, getCurrencyReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCurrency(NULL, result, status, false);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}
