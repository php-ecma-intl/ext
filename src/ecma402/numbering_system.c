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

#include "ecma402/numbering_system.h"

#include "ecma402/locale.h"
#include "ecma402/util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/uenum.h>
#include <unicode/uloc.h>
#include <unicode/unumsys.h>

int ecma402_availableCanonicalNumberingSystems(const char **values) {
  UEnumeration *enumeration = NULL;
  UErrorCode status = U_ZERO_ERROR;
  const char *identifier;
  int identifierLength, valuesCount = 0;

  enumeration = unumsys_openAvailableNames(&status);

  if (U_FAILURE(status)) {
    return 0;
  }

  while ((identifier = uenum_next(enumeration, &identifierLength, &status))) {
    const char *tmpIdentifier = NULL;
    tmpIdentifier =
        uloc_toUnicodeLocaleType(ICU_KEYWORD_NUMBERING_SYSTEM, identifier);

    size_t tmpIdLength = strlen(tmpIdentifier);
    values[valuesCount] = (const char *)malloc(tmpIdLength + 1);
    memcpy((void *)values[valuesCount], tmpIdentifier, tmpIdLength + 1);

    valuesCount++;
  }

  uenum_close(enumeration);

  return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount,
                                         ecma402_strToLower);
}

int ecma402_numberingSystemsOfLocale(const char *localeId,
                                     const char **values) {
  return ecma402_keywordsOfLocale(localeId, ICU_KEYWORD_NUMBERING_SYSTEM,
                                  values);
}
