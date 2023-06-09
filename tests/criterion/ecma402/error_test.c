#include "src/ecma402/error.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Error

Test(TEST_SUITE, initializesErrorStatus) {
  errorStatus *status;

  status = initErrorStatus();

  cr_assert(eq(int, hasError(status), false));
  cr_assert(eq(int, status->ecma, ZERO_ERROR));
  cr_assert_null(status->errorMessage);
  cr_assert_null(status->fileName);
  cr_assert(eq(int, status->icu, U_ZERO_ERROR));
  cr_assert(eq(int, status->lineNumber, 0));

  freeErrorStatus(status);
}
