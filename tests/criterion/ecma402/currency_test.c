#include "src/ecma402/currency.h"
#include "tests/criterion/test.h"

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
