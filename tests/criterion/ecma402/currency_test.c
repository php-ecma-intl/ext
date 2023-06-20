#include "src/ecma402/currency.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Currency

Test(TEST_SUITE, getAvailableCanonicalCurrenciesIsSorted) {
  const char **currencies;
  int currenciesLength;

  currencies = malloc(sizeof(char *) * CURRENCY_CAPACITY);
  currenciesLength = getAvailableCanonicalCurrencies(currencies);

  cr_expect(gt(int, currenciesLength, 0));

  const char *previous = "";
  for (int i = 0; i < currenciesLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(currencies[i], previous), 0));

    previous = currencies[i];
  }

  free(currencies);
}
