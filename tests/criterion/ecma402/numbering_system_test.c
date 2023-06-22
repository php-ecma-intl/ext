#include "tests/criterion/test.h"

#include "src/ecma402/numbering_system.h"

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
