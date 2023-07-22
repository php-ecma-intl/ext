#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402Locale

Test(TEST_SUITE, canonicalizeLocaleIdReturnsZeroForNullPointer) {
  char *result;
  int resultLength;

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_canonicalizeUnicodeLocaleId(NULL, result, NULL);

  cr_expect(zero(i8, resultLength));

  free(result);
}

ParameterizedTestParameters(TEST_SUITE,
                            canonicalizeLocaleIdReturnsZeroForFailures) {
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
                  canonicalizeLocaleIdReturnsZeroForFailures) {
  char *result;
  int resultLength;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_canonicalizeUnicodeLocaleId(*test, result, status);

  cr_expect(zero(i8, resultLength));
  cr_expect(eq(i8, ecma402_hasError(status), 1));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, canonicalizeLocaleIdHasErrorForStructurallyInvalidLocaleId) {
  char *result;
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  ecma402_canonicalizeUnicodeLocaleId("en_US_POSIX", result, status);

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

  cr_assert(
      eq(str, result, test->expected),
      "Expected locale \"%s\" to canonicalize to \"%s\"; got \"%s\" instead",
      test->input, test->expected, result);
  cr_assert(eq(i8, resultLength, strlen(test->expected)));

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
  STRING_TEST("und", "und")
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

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_getBaseName(test->input, result, NULL);

  cr_assert(eq(str, result, test->expected),
            "Expected locale \"%s\" base name of \"%s\"; got \"%s\" instead",
            test->input, test->expected, result);
  cr_assert(eq(i8, resultLength, strlen(test->expected)));

  free(result);
}

Test(TEST_SUITE, getBaseNameHasErrorForStructurallyInvalidLocaleId) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_getBaseName("en_US_POSIX", result, status);

  cr_expect(eq(i8, resultLength, 0));
  cr_expect(eq(i8, ecma402_hasError(status), 1));
  cr_expect(eq(i16, status->ecma, STRUCTURALLY_INVALID_LOCALE_ID));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
  cr_expect(
      eq(str, status->errorMessage, "Invalid language tag \"en_US_POSIX\""));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, getBaseNameReturnsZeroForNullPointer) {
  char *result;
  ecma402_errorStatus *status;
  int resultLength;

  status = ecma402_initErrorStatus();

  result = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  resultLength = ecma402_getBaseName(NULL, result, status);

  cr_expect(eq(i8, resultLength, 0));
  cr_expect(eq(i8, ecma402_hasError(status), 0));

  free(result);
  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, initEmptyLocale) {
  ecma402_locale *locale = ecma402_initEmptyLocale();

  cr_expect(eq(ptr, locale->baseName, NULL));
  cr_expect(eq(ptr, locale->canonical, NULL));
  cr_expect(eq(ptr, locale->original, NULL));
  cr_expect(eq(i8, ecma402_hasError(locale->status), 0));

  ecma402_freeLocale(locale);
}

Test(TEST_SUITE, initLocale) {
  ecma402_locale *locale = ecma402_initLocale(
      "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn");

  cr_expect(eq(str, locale->baseName, "de-Latn-DE"));
  cr_expect(
      eq(str, locale->canonical,
         "de-Latn-DE-u-ca-gregory-co-phonebk-hc-h23-kf-kn-false-nu-latn"));
  cr_expect(
      eq(str, locale->original,
         "de-latn-de-u-ca-gregory-co-phonebk-hc-h23-kf-true-kn-false-nu-latn"));
  cr_expect(eq(i8, ecma402_hasError(locale->status), 0));

  ecma402_freeLocale(locale);
}

Test(TEST_SUITE, initLocaleWithNullPointer) {
  ecma402_locale *locale = ecma402_initLocale(NULL);

  cr_expect(eq(ptr, locale, NULL));

  ecma402_freeLocale(locale);
}
