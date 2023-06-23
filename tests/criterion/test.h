#ifndef ECMA_INTL_TEST_H
#define ECMA_INTL_TEST_H

#include <criterion/criterion.h>

#include <criterion/new/assert.h>
#include <criterion/parameterized.h>

#include "src/common.h"

char *testStrDup(const char *str);
void testFreeStrings(struct criterion_test_params *criterionParams);

#endif /* ECMA_INTL_TEST_H */
