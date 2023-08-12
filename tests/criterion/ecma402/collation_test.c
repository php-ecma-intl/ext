#include "../test.h"

#include "ecma402/collation.h"

#define TEST_SUITE ecma402Collation

Test(TEST_SUITE, availableCanonicalCollationsDoesNotHaveSearchOrStandard) {
  const char **collations;
  int collationsLength;

  collations = malloc(sizeof(char *) * ECMA402_COLLATION_CAPACITY);
  collationsLength = ecma402_availableCanonicalCollations(collations);

  cr_expect(gt(int, collationsLength, 0));

  for (int i = 0; i < collationsLength; i++) {
    // According to ECMA-402, section 10.2.3, "the values 'standard' and
    // 'search' must not be used as elements in any [collation] list."
    cr_expect(ne(str, (char *)collations[i], ECMA402_COLLATION_SEARCH));
    cr_expect(ne(str, (char *)collations[i], ECMA402_COLLATION_STANDARD));
  }

  free(collations);
}

Test(TEST_SUITE, availableCanonicalCollationsIsSorted) {
  const char **collations;
  int collationsLength;

  collations = malloc(sizeof(char *) * ECMA402_COLLATION_CAPACITY);
  collationsLength = ecma402_availableCanonicalCollations(collations);

  cr_expect(gt(int, collationsLength, 0));

  const char *previous = "";
  for (int i = 0; i < collationsLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(collations[i], previous), 0));

    previous = collations[i];
  }

  free(collations);
}

Test(TEST_SUITE, availableCanonicalCollationsReturnsOnlyBcp47Values) {
  const char **collations;
  int collationsLength;

  collations = malloc(sizeof(char *) * ECMA402_COLLATION_CAPACITY);
  collationsLength = ecma402_availableCanonicalCollations(collations);

  cr_expect(gt(int, collationsLength, 0));

  for (int i = 0; i < collationsLength; i++) {
    cr_expect(ne(str, (char *)collations[i], "dictionary"));
    cr_expect(ne(str, (char *)collations[i], "gb2312han"));
    cr_expect(ne(str, (char *)collations[i], "phonebook"));
    cr_expect(ne(str, (char *)collations[i], "traditional"));
  }

  free(collations);
}

Test(TEST_SUITE, collationsOfLocaleReturnsPreferredCollation) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_COLLATION_CAPACITY);
  valuesLength = ecma402_collationsOfLocale("en-US-u-co-phonebk", values);

  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "phonebk"));

  free(values);
}

Test(TEST_SUITE, collationsOfLocaleReturnsNoCollationsForInvalidLocaleId) {
  const char **values;
  int valuesLength;

  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_COLLATION_CAPACITY);
  valuesLength = ecma402_collationsOfLocale("foobar-baz", values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
}

Test(TEST_SUITE, collationsOfLocaleReturnsExpectedCollations) {
  const char **values;
  int valuesLength;

  // "en-US" has collations of ["emoji", "eor"]
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_COLLATION_CAPACITY);
  valuesLength = ecma402_collationsOfLocale("en-US", values);
  cr_assert(eq(int, valuesLength, 2));
  cr_expect(eq(str, (char *)values[0], "emoji"));
  cr_expect(eq(str, (char *)values[1], "eor"));
  free(values);

  // "es-MX" has collations of ["trad", "emoji", "eor"]
  values =
      (const char **)malloc(sizeof(char *) * ECMA402_LOCALE_COLLATION_CAPACITY);
  valuesLength = ecma402_collationsOfLocale("es-MX", values);
  cr_assert(eq(int, valuesLength, 3));
  cr_expect(eq(str, (char *)values[0], "trad"));
  cr_expect(eq(str, (char *)values[1], "emoji"));
  cr_expect(eq(str, (char *)values[2], "eor"));
  free(values);
}
