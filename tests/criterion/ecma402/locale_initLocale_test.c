#include "../test.h"

#include "ecma402/locale.h"

#define TEST_SUITE ecma402LocaleInitLocale

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
