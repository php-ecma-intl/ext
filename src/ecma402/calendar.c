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

#include "ecma402/calendar.h"

#include "ecma402/error.h"
#include "ecma402/locale.h"
#include "ecma402/util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/ucal.h>
#include <unicode/uenum.h>
#include <unicode/uloc.h>

int ecma402_availableCanonicalCalendars(const char **values) {
  UEnumeration *enumeration = NULL;
  UErrorCode status = U_ZERO_ERROR;
  const char *identifier;
  int identifierLength, valuesCount = 0;

  enumeration =
      ucal_getKeywordValuesForLocale(ICU_KEYWORD_CALENDAR, NULL, 0, &status);

  if (U_FAILURE(status)) {
    return 0;
  }

  while ((identifier = uenum_next(enumeration, &identifierLength, &status))) {
    const char *tmpIdentifier = NULL;
    tmpIdentifier = uloc_toUnicodeLocaleType(ICU_KEYWORD_CALENDAR, identifier);

    size_t tmpIdLength = strlen(tmpIdentifier);
    values[valuesCount] = (const char *)malloc(tmpIdLength + 1);
    memcpy((void *)values[valuesCount], tmpIdentifier, tmpIdLength + 1);

    valuesCount++;
  }

  uenum_close(enumeration);

  return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount,
                                         ecma402_strToLower);
}

int ecma402_calendarsOfLocale(const char *localeId, const char **values) {
  UEnumeration *supported = NULL;
  UErrorCode status = U_ZERO_ERROR;
  char *canonicalized, *preferred;
  const char *name, *tmpName;
  int preferredLength, count = 0;
  ecma402_errorStatus *ecmaStatus;

  if (localeId == NULL) {
    return 0;
  }

  ecmaStatus = ecma402_initErrorStatus();
  canonicalized = (char *)malloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);
  ecma402_canonicalizeUnicodeLocaleId(localeId, canonicalized, ecmaStatus);

  if (ecma402_hasError(ecmaStatus)) {
    ecma402_freeErrorStatus(ecmaStatus);
    free(canonicalized);
    return 0;
  }

  ecma402_freeErrorStatus(ecmaStatus);

  // Check to see whether the localeId already has a calendar value set on it,
  // and if so, return it as the only item in the list; it is "preferred."
  preferred = (char *)malloc(sizeof(char) * ULOC_KEYWORDS_CAPACITY);
  preferredLength =
      uloc_getKeywordValue(canonicalized, ICU_KEYWORD_CALENDAR, preferred,
                           ULOC_KEYWORDS_CAPACITY, &status);

  free(canonicalized);

  if (U_FAILURE(status)) {
    free(preferred);
    return 0;
  }

  if (preferredLength > 0) {
    tmpName = uloc_toUnicodeLocaleType(ICU_KEYWORD_CALENDAR, preferred);
    free(preferred);

    size_t tmpNameLength = strlen(tmpName);
    values[0] = (const char *)malloc(tmpNameLength + 1);
    memcpy((void *)values[0], tmpName, tmpNameLength + 1);

    return 1;
  }

  free(preferred);

  // We didn't find a "preferred" calendar, so look up common supported
  // calendar values for this locale and return them.
  supported = ucal_getKeywordValuesForLocale(ICU_KEYWORD_CALENDAR, localeId,
                                             true, &status);
  if (U_FAILURE(status)) {
    return 0;
  }

  while ((name = uenum_next(supported, NULL, &status))) {
    if (U_FAILURE(status)) {
      break;
    }

    tmpName = uloc_toUnicodeLocaleType(ICU_KEYWORD_CALENDAR, name);
    size_t tmpNameLength = strlen(tmpName);
    values[count] = (const char *)malloc(tmpNameLength + 1);
    memcpy((void *)values[count], tmpName, tmpNameLength + 1);
    count++;
  }

  uenum_close(supported);

  return count;
}
