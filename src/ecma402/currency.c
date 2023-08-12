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

#include "ecma402/currency.h"

#include "ecma402/locale.h"
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

int ecma402_currenciesOfLocale(ecma402_locale *locale, const char **values) {
  int count = ecma402_keywordsOfLocale(locale, ICU_KEYWORD_CURRENCY, values);

  for (int i = 0; i < count; i++) {
    values[i] = ecma402_strToUpper((char *)values[i]);
  }

  return count;
}
