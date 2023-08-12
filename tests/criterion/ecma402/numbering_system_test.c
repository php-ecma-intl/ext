#include "../test.h"

#include "ecma402/numbering_system.h"

#define TEST_SUITE ecma402NumberingSystem

Test(TEST_SUITE, availableCanonicalNumberingSystemsIsSorted) {
  const char **numberingSystems;
  int numberingSystemsLength;

  numberingSystems = malloc(sizeof(char *) * ECMA402_NUMBERING_SYSTEM_CAPACITY);
  numberingSystemsLength =
      ecma402_availableCanonicalNumberingSystems(numberingSystems);

  cr_expect(gt(int, numberingSystemsLength, 0));

  const char *previous = "";
  for (int i = 0; i < numberingSystemsLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(numberingSystems[i], previous), 0));

    previous = numberingSystems[i];
  }

  free(numberingSystems);
}

Test(TEST_SUITE, numberingSystemsOfLocaleReturnsPreferredNumberingSystem) {
  const char **values;
  int valuesLength;

  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
  valuesLength = ecma402_numberingSystemsOfLocale("en-US-u-nu-arab", values);

  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "arab"));

  free(values);
}

Test(TEST_SUITE,
     numberingSystemsOfLocaleReturnsNoNumberingSystemsForInvalidLocaleId) {
  const char **values;
  int valuesLength;

  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
  valuesLength = ecma402_numberingSystemsOfLocale("foobar-baz", values);

  cr_assert(eq(int, valuesLength, 0));

  free(values);
}

Test(TEST_SUITE, numberingSystemsOfLocaleReturnsExpectedNumberingSystems) {
  const char **values;
  int valuesLength;

  // "en-US" has numbering systems of ["latn"]
  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
  valuesLength = ecma402_numberingSystemsOfLocale("en-US", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "latn"));
  free(values);

  // "fa" has numbering systems of ["arabext"]
  values = (const char **)malloc(sizeof(char *) *
                                 ECMA402_LOCALE_NUMBERING_SYSTEM_CAPACITY);
  valuesLength = ecma402_numberingSystemsOfLocale("fa", values);
  cr_assert(eq(int, valuesLength, 1));
  cr_expect(eq(str, (char *)values[0], "arabext"));
  free(values);
}
