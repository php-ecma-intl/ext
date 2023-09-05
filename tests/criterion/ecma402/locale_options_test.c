#include "../test.h"

#include "ecma402/locale.h"

#define TEST_SUITE ecma402LocaleOptions

Test(TEST_SUITE, applyLocaleOptionsWillAllPopulatedOptions) {
  ecma402_locale *originalLocale, *newLocale;

  originalLocale = ecma402_initLocale(
      "en-Latn-US-u-ca-buddhist-kf-lower-co-phonebk-hc-h12-nu-arab-kn-cu-eur");
  newLocale = ecma402_applyLocaleOptions(originalLocale, "gregory", "upper",
                                         "emoji", "cad", "h23", "fr", "latn",
                                         false, "CA", "Some");

  cr_assert(newLocale != NULL);

  cr_expect(eq(str, newLocale->baseName, "fr-Some-CA"));
  cr_expect(eq(str, newLocale->calendar, "gregory"));
  cr_expect(eq(str, newLocale->caseFirst, "upper"));
  cr_expect(eq(str, newLocale->collation, "emoji"));
  cr_expect(eq(str, newLocale->currency, "CAD"));
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
      "en-Latn-US-u-ca-buddhist-kf-lower-co-phonebk-hc-h12-nu-arab-kn-cu-eur");
  newLocale = ecma402_applyLocaleOptions(originalLocale, NULL, NULL, NULL, NULL,
                                         NULL, NULL, NULL, -1, NULL, NULL);

  cr_assert(newLocale != NULL);

  cr_expect(eq(str, newLocale->baseName, "en-Latn-US"));
  cr_expect(eq(str, newLocale->calendar, "buddhist"));
  cr_expect(eq(str, newLocale->caseFirst, "lower"));
  cr_expect(eq(str, newLocale->collation, "phonebk"));
  cr_expect(eq(str, newLocale->currency, "EUR"));
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
                                         NULL, NULL, NULL, -1, NULL, NULL);

  cr_assert(newLocale != NULL);

  cr_expect(eq(str, newLocale->baseName, "en"));
  cr_expect(eq(ptr, newLocale->calendar, NULL));
  cr_expect(eq(ptr, newLocale->caseFirst, NULL));
  cr_expect(eq(ptr, newLocale->collation, NULL));
  cr_expect(eq(ptr, newLocale->currency, NULL));
  cr_expect(eq(ptr, newLocale->hourCycle, NULL));
  cr_expect(eq(str, newLocale->language, "en"));
  cr_expect(eq(ptr, newLocale->numberingSystem, NULL));
  cr_expect(eq(i8, newLocale->numeric, false));
  cr_expect(eq(ptr, newLocale->region, NULL));
  cr_expect(eq(ptr, newLocale->script, NULL));

  ecma402_freeLocale(newLocale);
  ecma402_freeLocale(originalLocale);
}
