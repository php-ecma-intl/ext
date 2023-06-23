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

#include "ecma402/currency.h"

#include "ecma402/util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/ucurr.h>
#include <unicode/uenum.h>

int ecma402_availableCanonicalCurrencies(const char **values) {
  UEnumeration *enumeration = NULL;
  UErrorCode status = U_ZERO_ERROR;
  const char *identifier;
  int identifierLength, valuesCount = 0;

  enumeration = ucurr_openISOCurrencies(UCURR_ALL, &status);

  if (U_FAILURE(status)) {
    return 0;
  }

  while ((identifier = uenum_next(enumeration, &identifierLength, &status))) {
    values[valuesCount] = (const char *)malloc(identifierLength + 1);
    memcpy((void *)values[valuesCount], identifier, identifierLength + 1);

    valuesCount++;
  }

  uenum_close(enumeration);

  return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount,
                                         ecma402_strToUpper);
}
