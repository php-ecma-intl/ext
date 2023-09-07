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

#include "error.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_BUFFER_SIZE 256

static void storeError(ecma402_errorStatus *status, const char *format, va_list vargs);

ecma402_errorStatus *ecma402_initErrorStatus(void)
{
	ecma402_errorStatus *status;

	status = (ecma402_errorStatus *)malloc(sizeof(*status));
	if (!status) {
		return NULL;
	}

	status->ecma = ZERO_ERROR;
	status->icu = U_ZERO_ERROR;
	status->errorMessage = (char *)malloc(sizeof(char) * MESSAGE_BUFFER_SIZE);

	return status;
}

void ecma402_freeErrorStatus(ecma402_errorStatus *status)
{
	if (status->errorMessage) {
		free(status->errorMessage);
	}

	free(status);
}

bool ecma402_hasError(ecma402_errorStatus *status)
{
	if (!status) {
		return false;
	}

	return status->ecma != ZERO_ERROR;
}

void ecma402_error(ecma402_errorStatus *status, const char *format, ...)
{
	va_list args;

	if (!status) {
		return;
	}

	va_start(args, format);
	storeError(status, format, args);
	va_end(args);
}

void ecma402_ecmaError(ecma402_errorStatus *status, ecma402_errorCode errorCode, const char *format, ...)
{
	va_list args;

	if (!status) {
		return;
	}

	status->ecma = errorCode;

	va_start(args, format);
	storeError(status, format, args);
	va_end(args);
}

void ecma402_icuError(ecma402_errorStatus *status, UErrorCode errorCode, const char *format, ...)
{
	va_list args;

	if (!status) {
		return;
	}

	status->icu = errorCode;
	status->ecma = ICU_ERROR;

	va_start(args, format);
	storeError(status, format, args);
	va_end(args);
}

static void storeError(ecma402_errorStatus *status, const char *format, va_list vargs)
{
	char *message;

	if (status->ecma == ZERO_ERROR) {
		status->ecma = GENERAL_ERROR;
	}

	message = (char *)malloc(sizeof(char) * MESSAGE_BUFFER_SIZE);
	vsprintf(message, format, vargs);

	status->errorMessage = strdup(message);

	if (message) {
		free(message);
	}
}
