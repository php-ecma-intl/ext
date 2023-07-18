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

#ifndef ECMA_INTL_ECMA402_CATEGORY_H
#define ECMA_INTL_ECMA402_CATEGORY_H

#include "common.h"

#define ECMA402_CATEGORY_CALENDAR "calendar"
#define ECMA402_CATEGORY_COLLATION "collation"
#define ECMA402_CATEGORY_CURRENCY "currency"
#define ECMA402_CATEGORY_NUMBERING_SYSTEM "numberingSystem"
#define ECMA402_CATEGORY_TIME_ZONE "timeZone"
#define ECMA402_CATEGORY_UNIT "unit"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Points the provided values char pointer to an array of all supported values
 * for the given category, and returns the total number of supported values
 * for the category.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the units. Typically, this should use
 * ecma402_capacityForCategory(category). For example:
 *
 *     malloc(sizeof(const char *) * ecma402_capacityForCategory(category))
 *
 * @param category The category keyword to get supported values for.
 * @param values A pointer to store the resulting char array of values.
 *
 * @return The total count of the supported values returned for the category.
 */
int ecma402_supportedValuesForCategory(const char *category,
                                       const char **values);

/**
 * Returns the recommended const char ** capacity for the given category.
 */
int ecma402_capacityForCategory(const char *category);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_CATEGORY_H */
