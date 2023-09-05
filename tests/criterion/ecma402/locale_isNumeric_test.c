#include "../test.h"

#include "ecma402/locale.h"

#define TEST_SUITE ecma402LocaleIsNumeric

ParameterizedTestParameters(TEST_SUITE, isNumeric) {
  START_STRING_TEST_PARAMS(10)
  STRING_TEST("de", "false")
  STRING_TEST("de-DE", "false")
  STRING_TEST("cmn", "false")
  STRING_TEST("cmn-hans-cn", "false")
  STRING_TEST("es-419", "false")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "false")
  STRING_TEST("de-gregory-u-ca-gregory", "false")
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "false")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "true")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-true-nu-latn",
              "true")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, isNumeric) {
  bool result;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();
  result = ecma402_isNumeric(test->input, status, false);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "false") == 0) {
    cr_expect(eq(i8, result, 0), "Expected false numeric for \"%s\"",
              test->input);
  } else {
    cr_expect(eq(i8, result, 1), "Expected true numeric for \"%s\"",
              test->input);
  }
}
