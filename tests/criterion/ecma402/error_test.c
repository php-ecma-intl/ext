#include "../test.h"

#include "ecma402/error.h"

#define TEST_SUITE ecma402Error

Test(TEST_SUITE, initializesErrorStatus) {
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  cr_expect(eq(i8, ecma402_hasError(status), false));
  cr_expect(eq(i16, status->ecma, ZERO_ERROR));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));

  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, storesGeneralErrorInformation) {
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  ecma402_error(status, "A %s %s occurred", "general", "error");

  cr_expect(eq(i8, ecma402_hasError(status), true));
  cr_expect(eq(i16, status->ecma, GENERAL_ERROR));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
  cr_expect(eq(str, (char *)status->errorMessage, "A general error occurred"));

  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, storesEcmaErrorInformation) {
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  ecma402_ecmaError(status, INVALID_LOCALE_ID, "An %s %s", "error", "occurred");

  cr_expect(eq(i8, ecma402_hasError(status), true));
  cr_expect(eq(i16, status->ecma, INVALID_LOCALE_ID));
  cr_expect(eq(i32, status->icu, U_ZERO_ERROR));
  cr_expect(eq(str, (char *)status->errorMessage, "An error occurred"));

  ecma402_freeErrorStatus(status);
}

Test(TEST_SUITE, storesIcuErrorInformation) {
  ecma402_errorStatus *status;

  status = ecma402_initErrorStatus();

  ecma402_icuError(status, U_ILLEGAL_CHARACTER, "%s %s %s", "Another", "error",
                   "occurred");

  cr_expect(eq(i8, ecma402_hasError(status), true));
  cr_expect(eq(i16, status->ecma, ICU_ERROR));
  cr_expect(eq(i32, status->icu, U_ILLEGAL_CHARACTER));
  cr_expect(eq(str, (char *)status->errorMessage, "Another error occurred"));

  ecma402_freeErrorStatus(status);
}
