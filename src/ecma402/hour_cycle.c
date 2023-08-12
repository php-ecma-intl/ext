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

#include "ecma402/hour_cycle.h"

#include "ecma402/locale.h"

int ecma402_hourCyclesOfLocale(const char *localeId, const char **values) {
  return ecma402_keywordsOfLocale(localeId, ICU_KEYWORD_HOUR_CYCLE, values);
}
