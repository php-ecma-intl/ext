#include "tests/criterion/test.h"

#define TEST_SUITE example

Test(TEST_SUITE, test) { cr_assert(strlen("") == 0); }
