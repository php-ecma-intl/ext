#include "src/ecma402/collation.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Collation

Test(TEST_SUITE, getAvailableCanonicalCollations) {
  const char **collations;
  int collationsLength;

  collations = malloc(sizeof(char *) * COLLATION_CAPACITY);
  collationsLength = getAvailableCanonicalCollations(collations);

  cr_expect(gt(int, collationsLength, 0));

  const char *previous = "";
  for (int i = 0; i < collationsLength; i++) {
    // According to ECMA-402, section 10.2.3, "the values 'standard' and
    // 'search' must not be used as elements in any [collation] list."
    cr_expect(ne(str, (char *)collations[i], COLLATION_SEARCH));
    cr_expect(ne(str, (char *)collations[i], COLLATION_STANDARD));

    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(collations[i], previous), 0));

    previous = collations[i];
  }

  free(collations);
}
