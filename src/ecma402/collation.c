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

#include "collation.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/ucol.h>
#include <unicode/uenum.h>

int getAvailableCanonicalCollations(const char **values) {
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
    if (strcasecmp(tmpIdentifier, COLLATION_STANDARD) == 0 ||
        strcasecmp(tmpIdentifier, COLLATION_SEARCH) == 0) {
      continue;
    }

    size_t tmpIdLength = strlen(tmpIdentifier);
    values[valuesCount] = (const char *)malloc(tmpIdLength + 1);
    memcpy((void *)values[valuesCount], tmpIdentifier, tmpIdLength + 1);

    valuesCount++;
  }

  uenum_close(enumeration);

  return sortAndRemoveDuplicates((char **)values, valuesCount);
}
