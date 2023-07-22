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

#ifndef ECMA_INTL_ECMA402_LOCALE_H
#define ECMA_INTL_ECMA402_LOCALE_H

#include "common.h"

#include "error.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Canonicalizes a list of locales.
 *
 * The canonicalized parameter should already be allocated on the stack with
 * enough memory to store all the values. Typically, this should use
 * ULOC_FULLNAME_CAPACITY. For example:
 *
 *     malloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY)
 *
 * @param locales The list of locales to canonicalize.
 * @param localesLength The length of the list of locales.
 * @param canonicalized A pointer in which to store the resulting char array of
 * canonicalized locales.
 * @param status A status object to pass error messages back to the caller.
 *
 * @return The length of the canonicalized list.
 */
int ecma402_canonicalizeLocaleList(const char **locales, int localesLength,
                                   char **canonicalized,
                                   ecma402_errorStatus *status);

/**
 * Returns the Unicode canonicalized locale identifier form of the locale ID.
 *
 * The canonicalized parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_FULLNAME_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY)
 *
 * @link https://unicode-org.atlassian.net/browse/ICU-21506
 * @link https://tc39.es/ecma402/#sec-canonicalizeunicodelocaleid
 *
 * @param localeId The locale identifier to canonicalize.
 * @param canonicalized A buffer in which to store the canonicalized name.
 * @param status A status object to pass error messages back to the caller.
 *
 * @return The length of the string stored to the canonicalized buffer.
 */
int ecma402_canonicalizeUnicodeLocaleId(const char *localeId,
                                        char *canonicalized,
                                        ecma402_errorStatus *status);

/**
 * Returns the full name for the given locale ID, without keywords.
 *
 * The baseName parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_FULLNAME_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY)
 *
 * @param localeId The locale identifier to get the base name of.
 * @param baseName A buffer in which to store the base name.
 * @param status A status object to pass error messages back to the caller.
 *
 * @return The length of the string stored to the baseName buffer.
 */
int ecma402_getBaseName(const char *localeId, char *baseName,
                        ecma402_errorStatus *status);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_LOCALE_H */
