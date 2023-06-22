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

#include "time_zone.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/ucal.h>
#include <unicode/uenum.h>

#define TIME_ZONE_UTC "UTC"

static const char *canonicalizeTimeZoneName(const char *timeZoneIdentifier);

int ecma402_availableCanonicalTimeZones(const char **values) {
  UEnumeration *enumeration = NULL;
  UErrorCode status = U_ZERO_ERROR;
  const char *identifier;
  int identifierLength, valuesCount = 0;

  enumeration = ucal_openTimeZoneIDEnumeration(UCAL_ZONE_TYPE_CANONICAL, NULL,
                                               NULL, &status);

  if (U_FAILURE(status)) {
    return 0;
  }

  while ((identifier = uenum_next(enumeration, &identifierLength, &status))) {
    const char *tmpIdentifier = NULL;
    tmpIdentifier = canonicalizeTimeZoneName(identifier);

    size_t tmpIdLength = strlen(tmpIdentifier);
    values[valuesCount] = (const char *)malloc(tmpIdLength + 1);
    memcpy((void *)values[valuesCount], tmpIdentifier, tmpIdLength + 1);

    valuesCount++;
  }

  uenum_close(enumeration);

  return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount, NULL);
}

static const char *canonicalizeTimeZoneName(const char *timeZoneIdentifier) {
  if (strcasecmp(timeZoneIdentifier, "Etc/UTC") == 0 ||
      strcasecmp(timeZoneIdentifier, "Etc/GMT") == 0 ||
      strcasecmp(timeZoneIdentifier, "GMT") == 0) {
    return TIME_ZONE_UTC;
  }

  return timeZoneIdentifier;
}
