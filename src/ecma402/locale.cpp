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
    ecma402_##method(id, property, locale->status);                            \
    if (ecma402_hasError(locale->status)) {                                    \
      free(property);                                                          \
      return locale;                                                           \
    }                                                                          \
    locale->property = property;                                               \
  } while (0)

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
    return 0;
  }

  if (!ecma402_isStructurallyValidLanguageTag(localeId)) {
    ecma402_ecmaError(status, STRUCTURALLY_INVALID_LOCALE_ID,
                      "Invalid language tag \"%s\"", localeId);

    return 0;
  }

  canonicalLocale = icu::Locale::createCanonical(localeId);
  if (canonicalLocale == nullptr) {
    ecma402_ecmaError(status, CANNOT_CREATE_LOCALE_ID,
                      "Invalid language tag \"%s\"", localeId);

    return 0;
  }

  std::string const locale =
      canonicalLocale.toLanguageTag<std::string>(icuStatus);
  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    ecma402_icuError(status, icuStatus, "Invalid language tag \"%s\"",
                     localeId);

    return 0;
  }

  // If the input localeId is not "und," but we got "und," then return 0.
  if (strcasecmp(locale.c_str(), UNDETERMINED_LANGUAGE) == 0 &&
      strcasecmp(localeId, UNDETERMINED_LANGUAGE) != 0) {
    ecma402_ecmaError(status, UNDEFINED_LOCALE_ID,
                      "Invalid language tag \"%s\"", localeId);

    return 0;
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

    return 0;
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
  FREE_PROPERTY(canonical);
  FREE_PROPERTY(original);
  ecma402_freeErrorStatus(locale->status);
  free(locale);
}

int ecma402_getBaseName(const char *localeId, char *baseName,
                        ecma402_errorStatus *status) {
  char *canonicalized, *icuBaseName, *bcp47BaseName;
  UErrorCode icuStatus = U_ZERO_ERROR;
  int canonicalizedLength;

  if (localeId == nullptr) {
    return 0;
  }

  canonicalized = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  canonicalizedLength =
      ecma402_canonicalizeUnicodeLocaleId(localeId, canonicalized, status);

  if (ecma402_hasError(status)) {
    free(canonicalized);

    return 0;
  }

  icuBaseName = (char *)malloc(sizeof(char) * (canonicalizedLength + 1));
  uloc_getBaseName(canonicalized, icuBaseName, canonicalizedLength + 1,
                   &icuStatus);
  free(canonicalized);

  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    free(icuBaseName);
    ecma402_icuError(status, icuStatus,
                     "Unable to get base name from language tag \"%s\"",
                     localeId);

    return 0;
  }

  bcp47BaseName = (char *)malloc(sizeof(char) * (canonicalizedLength + 1));
  int const length = uloc_toLanguageTag(icuBaseName, bcp47BaseName,
                                        canonicalizedLength + 1, 1, &icuStatus);
  free(icuBaseName);

  if (U_FAILURE(icuStatus) != U_ZERO_ERROR) {
    free(bcp47BaseName);
    ecma402_icuError(status, icuStatus,
                     "Unable to get BCP 47 base name from language tag \"%s\"",
                     localeId);

    return 0;
  }

  memcpy(baseName, bcp47BaseName, length + 1);
  free(bcp47BaseName);

  return length;
}

ecma402_locale *ecma402_initEmptyLocale(void) {
  ecma402_locale *locale;

  locale = (struct ecma402_locale *)malloc(sizeof(ecma402_locale));

  if (locale == nullptr) {
    return nullptr;
  }

  locale->baseName = nullptr;
  locale->canonical = nullptr;
  locale->original = nullptr;
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

  int const capacity = ULOC_FULLNAME_CAPACITY;

  locale->original = strdup(localeId);
  INIT_PROPERTY(localeId, canonical, capacity, canonicalizeUnicodeLocaleId);
  INIT_PROPERTY(locale->canonical, baseName, capacity, getBaseName);

  return locale;
}
