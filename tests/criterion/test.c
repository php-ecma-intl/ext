#include "test.h"

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
