#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402Locale

Test(TEST_SUITE, canonicalizeLocaleIdReturnsNegativeOneForNullPointer) {
  char *result;
  int resultLength;

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_canonicalizeUnicodeLocaleId(NULL, result, NULL);

  cr_expect(eq(i8, resultLength, -1));

  free(result);
}

ParameterizedTestParameters(TEST_SUITE,
                            canonicalizeLocaleIdReturnsNegativeOneForFailures) {
  const int length = 8;
  char *values[] = {
      "en-latn-us-co-foo",
      "de-de_euro",
      "1234",
      "invalid language tag",
      "1234.56",
      "i-test",
      "en_US_POSIX",
      "zh_CN_CA@collation=pinyin",
  };

  char **tests = cr_malloc(sizeof(char *) * length);

  for (int i = 0; i < length; i++) {
    tests[i] = testStrDup(values[i]);
  }

  return cr_make_param_array(const char *, tests, length, testFreeStrings);
}

ParameterizedTest(char **test, TEST_SUITE,
                  canonicalizeLocaleIdReturnsNegativeOneForFailures) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_canonicalizeUnicodeLocaleId(*test, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 1));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, canonicalizeLocaleIdHasErrorForStructurallyInvalidLocaleId) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength =
      ecma402_canonicalizeUnicodeLocaleId("en_US_POSIX", result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 1));
  cr_expect(eq(i16, status->ecma, STRUCTURALLY_INVALID_LOCALE_ID));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
  cr_expect(
      eq(str, status->errorMessage, "Invalid language tag \"en_US_POSIX\""));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, canonicalizeLocaleIdCanonicalizes) {
  START_STRING_TEST_PARAMS(22)
  STRING_TEST("de", "de")
  STRING_TEST("DE-de", "de-DE")
  STRING_TEST("de-DE", "de-DE")
  STRING_TEST("cmn", "zh")
  STRING_TEST("CMN-hANS", "zh-Hans")
  STRING_TEST("cmn-hans-cn", "zh-Hans-CN")
  STRING_TEST("es-419", "es-419")
  STRING_TEST("es-419-u-nu-latn", "es-419-u-nu-latn")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "zh-Hans-CN-t-ca-u-ca-x-t-u")
  STRING_TEST("de-gregory-u-ca-gregory", "de-gregory-u-ca-gregory")
  STRING_TEST("sgn-GR", "gss")
  STRING_TEST("ji", "yi")
  STRING_TEST("de-DD", "de-DE")
  STRING_TEST("in", "id")
  STRING_TEST("sr-cyrl-ekavsk", "sr-Cyrl-ekavsk")
  STRING_TEST("en-ca-newfound", "en-CA-newfound")
  STRING_TEST("sl-rozaj-biske-1994", "sl-1994-biske-rozaj")
  STRING_TEST("da-u-attr", "da-u-attr")
  STRING_TEST("da-u-attr-co-search", "da-u-attr-co-search")
  STRING_TEST("und", "und")
  STRING_TEST("en-US", "en-US")
  STRING_TEST("zh-xiang-u-nu-thai-x-0", "hsn-u-nu-thai-x-0")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE,
                  canonicalizeLocaleIdCanonicalizes) {
  char *result;
  int resultLength;

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_canonicalizeUnicodeLocaleId(test->input, result, NULL);

  cr_expect(
      eq(str, result, test->expected),
      "Expected locale \"%s\" to canonicalize to \"%s\"; got \"%s\" instead",
      test->input, test->expected, result);
  cr_expect(eq(i8, resultLength, strlen(test->expected)));

  free(result);
}

Test(TEST_SUITE, canonicalizeLocaleList) {
  const int testLength = 33;
  const char *test[] = {
      "de",
      "DE-de",
      "de-DE",
      "en-latn-us-co-foo",
      "cmn",
      "CMN-hANS",
      "cmn-hans-cn",
      "en_US_POSIX",
      "es-419",
      "de-de_euro",
      "es-419-u-nu-latn",
      "cmn-hans-cn-u-ca-t-ca-x-t-u",
      "de-gregory-u-ca-gregory",
      "sgn-GR",
      "ji",
      "de-DD",
      "invalid language tag",
      "in",
      "sr-cyrl-ekavsk",
      "en-ca-newfound",
      "sl-rozaj-biske-1994",
      "da-u-attr",
      "da-u-attr-co-search",
      "1234.56",
      "und",
      "en-US",
      "i-test",
      "art__lojban@x=0",
      "zh-xiang-u-nu-thai-x-0",
      "zh@collation=pinyin",
      "zh_CN@collation=pinyin",
      "1234",
      "zh_CN_CA@collation=pinyin",
  };

  const int expectedLength = 20;
  const char *expected[] = {
      "de",
      "de-DE",
      "zh",
      "zh-Hans",
      "zh-Hans-CN",
      "es-419",
      "es-419-u-nu-latn",
      "zh-Hans-CN-t-ca-u-ca-x-t-u",
      "de-gregory-u-ca-gregory",
      "gss",
      "yi",
      "id",
      "sr-Cyrl-ekavsk",
      "en-CA-newfound",
      "sl-1994-biske-rozaj",
      "da-u-attr",
      "da-u-attr-co-search",
      "und",
      "en-US",
      "hsn-u-nu-thai-x-0",
  };

  char **result;
  int i, resultLength;

  result = (char **)malloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_canonicalizeLocaleList(test, testLength, result, NULL);

  cr_assert(eq(i8, resultLength, expectedLength));

  for (i = 0; i < resultLength; i++) {
    cr_expect(eq(str, result[i], (char *)expected[i]));
    free(result[i]);
  }

  free(result);
}

Test(TEST_SUITE, canonicalizeLocaleListExitsEarlyForErrorStatus) {
  const int testLength = 33;
  const char *test[] = {
      "de",
      "DE-de",
      "de-DE",
      "en-latn-us-co-foo",
      "cmn",
      "CMN-hANS",
      "cmn-hans-cn",
      "en_US_POSIX",
      "es-419",
      "de-de_euro",
      "es-419-u-nu-latn",
      "cmn-hans-cn-u-ca-t-ca-x-t-u",
      "de-gregory-u-ca-gregory",
      "sgn-GR",
      "ji",
      "de-DD",
      "invalid language tag",
      "in",
      "sr-cyrl-ekavsk",
      "en-ca-newfound",
      "sl-rozaj-biske-1994",
      "da-u-attr",
      "da-u-attr-co-search",
      "1234.56",
      "und",
      "en-US",
      "i-test",
      "art__lojban@x=0",
      "zh-xiang-u-nu-thai-x-0",
      "zh@collation=pinyin",
      "zh_CN@collation=pinyin",
      "1234",
      "zh_CN_CA@collation=pinyin",
  };

  const int expectedLength = 2;
  const char *expected[] = {
      "de",
      "de-DE",
  };

  char **result;
  int i, resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char **)malloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);
  resultLength =
      ecma402_canonicalizeLocaleList(test, testLength, result, status);

  // We tell the caller that there are 0 values.
  cr_assert(eq(i8, resultLength, 0));

  // However, we did actually process the first two values, so just test that
  // our assumption is correct, though no one should rely on this behavior.
  for (i = 0; i < expectedLength; i++) {
    cr_expect(eq(str, result[i], (char *)expected[i]));
    free(result[i]);
  }

  // This is the first error encountered, and it's the error we expect.
  cr_expect(eq(i8, ecma402_hasError(status), 1));
  cr_expect(eq(i16, status->ecma, STRUCTURALLY_INVALID_LOCALE_ID));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
  cr_expect(eq(str, status->errorMessage,
               "Invalid language tag \"en-latn-us-co-foo\""));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getBaseName) {
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
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "de-Latn-DE")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "ja-Jpan-JP")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "fr-Latn-CA")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getBaseName) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_getBaseName(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" base name of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)),
              "Expected length %d for locale \"%s\"; got %d instead",
              strlen(test->expected), test->input, resultLength);
  }

  free(result);
}

Test(TEST_SUITE, getBaseNameHasErrorForStructurallyInvalidLocaleId) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_getBaseName("en_US_POSIX", result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 1));
  cr_expect(eq(i16, status->ecma, STRUCTURALLY_INVALID_LOCALE_ID));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
  cr_expect(
      eq(str, status->errorMessage, "Invalid language tag \"en_US_POSIX\""));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, getBaseNameReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_getBaseName(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, initEmptyLocale) {
  ecma402_locale *locale = ecma402_initEmptyLocale();

  cr_expect(eq(ptr, locale->baseName, NULL));
  cr_expect(eq(ptr, locale->calendar, NULL));
  cr_expect(eq(ptr, locale->canonical, NULL));
  cr_expect(eq(ptr, locale->caseFirst, NULL));
  cr_expect(eq(ptr, locale->collation, NULL));
  cr_expect(eq(ptr, locale->hourCycle, NULL));
  cr_expect(eq(ptr, locale->language, NULL));
  cr_expect(eq(ptr, locale->numberingSystem, NULL));
  cr_expect(eq(i8, locale->numeric, false));
  cr_expect(eq(ptr, locale->original, NULL));
  cr_expect(eq(ptr, locale->region, NULL));
  cr_expect(eq(ptr, locale->script, NULL));
  cr_expect(eq(i8, ecma402_hasError(locale->status), 0));

  ecma402_freeLocale(locale);
}

Test(TEST_SUITE, initLocale) {
  ecma402_locale *locale = ecma402_initLocale(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-true-nu-latn");

  cr_expect(eq(str, locale->baseName, "de-Latn-DE"));
  cr_expect(eq(str, locale->calendar, "gregory"));
  cr_expect(eq(str, locale->canonical,
               "de-Latn-DE-u-ca-gregory-co-phonebk-hc-h23-kf-kn-nu-latn"));
  cr_expect(eq(str, locale->caseFirst, "yes"));
  cr_expect(eq(str, locale->collation, "phonebk"));
  cr_expect(eq(str, locale->hourCycle, "h23"));
  cr_expect(eq(str, locale->language, "de"));
  cr_expect(eq(str, locale->numberingSystem, "latn"));
  cr_expect(eq(i8, locale->numeric, true));
  cr_expect(
      eq(str, locale->original,
         "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-true-nu-latn"));
  cr_expect(eq(str, locale->region, "DE"));
  cr_expect(eq(str, locale->script, "Latn"));
  cr_expect(eq(i8, ecma402_hasError(locale->status), 0));

  ecma402_freeLocale(locale);
}

Test(TEST_SUITE, initLocaleWithNullPointer) {
  ecma402_locale *locale = ecma402_initLocale(NULL);

  cr_expect(eq(ptr, locale, NULL));

  ecma402_freeLocale(locale);
}

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
  resultLength = ecma402_getCalendar(test->input, result, status);

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
  resultLength = ecma402_getCalendar(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getCaseFirst) {
  START_STRING_TEST_PARAMS(10)
  STRING_TEST("de", "-1")
  STRING_TEST("de-DE", "-1")
  STRING_TEST("cmn", "-1")
  STRING_TEST("cmn-hans-cn", "-1")
  STRING_TEST("es-419", "-1")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "-1")
  STRING_TEST("de-gregory-u-ca-gregory", "-1")
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "yes")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "false")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "yes")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getCaseFirst) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCaseFirst(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(
        eq(str, result, test->expected),
        "Expected locale \"%s\" colcasefirst of \"%s\"; got \"%s\" instead",
        test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getCaseFirstReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCaseFirst(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getCollation) {
  START_STRING_TEST_PARAMS(10)
  STRING_TEST("de", "-1")
  STRING_TEST("de-DE", "-1")
  STRING_TEST("cmn", "-1")
  STRING_TEST("cmn-hans-cn", "-1")
  STRING_TEST("es-419", "-1")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "-1")
  STRING_TEST("de-gregory-u-ca-gregory", "-1")
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "phonebk")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "search")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "standard")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getCollation) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCollation(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" collation of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getCollationReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getCollation(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getHourCycle) {
  START_STRING_TEST_PARAMS(10)
  STRING_TEST("de", "-1")
  STRING_TEST("de-DE", "-1")
  STRING_TEST("cmn", "-1")
  STRING_TEST("cmn-hans-cn", "-1")
  STRING_TEST("es-419", "-1")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "-1")
  STRING_TEST("de-gregory-u-ca-gregory", "-1")
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "h23")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "h24")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "h11")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getHourCycle) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getHourCycle(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" hours of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getHourCycleReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getHourCycle(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

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
  result = ecma402_isNumeric(test->input, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "false") == 0) {
    cr_expect(eq(i8, result, 0), "Expected false numeric for \"%s\"",
              test->input);
  } else {
    cr_expect(eq(i8, result, 1), "Expected true numeric for \"%s\"",
              test->input);
  }
}

ParameterizedTestParameters(TEST_SUITE, getNumberingSystem) {
  START_STRING_TEST_PARAMS(10)
  STRING_TEST("de", "-1")
  STRING_TEST("de-DE", "-1")
  STRING_TEST("cmn", "-1")
  STRING_TEST("cmn-hans-cn", "-1")
  STRING_TEST("es-419", "-1")
  STRING_TEST("cmn-hans-cn-u-ca-t-ca-x-t-u", "-1")
  STRING_TEST("de-gregory-u-ca-gregory", "-1")
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "latn")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "jpanfin")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "latn")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getNumberingSystem) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getNumberingSystem(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" numbers of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getNumberingSystemReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  resultLength = ecma402_getNumberingSystem(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getLanguage) {
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
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "de")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "ja")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "fr")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getLanguage) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_LANG_CAPACITY);
  resultLength = ecma402_getLanguage(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" language of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getLanguageReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_LANG_CAPACITY);
  resultLength = ecma402_getLanguage(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getScript) {
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
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "Latn")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin",
      "Jpan")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "Latn")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getScript) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_SCRIPT_CAPACITY);
  resultLength = ecma402_getScript(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" script of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getScriptReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_SCRIPT_CAPACITY);
  resultLength = ecma402_getScript(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

ParameterizedTestParameters(TEST_SUITE, getRegion) {
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
  STRING_TEST(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn",
      "DE")
  STRING_TEST(
      "ja-jpan-jp-u-ca-japanese-co-search-hc-h24-kf-false-kn-nu-jpanfin", "JP")
  STRING_TEST("fr-latn-ca-u-ca-gregory-co-standard-hc-h11-kf-kn-false-nu-latn",
              "CA")
  END_STRING_TEST_PARAMS;
}

ParameterizedTest(stringTestParams *test, TEST_SUITE, getRegion) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_COUNTRY_CAPACITY);
  resultLength = ecma402_getRegion(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected locale \"%s\" region of \"%s\"; got \"%s\" instead",
              test->input, test->expected, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

Test(TEST_SUITE, getRegionReturnsNegativeOneForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_COUNTRY_CAPACITY);
  resultLength = ecma402_getRegion(NULL, result, status);

  cr_expect(eq(i8, resultLength, -1));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, applyLocaleOptionsWillAllPopulatedOptions) {
  ecma402_locale *originalLocale, *newLocale;

  originalLocale = ecma402_initLocale(
      "en-Latn-US-u-ca-buddhist-kf-lower-co-phonebk-hc-h12-nu-arab-kn");
  newLocale =
      ecma402_applyLocaleOptions(originalLocale, "gregory", "upper", "emoji",
                                 "h23", "fr", "latn", false, "CA", "Some");

  cr_assert(newLocale != NULL);

  cr_expect(eq(str, newLocale->baseName, "fr-Some-CA"));
  cr_expect(eq(str, newLocale->calendar, "gregory"));
  cr_expect(eq(str, newLocale->caseFirst, "upper"));
  cr_expect(eq(str, newLocale->collation, "emoji"));
  cr_expect(eq(str, newLocale->hourCycle, "h23"));
  cr_expect(eq(str, newLocale->language, "fr"));
  cr_expect(eq(str, newLocale->numberingSystem, "latn"));
  cr_expect(eq(i8, newLocale->numeric, false));
  cr_expect(eq(str, newLocale->region, "CA"));
  cr_expect(eq(str, newLocale->script, "Some"));

  ecma402_freeLocale(newLocale);
  ecma402_freeLocale(originalLocale);
}

Test(TEST_SUITE, applyLocaleOptionsWithAllNullOptions) {
  ecma402_locale *originalLocale, *newLocale;

  originalLocale = ecma402_initLocale(
      "en-Latn-US-u-ca-buddhist-kf-lower-co-phonebk-hc-h12-nu-arab-kn");
  newLocale = ecma402_applyLocaleOptions(originalLocale, NULL, NULL, NULL, NULL,
                                         NULL, NULL, -1, NULL, NULL);

  cr_assert(newLocale != NULL);

  cr_expect(eq(str, newLocale->baseName, "en-Latn-US"));
  cr_expect(eq(str, newLocale->calendar, "buddhist"));
  cr_expect(eq(str, newLocale->caseFirst, "lower"));
  cr_expect(eq(str, newLocale->collation, "phonebk"));
  cr_expect(eq(str, newLocale->hourCycle, "h12"));
  cr_expect(eq(str, newLocale->language, "en"));
  cr_expect(eq(str, newLocale->numberingSystem, "arab"));
  cr_expect(eq(i8, newLocale->numeric, true));
  cr_expect(eq(str, newLocale->region, "US"));
  cr_expect(eq(str, newLocale->script, "Latn"));

  ecma402_freeLocale(newLocale);
  ecma402_freeLocale(originalLocale);
}

Test(TEST_SUITE, applyLocaleOptionsWithAllNullOptionsAndMinimalLocale) {
  ecma402_locale *originalLocale, *newLocale;

  originalLocale = ecma402_initLocale("en");
  newLocale = ecma402_applyLocaleOptions(originalLocale, NULL, NULL, NULL, NULL,
                                         NULL, NULL, -1, NULL, NULL);

  cr_assert(newLocale != NULL);

  cr_expect(eq(str, newLocale->baseName, "en"));
  cr_expect(eq(ptr, newLocale->calendar, NULL));
  cr_expect(eq(ptr, newLocale->caseFirst, NULL));
  cr_expect(eq(ptr, newLocale->collation, NULL));
  cr_expect(eq(ptr, newLocale->hourCycle, NULL));
  cr_expect(eq(str, newLocale->language, "en"));
  cr_expect(eq(ptr, newLocale->numberingSystem, NULL));
  cr_expect(eq(i8, newLocale->numeric, false));
  cr_expect(eq(ptr, newLocale->region, NULL));
  cr_expect(eq(ptr, newLocale->script, NULL));

  ecma402_freeLocale(newLocale);
  ecma402_freeLocale(originalLocale);
}

ParameterizedTestParameters(TEST_SUITE, maximize) {
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

ParameterizedTest(stringTestParams *test, TEST_SUITE, maximize) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_maximize(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected maximized value of \"%s\" for language tag \"%s\"; got "
              "\"%s\" instead",
              test->expected, test->input, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}

ParameterizedTestParameters(TEST_SUITE, minimize) {
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

ParameterizedTest(stringTestParams *test, TEST_SUITE, minimize) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_minimize(test->input, result, status);

  cr_assert(eq(i8, ecma402_hasError(status), 0));

  if (strcmp(test->expected, "-1") == 0) {
    cr_expect(eq(i8, resultLength, -1));
  } else {
    cr_expect(eq(str, result, test->expected),
              "Expected minimized value of \"%s\" for language tag \"%s\"; got "
              "\"%s\" instead",
              test->expected, test->input, result);
    cr_expect(eq(i8, resultLength, strlen(test->expected)));
  }

  free(result);
}
