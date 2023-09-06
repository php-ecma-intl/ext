#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402Locale

Test(TEST_SUITE, keywordsOfLocaleReturnsZeroForUnknownKeyword) {
  ecma402_locale *locale = ecma402_initLocale("foobar");
  cr_expect(eq(int, ecma402_keywordsOfLocale(locale, "unknown", NULL), 0));
  ecma402_freeLocale(locale);
}
