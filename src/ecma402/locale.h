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

#include "ecma402/error.h"

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
	 * The calendar (ca) property of the locale identifier, if available.
	 */
	char *calendar;

	/**
	 * The canonicalized locale identifier.
	 */
	char *canonical;

	/**
	 * The colcasefirst (kf) property of the locale identifier, if available.
	 */
	char *caseFirst;

	/**
	 * The collation (co) property of the locale identifier, if available.
	 */
	char *collation;

	/**
	 * The currency (cu) property of the locale identifier, if available.
	 */
	char *currency;

	/**
	 * The hours (hc) property of the locale identifier, if available.
	 */
	char *hourCycle;

	/**
	 * The language code property of the locale identifier, if available.
	 */
	char *language;

	/**
	 * The numbers (nu) property of the locale identifier, if available.
	 */
	char *numberingSystem;

	/**
	 * The colnumeric (kn) property of the locale identifier, if available.
	 */
	bool numeric;

	/**
	 * The original locale identifier, before canonicalization.
	 */
	char *original;

	/**
	 * The region code property of the locale identifier, if available.
	 */
	char *region;

	/**
	 * The script code property of the locale identifier, if available.
	 */
	char *script;

	/**
	 * Indicates whether there is an error with this locale. This property allows
	 * us to pass the error(s) back up for proper PHP exception throwing, etc.
	 */
	ecma402_errorStatus *status;

} ecma402_locale;

/**
 * Returns a new locale created from the provided locale combined with the given
 * options. A NULL option is ignored, retaining the value from the original
 * locale on the new locale, if present. This also allocates the new locale and
 * its properties on the stack; free it using ecma402_freeLocale(). The original
 * locale is unchanged.
 *
 * @param locale The original locale to use when setting options.
 * @param calendar The calendar (ca) type to set; use NULL to ignore.
 * @param caseFirst The colcasefirst (kf) type to set; use NULL to ignore.
 * @param collation The collation (co) type to set; use NULL to ignore.
 * @param currency The currency (cu) type to set; use NULL to ignore.
 * @param hourCycle The hours (hc) type to set; use NULL to ignore.
 * @param language The language type to set; use NULL to ignore.
 * @param numberingSystem The numbers (nu) type to set; use NULL to ignore.
 * @param numeric The numeric (kn) type (true/false) to set; use -1 to ignore.
 * @param region The region type to set; use NULL to ignore.
 * @param script The script type to set; use NULL to ignore.
 */
ecma402_locale *ecma402_applyLocaleOptions(ecma402_locale *locale, const char *calendar, const char *caseFirst,
                                           const char *collation, const char *currency, const char *hourCycle,
                                           const char *language, const char *numberingSystem, int numeric,
                                           const char *region, const char *script);

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
int ecma402_canonicalizeLocaleList(const char **locales, int localesLength, char **canonicalized,
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
 * @return The length of the string stored to the canonicalized buffer, or -1 if
 * the localeId cannot be canonicalized.
 */
int ecma402_canonicalizeUnicodeLocaleId(const char *localeId, char *canonicalized, ecma402_errorStatus *status);

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
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the baseName buffer, or -1 if the
 * localeId has no base name value.
 */
int ecma402_getBaseName(const char *localeId, char *baseName, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the value of the calendar (ca) keyword for the given locale ID.
 *
 * The calendar parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_KEYWORDS_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY)
 *
 * @param localeId The locale identifier to get the calendar of.
 * @param calendar A buffer in which to store the calendar name.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the calendar buffer, or -1 if the
 * localeId has no calendar value.
 */
int ecma402_getCalendar(const char *localeId, char *calendar, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the value of the colcasefirst (kf) keyword for the given locale ID.
 *
 * The caseFirst parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_KEYWORDS_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY)
 *
 * @param localeId The locale identifier to get the case first value of.
 * @param caseFirst A buffer in which to store the case first value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the caseFirst buffer, or -1 if the
 * localeId has no colcasefirst value.
 */
int ecma402_getCaseFirst(const char *localeId, char *caseFirst, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the value of the collation (co) keyword for the given locale ID.
 *
 * The collation parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_KEYWORDS_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY)
 *
 * @param localeId The locale identifier to get the collation value of.
 * @param collation A buffer in which to store the collation value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the collation buffer, or -1 if the
 * localeId has no collation value.
 */
int ecma402_getCollation(const char *localeId, char *collation, ecma402_errorStatus *status, bool isCanonicalized);

int ecma402_getCurrency(const char *localeId, char *currency, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the value of the hours (hc) keyword for the given locale ID.
 *
 * The hourCycle parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_KEYWORDS_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY)
 *
 * @param localeId The locale identifier to get the hours value of.
 * @param hourCycle A buffer in which to store the hours value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the hourCycle buffer, or -1 if the
 * localeId has no hours value.
 */
int ecma402_getHourCycle(const char *localeId, char *hourCycle, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the language value for the given locale ID.
 *
 * The language parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_LANG_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_LANG_CAPACITY)
 *
 * @param localeId The locale identifier to get the language value of.
 * @param language A buffer in which to store the language value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the language buffer, or -1 if the
 * localeId has no language value.
 */
int ecma402_getLanguage(const char *localeId, char *language, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the value of the numbers (nu) keyword for the given locale ID.
 *
 * The numberingSystem parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_KEYWORDS_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY)
 *
 * @param localeId The locale identifier to get the numbers value of.
 * @param numberingSystem A buffer in which to store the numbers value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the numberingSystem buffer, or -1
 * if the localeId has no numbers value.
 */
int ecma402_getNumberingSystem(const char *localeId, char *numberingSystem, ecma402_errorStatus *status,
                               bool isCanonicalized);

/**
 * Returns the region value for the given locale ID.
 *
 * The region parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_COUNTRY_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_COUNTRY_CAPACITY)
 *
 * @param localeId The locale identifier to get the region value of.
 * @param region A buffer in which to store the region value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the region buffer, or -1 if the
 * localeId has no region value.
 */
int ecma402_getRegion(const char *localeId, char *region, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the script value for the given locale ID.
 *
 * The script parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_SCRIPT_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_SCRIPT_CAPACITY)
 *
 * @param localeId The locale identifier to get the script value of.
 * @param script A buffer in which to store the script value.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the script buffer, or -1 if the
 * localeId has no script value.
 */
int ecma402_getScript(const char *localeId, char *script, ecma402_errorStatus *status, bool isCanonicalized);

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

/**
 * Returns true if the localeId has the colnumeric (kn) keyword with a value
 * that evaluates to true.
 *
 * @param localeId The locale identifier to get the colnumeric value of.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 */
bool ecma402_isNumeric(const char *localeId, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns a list of one or more canonical identifiers for the keyword in the
 * given locale identifier.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values.
 *
 * @param locale The locale to get keyword identifiers for.
 * @param keyword The keyword to get identifiers for (i.e., one of the
 * ICU_KEYWORD_* values).
 * @param values A pointer in which to store the resulting char array of
 * keyword identifier values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_keywordsOfLocale(ecma402_locale *locale, const char *keyword, const char **values);

/**
 * Returns the localeId with all likely sub tags added according to the
 * algorithm in Unicode Technical Standard #35.
 *
 * The maximized parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_FULLNAME_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY)
 *
 * @param localeId The locale identifier to maximize.
 * @param maximized A buffer in which to store the maximized locale ID.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the maximized buffer.
 */
int ecma402_maximize(const char *localeId, char *maximized, ecma402_errorStatus *status, bool isCanonicalized);

/**
 * Returns the localeId with sub tags removed according to the algorithm in
 * Unicode Technical Standard #35.
 *
 * The minimized parameter should already be allocated on the stack with
 * enough memory to store the buffer. Typically, this should use
 * ULOC_FULLNAME_CAPACITY. For example:
 *
 *     malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY)
 *
 * @param localeId The locale identifier to minimize.
 * @param minimized A buffer in which to store the minimized locale ID.
 * @param status A status object to pass error messages back to the caller.
 * @param isCanonicalized Whether localeId is already canonicalized. If not,
 * this function will call ecma402_canonicalizeUnicodeLocaleId on localeId.
 *
 * @return The length of the string stored to the minimized buffer.
 */
int ecma402_minimize(const char *localeId, char *minimized, ecma402_errorStatus *status, bool isCanonicalized);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_LOCALE_H */
