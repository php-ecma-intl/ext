#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402LocaleGetCalendar

ParameterizedTestParameters(TEST_SUITE, getCalendar) {
  START_STRING_TEST_PARAMS(10)
  STRING_TEST("de", "-1")
  STRING_TEST("de-DE", "-1")
  STRING_TEST("cmn", "-1")
  STRING_TEST("cmn-hans-cn", "-1")
  STRING_TEST("es-419", "-1")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "yes")
  STRING_TEST("de-gregory-u-ca-gregory", "gregory")
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "gregory")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "japanese")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "gregory")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getCalendar) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCalendar(test->input, result, status, false);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" calendar of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getCalendarReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCalendar(NULL, result, status, false);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}