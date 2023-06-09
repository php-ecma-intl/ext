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

Test(TEST_SUITE, storesGeneralErrorInformation) {
  errorStatus *status;

  status = initErrorStatus();

  error(status, "A general error occurred", "general_error.c", 3);

  cr_assert(eq(int, hasError(status), true));
  cr_assert(eq(int, status->ecma, GENERAL_ERROR));
  cr_assert(eq(int, status->icu, U_ZERO_ERROR));
  cr_assert(eq(str, (char *)status->errorMessage, "A general error occurred"));
  cr_assert(eq(str, (char *)status->fileName, "general_error.c"));
  cr_assert(eq(int, status->lineNumber, 3));

  freeErrorStatus(status);
}

Test(TEST_SUITE, storesEcmaErrorInformation) {
  errorStatus *status;

  status = initErrorStatus();

  ecmaError(status, INVALID_CALENDAR, "error_test.c", 45, "An error occurred");

  cr_assert(eq(int, hasError(status), true));
  cr_assert(eq(int, status->ecma, INVALID_CALENDAR));
  cr_assert(eq(int, status->icu, U_ZERO_ERROR));
  cr_assert(eq(str, (char *)status->errorMessage, "An error occurred"));
  cr_assert(eq(str, (char *)status->fileName, "error_test.c"));
  cr_assert(eq(int, status->lineNumber, 45));

  freeErrorStatus(status);
}

Test(TEST_SUITE, storesIcuErrorInformation) {
  errorStatus *status;

  status = initErrorStatus();

  icuError(status, U_ILLEGAL_CHARACTER, "foobar", 213,
           "Another error occurred");

  cr_assert(eq(int, hasError(status), true));
  cr_assert(eq(int, status->ecma, ICU_ERROR));
  cr_assert(eq(int, status->icu, U_ILLEGAL_CHARACTER));
  cr_assert(eq(str, (char *)status->errorMessage, "Another error occurred"));
  cr_assert(eq(str, (char *)status->fileName, "foobar"));
  cr_assert(eq(int, status->lineNumber, 213));

  freeErrorStatus(status);
}

Test(TEST_SUITE, storesMemoryErrorInformation) {
  errorStatus *status;

  status = initErrorStatus();

  memoryError(status, "something.c", 42);

  cr_assert(eq(int, hasError(status), true));
  cr_assert(eq(int, status->ecma, MEMORY_ALLOCATION_ERROR));
  cr_assert(eq(int, status->icu, U_ZERO_ERROR));
  cr_assert_null(status->errorMessage);
  cr_assert(eq(str, (char *)status->fileName, "something.c"));
  cr_assert(eq(int, status->lineNumber, 42));

  freeErrorStatus(status);
}
