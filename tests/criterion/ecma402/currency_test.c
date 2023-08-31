#include "../test.h"

#include "ecma402/currency.h"

#define TEST_SUITE ecma402Currency

Test(TEST_SUITE, availableCanonicalCurrenciesIsSorted) {
  const char **currencies;
  int currenciesLength;

  currencies = malloc(sizeof(char *) * ECMA402_CURRENCY_CAPACITY);
  currenciesLength = ecma402_availableCanonicalCurrencies(currencies);

  cr_expect(gt(int, currenciesLength, 0));

  const char *previous = "";
  for (int i = 0; i < currenciesLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(currencies[i], previous), 0));

    previous = currencies[i];
  }

  free(currencies);
}

Test(TEST_SUITE,
     currenciesOfLocaleReturnsAllCurrenciesRegardlessOfPreferredCurrency) {
  ecma402_locale *locale;
  const char **values;
  int valuesLength;

  locale = ecma402_initLocale("en-US-u-cu-uss");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);

  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "USS"));

  free(values);
  ecma402_freeLocale(locale);
}

Test(TEST_SUITE, currenciesOfLocaleReturnsNoCurrenciesForInvalidLocaleId) {
  ecma402_locale *locale;
  const char **values;
  int valuesLength;

  locale = ecma402_initLocale("foobar-baz");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
  ecma402_freeLocale(locale);
}

Test(TEST_SUITE, currenciesOfLocaleReturnsExpectedCurrencies) {
  ecma402_locale *locale;
  const char **values;
  int valuesLength;

  // "en-US" has currencies of ["USD", "USN"]
  locale = ecma402_initLocale("en-US");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);
  cr_assert(eq(int, valuesLength, 2));
  cr_expect(eq(str, (char *)values[0], "USD"));
  cr_expect(eq(str, (char *)values[1], "USN"));
  free(values);
  ecma402_freeLocale(locale);

  // "en-GB" has currencies of ["GBP"]
  locale = ecma402_initLocale("en-GB");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "GBP"));
  free(values);
  ecma402_freeLocale(locale);

  // "de-DE" has currencies of ["EUR"]
  locale = ecma402_initLocale("de-DE");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "EUR"));
  free(values);
  ecma402_freeLocale(locale);

  // "fr-CA" has currencies of ["CAD"]
  locale = ecma402_initLocale("fr-CA");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "CAD"));
  free(values);
  ecma402_freeLocale(locale);

  // "fr" has currencies of ["EUR"]
  locale = ecma402_initLocale("fr");
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale(locale, values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "EUR"));
  free(values);
  ecma402_freeLocale(locale);
}
