#include "../test.h"

#include "ecma402/locale.h"

#include <unicode/uloc.h>

#define TEST_SUITE ecma402Locale

Test(TEST_SUITE, keywordsOfLocaleReturnsZeroForUnknownKeyword)
{
	ecma402_locale *locale = ecma402_initLocale("foobar");
	cr_expect(eq(int, ecma402_keywordsOfLocale(locale, "unknown", NULL), 0));
	ecma402_freeLocale(locale);
}

Test(TEST_SUITE, intlAvailableLocales) {
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
