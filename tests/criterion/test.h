#ifndef ECMA_INTL_TESTS_CRITERION_TEST_H
#define ECMA_INTL_TESTS_CRITERION_TEST_H

#include "common.h"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/parameterized.h>

#define START_STRING_TEST_PARAMS(testCount)                                    \
  stringTestParams *tests;                                                     \
  int index = 0;                                                               \
  tests = cr_malloc(testCount * sizeof(stringTestParams));

#define STRING_TEST(input, expected)                                           \
  index = addStringTest(tests, index, input, expected);

#define END_STRING_TEST_PARAMS                                                 \
  return cr_make_param_array(stringTestParams, tests, index,                   \
                             freeStringTestParams)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct stringTestParams stringTestParams;

struct stringTestParams {
  char *input;
  char *expected;
};

int addStringTest(stringTestParams *tests, int index, const char *input,
                  const char *expected);
void freeStringTestParams(struct criterion_test_params *criterionParams);
char *testStrDup(const char *str);
void testFreeStrings(struct criterion_test_params *criterionParams);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_TESTS_CRITERION_TEST_H */
