/*
   +----------------------------------------------------------------------+
   | ecma_intl extension for PHP                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Ben Ramsey <ben@benramsey.com>                         |
   | This source file is subject to the MIT license that is bundled with  |
   | this package in the file LICENSE, and is available at the following  |
   | web address: https://opensource.org/license/mit/                     |
   +----------------------------------------------------------------------+
*/

#include "error.h"

#include <stdlib.h>

errorStatus *initErrorStatus(void) {
  errorStatus *status;

  status = (errorStatus *)malloc(sizeof(*status));
  if (!status) {
    return NULL;
  }

  status->ecma = ZERO_ERROR;
  status->errorMessage = NULL;
  status->fileName = NULL;
  status->icu = U_ZERO_ERROR;
  status->lineNumber = 0;

  return status;
}

void freeErrorStatus(errorStatus *errorStatus) {
  if (errorStatus) {
    free(errorStatus);
  }
}

bool hasError(errorStatus *status) {
  if (!status) {
    return false;
  }

  return status->ecma != ZERO_ERROR;
}
