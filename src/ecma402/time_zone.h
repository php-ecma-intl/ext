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

#ifndef ECMA_INTL_ECMA402_TIME_ZONE_H
#define ECMA_INTL_ECMA402_TIME_ZONE_H

#include "common.h"

/**
 * Maximum capacity to allocate for a list of time zones.
 *
 * There are 468 unique time zones in the Unicode CLDR. icu4c's
 * ucal_openTimeZones() returns 636 time zone identifiers. The bundled
 * timezonedb in PHP has 597 unique time zones. PHP's
 * timezone_identifiers_list() filters this list and returns 419 time zones.
 * This allows for some unexpected growth. See:
 * https://github.com/unicode-org/cldr/blob/6600871aeacb361251ed5277587065ae04104696/common/bcp47/timezone.xml
 * https://github.com/php/php-src/blob/165a4e53da819d377734eb2286df1b54709d18f2/ext/date/lib/timezonedb.h
 * https://www.php.net/manual/en/function.timezone-identifiers-list.php
 */
#define ECMA402_TIME_ZONE_CAPACITY 650

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns a list of unique time zone identifiers supported by this
 * implementation.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_TIME_ZONE_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_TIME_ZONE_CAPACITY)
 *
 * @param values A pointer in which to store the resulting char array of
 * currency values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_availableCanonicalTimeZones(const char **values);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_TIME_ZONE_H */
