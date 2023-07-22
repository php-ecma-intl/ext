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
 * A parsed locale including properties similar to the ECMA-402 Intl.Locale
 * object properties.
 *
 * @link https://tc39.es/ecma402/#sec-properties-of-intl-locale-prototype-object
 */
typedef struct ecma402_locale {
  /**
   * The full name of the canonicalized locale identifier, without keywords.
   */
  char *baseName;

  /**
   * The canonicalized locale identifier.
   */
  char *canonical;

  /**
   * The original locale identifier, before canonicalization.
   */
  char *original;

  /**
   * Indicates whether there is an error with this locale. This property allows
   * us to pass the error(s) back up for proper PHP exception throwing, etc.
   */
  ecma402_errorStatus *status;

} ecma402_locale;

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
 * Frees a locale initialized with initLocale().
 *
 * @param locale The locale to free.
 */
void ecma402_freeLocale(ecma402_locale *locale);

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

/**
 * Initializes an empty locale struct. This also allocates the struct on the
 * stack; free it using ecma402_freeLocale().
 */
ecma402_locale *ecma402_initEmptyLocale(void);

/**
 * Initializes a locale struct with the given locale identifier. This
 * also allocates the struct and its properties on the stack; free it using
 * ecma402_freeLocale().
 *
 * @param localeId The locale identifier, e.g., "en-US."
 */
ecma402_locale *ecma402_initLocale(const char *localeId);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_LOCALE_H */
