/**
 * Copyright (c) php-ecma-intl contributors.
 *
 * This source file is subject to the BSD-3-Clause license that is bundled with
 * this package in the file LICENSE and is available at the following web
 * address: https://opensource.org/license/bsd-3-clause/
 *
 * This source file may utilize copyrighted material from third-party open
 * source projects, the use of which is acknowledged in the NOTICE file bundled
 * with this package.
 */

#ifndef ECMA_INTL_ECMA402_ERROR_H
#define ECMA_INTL_ECMA402_ERROR_H

#include "src/common.h"

#include <stdbool.h>
#include <unicode/utypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Error status codes.
 */
typedef enum ecma402_errorCode {
	/**
	 * No error or warning.
	 */
	ZERO_ERROR = 0,

	/**
	 * Indicates the error is from ICU; check ecma402_errorStatus->icu.
	 */
	ICU_ERROR = 100,

	/**
	 * Application errors.
	 */
	GENERAL_ERROR = 200,
	CANNOT_CREATE_LOCALE_ID,
	INVALID_LOCALE_ID,
	UNDEFINED_LOCALE_ID,
	STRUCTURALLY_INVALID_LOCALE_ID,

} ecma402_errorCode;

/**
 * Error status indicator.
 */
typedef struct ecma402_errorStatus {
	/**
	 * Error status of this library, if any. This should be initialized to
	 * ZERO_ERROR.
	 */
	ecma402_errorCode ecma;

	/**
	 * Error status of the ICU library, if any. This should be initialized to
	 * U_ZERO_ERROR.
	 */
	UErrorCode icu;

	/**
	 * If applicable, an error message with more details.
	 */
	char *errorMessage;

} ecma402_errorStatus;

/**
 * Initializes an ecma402_errorStatus struct. This also allocates the struct on
 * the stack; free it using ecma402_freeErrorStatus().
 */
ecma402_errorStatus *ecma402_initErrorStatus(void);

/**
 * Frees an errorStatus initialized with ecma402_initErrorStatus().
 */
void ecma402_freeErrorStatus(ecma402_errorStatus *status);

/**
 * Checks whether the ecma402_errorStatus indicates a error.
 */
bool ecma402_hasError(ecma402_errorStatus *status);

/**
 * Saves general error information to the ecma402_errorStatus.
 */
void ecma402_error(ecma402_errorStatus *status, const char *format, ...);

/**
 * Saves ecma402_errorCode error information to the ecma402_errorStatus.
 */
void ecma402_ecmaError(ecma402_errorStatus *status, ecma402_errorCode errorCode, const char *format, ...);

/**
 * Saves ICU UErrorCode error information to the ecma402_errorStatus.
 */
void ecma402_icuError(ecma402_errorStatus *status, UErrorCode errorCode, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_ERROR_H */
