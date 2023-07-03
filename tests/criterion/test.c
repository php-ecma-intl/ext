#include "test.h"

int addStringTest(stringTestParams *tests, int index, const char *input,
                  const char *expected) {
  if (input == NULL) {
    tests[index].input = NULL;
  } else {
    tests[index].input = testStrDup(input);
  }

  if (expected == NULL) {
    tests[index].expected = NULL;
  } else {
    tests[index].expected = testStrDup(expected);
  }

  return ++index;
}

void freeStringTestParams(struct criterion_test_params *criterionParams) {
  stringTestParams *params = (stringTestParams *)criterionParams->params;

  for (size_t i = 0; i < criterionParams->length; ++i) {
    if (params[i].input) {
      cr_free(params[i].input);
    }

    if (params[i].expected) {
      cr_free(params[i].expected);
    }
  }

  cr_free(params);
}

char *testStrDup(const char *str) {
  char *ptr = cr_malloc(sizeof(char) + (strlen(str) + 1));

  if (ptr) {
    strcpy(ptr, str);
  }

  return ptr;
}

void testFreeStrings(struct criterion_test_params *criterionParams) {
  char **strings = (char **)criterionParams->params;

  for (size_t i = 0; i < criterionParams->length; ++i) {
    cr_free(strings[i]);
  }

  cr_free(strings);
}
