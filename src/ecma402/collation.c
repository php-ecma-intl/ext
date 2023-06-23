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

#include "ecma402/collation.h"

#include "ecma402/util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/ucol.h>
#include <unicode/uenum.h>
#include <unicode/uloc.h>

int ecma402_availableCanonicalCollations(const char **values) {
  UEnumeration *enumeration = NULL;
  UErrorCode status = U_ZERO_ERROR;
  const char *identifier;
  int identifierLength, valuesCount = 0;

  enumeration = ucol_getKeywordValues(ICU_KEYWORD_COLLATION, &status);

  if (U_FAILURE(status)) {
    return 0;
  }

  while ((identifier = uenum_next(enumeration, &identifierLength, &status))) {
    const char *tmpIdentifier = NULL;
    tmpIdentifier = uloc_toUnicodeLocaleType(ICU_KEYWORD_COLLATION, identifier);

    // According to ECMA-402, section 10.2.3, "the values 'standard' and
    // 'search' must not be used as elements in any [collation] list."
    if (strcasecmp(tmpIdentifier, ECMA402_COLLATION_STANDARD) == 0 ||
        strcasecmp(tmpIdentifier, ECMA402_COLLATION_SEARCH) == 0) {
      continue;
    }

    size_t tmpIdLength = strlen(tmpIdentifier);
    values[valuesCount] = (const char *)malloc(tmpIdLength + 1);
    memcpy((void *)values[valuesCount], tmpIdentifier, tmpIdLength + 1);

    valuesCount++;
  }

  uenum_close(enumeration);

  return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount,
                                         ecma402_strToLower);
}
