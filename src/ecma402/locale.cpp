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

#include "./locale.h"

#include "language_tag.h"
#include "util.h"

#include <cstring>
#include <unicode/locid.h>

#define FREE_PROPERTY(property)                                                \
  do {                                                                         \
    if (locale->property != nullptr) {                                         \
      free(locale->property);                                                  \
      locale->property = nullptr;                                              \
    }                                                                          \
  } while (0)

#define INIT_PROPERTY(id, property, capacity, method)                          \
  do {                                                                         \
    char *property = (char *)malloc(sizeof(char) * capacity);                  \
    int const len_##property = ecma402_##method(id, property, locale->status); \
    if (ecma402_hasError(locale->status)) {                                    \
      free(property);                                                          \
      return locale;                                                           \
    }                                                                          \
    if (len_##property >= 0) {                                                 \
      locale->property = strdup(property);                                     \
    }                                                                          \
    free(property);                                                            \
  } while (0)

namespace {

int getLocaleCode(const char *localeId, char *returnValue, const char *codeType,
                  int (*callback)(const char *, char *, int, UErrorCode *),
                  int capacity, ecma402_errorStatus *status);
int getKeywordValue(const char *keyword, const char *localeId,
                    char *returnValue, ecma402_errorStatus *status);

} // namespace

int ecma402_canonicalizeLocaleList(const char **locales, int localesLength,
                                   char **canonicalized,
                                   ecma402_errorStatus *status) {
  int i, canonicalizedLength = 0;

  for (i = 0; i < localesLength; i++) {
    char *unicodeLocaleId;
    unicodeLocaleId = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
    int const unicodeLocaleIdLength = ecma402_canonicalizeUnicodeLocaleId(
        locales[i], unicodeLocaleId, status);

    if (ecma402_hasError(status)) {
      free(unicodeLocaleId);

      return 0;
    }

    if (unicodeLocaleId != nullptr) {
      if (unicodeLocaleIdLength > 0) {
        canonicalized[canonicalizedLength] =
            (char *)malloc(unicodeLocaleIdLength + 1);
        memcpy((void *)canonicalized[canonicalizedLength], unicodeLocaleId,
               unicodeLocaleIdLength + 1);
        canonicalizedLength++;
      }
      free(unicodeLocaleId);
    }
  }

  return ecma402_removeDuplicates(canonicalized, canonicalizedLength, nullptr);
}

int ecma402_canonicalizeUnicodeLocaleId(const char *localeId,
                                        char *canonicalized,
                                        ecma402_errorStatus *status) {
  icu::Locale canonicalLocale;
  UErrorCode icuStatus = U_ZERO_ERROR;
  UBool const strict = 1;
  char *unicodeLocaleId;

  if (localeId == nullptr) {
    return -1;
  }

  if (!ecma402_isStructurallyValidLanguageTag(localeId)) {
    ecma402_ecmaError(status, STRUCTURALLY_INVALID_LOCALE_ID,
                      "Invalid language tag \"%s\"", localeId);
    return -1;
  }

  canonicalLocale = icu::Locale::createCanonical(localeId);
  if (canonicalLocale == nullptr) {
    ecma402_ecmaError(status, CANNOT_CREATE_LOCALE_ID,
                      "Invalid language tag \"%s\"", localeId);
    return -1;
  }

  std::string const locale =
      canonicalLocale.toLanguageTag<std::string>(icuStatus);
  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    ecma402_icuError(status, icuStatus, "Invalid language tag \"%s\"",
                     localeId);
    return -1;
  }

  // If the input localeId is not "und," but we got "und," then return 0.
  if (strcasecmp(locale.c_str(), UNDETERMINED_LANGUAGE) == 0 &&
      strcasecmp(localeId, UNDETERMINED_LANGUAGE) != 0) {
    ecma402_ecmaError(status, UNDEFINED_LOCALE_ID,
                      "Invalid language tag \"%s\"", localeId);
    return -1;
  }

  // This additional conversion step forces tags like "en-latn-us-co-foo" and
  // "de-de_euro" to result in failures, which is the desired result.
  unicodeLocaleId = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  int const length =
      uloc_toLanguageTag(locale.c_str(), unicodeLocaleId,
                         ULOC_FULLNAME_CAPACITY, strict, &icuStatus);

  if (U_FAILURE(icuStatus) != U_ZERO_ERROR || strlen(unicodeLocaleId) == 0 ||
      unicodeLocaleId == nullptr) {
    if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
      ecma402_icuError(status, icuStatus, "Invalid language tag \"%s\"",
                       localeId);
    } else {
      ecma402_ecmaError(status, INVALID_LOCALE_ID,
                        "Invalid language tag \"%s\"", localeId);
    }

    if (unicodeLocaleId != nullptr) {
      free(unicodeLocaleId);
    }

    return -1;
  }

  memcpy(canonicalized, unicodeLocaleId, length + 1);
  free(unicodeLocaleId);

  return length;
}

void ecma402_freeLocale(ecma402_locale *locale) {
  if (locale == nullptr) {
    return;
  }

  FREE_PROPERTY(baseName);
  FREE_PROPERTY(calendar);
  FREE_PROPERTY(canonical);
  FREE_PROPERTY(caseFirst);
  FREE_PROPERTY(collation);
  FREE_PROPERTY(hourCycle);
  FREE_PROPERTY(language);
  FREE_PROPERTY(numberingSystem);
  locale->numeric = false;
  FREE_PROPERTY(original);
  FREE_PROPERTY(region);
  FREE_PROPERTY(script);
  ecma402_freeErrorStatus(locale->status);
  free(locale);
}

int ecma402_getBaseName(const char *localeId, char *baseName,
                        ecma402_errorStatus *status) {
  char *icuBaseName, *bcp47BaseName;
  UErrorCode icuStatus = U_ZERO_ERROR;
  int icuBaseNameLength, bcp47BaseNameLength;

  icuBaseName = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  icuBaseNameLength =
      getLocaleCode(localeId, icuBaseName, "base name", uloc_getBaseName,
                    ULOC_FULLNAME_CAPACITY, status);

  if (icuBaseNameLength < 1) {
    free(icuBaseName);
    return icuBaseNameLength;
  }

  bcp47BaseName = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  bcp47BaseNameLength = uloc_toLanguageTag(
      icuBaseName, bcp47BaseName, ULOC_FULLNAME_CAPACITY, 1, &icuStatus);
  free(icuBaseName);

  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    free(bcp47BaseName);
    ecma402_icuError(status, icuStatus,
                     "Unable to get BCP 47 base name from language tag \"%s\"",
                     localeId);

    return -1;
  }

  strcpy(baseName, bcp47BaseName);
  free(bcp47BaseName);

  return bcp47BaseNameLength;
}

int ecma402_getCalendar(const char *localeId, char *calendar,
                        ecma402_errorStatus *status) {
  return getKeywordValue(ICU_KEYWORD_CALENDAR, localeId, calendar, status);
}

int ecma402_getCaseFirst(const char *localeId, char *caseFirst,
                         ecma402_errorStatus *status) {
  return getKeywordValue(ICU_KEYWORD_CASE_FIRST, localeId, caseFirst, status);
}

int ecma402_getCollation(const char *localeId, char *collation,
                         ecma402_errorStatus *status) {
  return getKeywordValue(ICU_KEYWORD_COLLATION, localeId, collation, status);
}

int ecma402_getHourCycle(const char *localeId, char *hourCycle,
                         ecma402_errorStatus *status) {
  return getKeywordValue(ICU_KEYWORD_HOUR_CYCLE, localeId, hourCycle, status);
}

int ecma402_getLanguage(const char *localeId, char *language,
                        ecma402_errorStatus *status) {
  return getLocaleCode(localeId, language, "language", uloc_getLanguage,
                       ULOC_LANG_CAPACITY, status);
}

int ecma402_getNumberingSystem(const char *localeId, char *numberingSystem,
                               ecma402_errorStatus *status) {
  return getKeywordValue(ICU_KEYWORD_NUMBERING_SYSTEM, localeId,
                         numberingSystem, status);
}

int ecma402_getRegion(const char *localeId, char *region,
                      ecma402_errorStatus *status) {
  return getLocaleCode(localeId, region, "region", uloc_getCountry,
                       ULOC_COUNTRY_CAPACITY, status);
}

int ecma402_getScript(const char *localeId, char *script,
                      ecma402_errorStatus *status) {
  return getLocaleCode(localeId, script, "script", uloc_getScript,
                       ULOC_SCRIPT_CAPACITY, status);
}

ecma402_locale *ecma402_initEmptyLocale(void) {
  ecma402_locale *locale;

  locale = (struct ecma402_locale *)malloc(sizeof(ecma402_locale));

  if (locale == nullptr) {
    return nullptr;
  }

  locale->baseName = nullptr;
  locale->calendar = nullptr;
  locale->canonical = nullptr;
  locale->caseFirst = nullptr;
  locale->collation = nullptr;
  locale->hourCycle = nullptr;
  locale->language = nullptr;
  locale->numberingSystem = nullptr;
  locale->numeric = false;
  locale->original = nullptr;
  locale->region = nullptr;
  locale->script = nullptr;
  locale->status = ecma402_initErrorStatus();

  return locale;
}

ecma402_locale *ecma402_initLocale(const char *localeId) {
  ecma402_locale *locale;

  if (localeId == nullptr) {
    return nullptr;
  }

  locale = ecma402_initEmptyLocale();
  if (locale == nullptr) {
    return nullptr;
  }

  locale->original = strdup(localeId);

  INIT_PROPERTY(localeId, baseName, ULOC_FULLNAME_CAPACITY, getBaseName);
  INIT_PROPERTY(localeId, calendar, ULOC_KEYWORDS_CAPACITY, getCalendar);
  INIT_PROPERTY(localeId, canonical, ULOC_FULLNAME_CAPACITY,
                canonicalizeUnicodeLocaleId);
  INIT_PROPERTY(localeId, caseFirst, ULOC_KEYWORDS_CAPACITY, getCaseFirst);
  INIT_PROPERTY(localeId, collation, ULOC_KEYWORDS_CAPACITY, getCollation);
  INIT_PROPERTY(localeId, hourCycle, ULOC_KEYWORDS_CAPACITY, getHourCycle);
  INIT_PROPERTY(localeId, language, ULOC_LANG_CAPACITY, getLanguage);
  INIT_PROPERTY(localeId, numberingSystem, ULOC_KEYWORDS_CAPACITY,
                getNumberingSystem);
  INIT_PROPERTY(localeId, region, ULOC_COUNTRY_CAPACITY, getRegion);
  INIT_PROPERTY(localeId, script, ULOC_SCRIPT_CAPACITY, getScript);

  locale->numeric = ecma402_isNumeric(localeId, locale->status);

  return locale;
}

bool ecma402_isNumeric(const char *localeId, ecma402_errorStatus *status) {
  char *numeric;
  int length;
  bool isNumeric = false;

  numeric = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  length = getKeywordValue(ICU_KEYWORD_NUMERIC, localeId, numeric, status);

  if (length > 0 && strcmp(numeric, "yes") == 0) {
    isNumeric = true;
  }

  free(numeric);

  return isNumeric;
}

namespace {

int getLocaleCode(const char *localeId, char *returnValue, const char *codeType,
                  int (*callback)(const char *, char *, int, UErrorCode *),
                  int capacity, ecma402_errorStatus *status) {
  char *canonicalized, *icuValue;
  UErrorCode icuStatus = U_ZERO_ERROR;
  int icuValueLength;

  if (localeId == nullptr) {
    return -1;
  }

  canonicalized = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  ecma402_canonicalizeUnicodeLocaleId(localeId, canonicalized, status);

  if (ecma402_hasError(status)) {
    free(canonicalized);
    return -1;
  }

  icuValue = (char *)malloc(sizeof(char) * capacity);
  icuValueLength = (*callback)(canonicalized, icuValue, capacity, &icuStatus);
  free(canonicalized);

  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    free(icuValue);
    ecma402_icuError(status, icuStatus,
                     "Unable to get %s from language tag \"%s\"", codeType,
                     localeId);
    return -1;
  }

  if (strcmp(icuValue, "") == 0 ||
      strcmp(icuValue, UNDETERMINED_LANGUAGE) == 0) {
    free(icuValue);
    return -1;
  }

  memcpy(returnValue, icuValue, icuValueLength + 1);
  free(icuValue);

  return icuValueLength;
}

int getKeywordValue(const char *keyword, const char *localeId,
                    char *returnValue, ecma402_errorStatus *status) {
  char *canonicalized, *icuValue;
  const char *bcp47Value;
  UErrorCode icuStatus = U_ZERO_ERROR;

  if (localeId == nullptr) {
    return -1;
  }

  canonicalized = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  ecma402_canonicalizeUnicodeLocaleId(localeId, canonicalized, status);

  if (ecma402_hasError(status)) {
    free(canonicalized);

    return -1;
  }

  icuValue = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  uloc_getKeywordValue(canonicalized, keyword, icuValue, ULOC_KEYWORDS_CAPACITY,
                       &icuStatus);
  free(canonicalized);

  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    free(icuValue);
    ecma402_icuError(status, icuStatus,
                     "Unable to get keyword %s from language tag \"%s\"",
                     keyword, localeId);
    return -1;
  }

  if (strcmp(keyword, ICU_KEYWORD_NUMERIC) == 0 &&
      strcmp(icuValue, "yes") == 0) {
    strcpy(returnValue, "yes");
    free(icuValue);
    return 3;
  }

  bcp47Value = uloc_toUnicodeLocaleType(keyword, icuValue);

  if (bcp47Value == nullptr) {
    free(icuValue);
    return -1;
  }

  const size_t bcp47Length = strlen(bcp47Value);
  strcpy(returnValue, bcp47Value);
  free(icuValue);

  return bcp47Length;
}

} // namespace
