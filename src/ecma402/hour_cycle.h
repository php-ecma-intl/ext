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

#ifndef ECMA_INTL_ECMA402_HOUR_CYCLE_H
#define ECMA_INTL_ECMA402_HOUR_CYCLE_H

#include "common.h"

#include "ecma402/locale.h"

/**
 * A sufficient capacity for storing a list of hour cycle types for a given
 * locale.
 */
#define ECMA402_LOCALE_HOUR_CYCLE_CAPACITY 1

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns a list of one or more unique canonical hour cycle identifiers for the
 * given locale identifier.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_LOCALE_HOUR_CYCLE_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_LOCALE_HOUR_CYCLE_CAPACITY)
 *
 * @param localeId The locale identifier to get the hour cycles for.
 * @param values A pointer in which to store the resulting char array of
 * hour cycle values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_hourCyclesOfLocale(ecma402_locale *locale, const char **values);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_HOUR_CYCLE_H */
