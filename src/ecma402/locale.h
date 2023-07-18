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
 * @param status An status object to pass error messages back to the caller.
 *
 * @return The length of the canonicalized list.
 */
int ecma402_canonicalizeLocaleList(const char **locales, int localesLength,
                                   char **canonicalized,
                                   ecma402_errorStatus *status);

/**
 * Returns the Unicode canonicalized locale identifier form of the locale ID.
 *
 * This method is necessary as a wrapper around the C++ method
 * icu::Locale::createCanonical() because uloc_canonicalize() does not map
 * aliased names. See ICU-21506 for more information.
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
 * @param status An status object to pass error messages back to the caller.
 *
 * @return The length of the string stored to the name buffer.
 */
int ecma402_canonicalizeUnicodeLocaleId(const char *localeId,
                                        char *canonicalized,
                                        ecma402_errorStatus *status);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_LOCALE_H */
