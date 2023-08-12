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

Test(TEST_SUITE, currenciesOfLocaleReturnsPreferredCollation) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale("en-US-u-cu-uss", values);

  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "USS"));

  free(values);
}

Test(TEST_SUITE, currenciesOfLocaleReturnsNoCollationsForInvalidLocaleId) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale("foobar-baz", values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
}

Test(TEST_SUITE, currenciesOfLocaleReturnsExpectedCollations) {
  const char **values;
  int valuesLength;

  // "en-US" has currencies of ["USD", "USN"]
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale("en-US", values);
  cr_assert(eq(int, valuesLength, 2));
  cr_expect(eq(str, (char *)values[0], "USD"));
  cr_expect(eq(str, (char *)values[1], "USN"));
  free(values);

  // "en-GB" has currencies of ["GBP"]
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale("en-GB", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "GBP"));
  free(values);

  // "de-DE" has currencies of ["EUR"]
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale("de-DE", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "EUR"));
  free(values);

  // "fr-CA" has currencies of ["CAD"]
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_CURRENCY_CAPACITY);
  valuesLength = ecma402_currenciesOfLocale("fr-CA", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "CAD"));
  free(values);
}
