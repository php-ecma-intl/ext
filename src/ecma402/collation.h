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

#ifndef ECMA_INTL_ECMA402_COLLATION_H
#define ECMA_INTL_ECMA402_COLLATION_H

#include "common.h"

#define ECMA402_COLLATION_CAPACITY 25

#define ECMA402_COLLATION_SEARCH "search"
#define ECMA402_COLLATION_STANDARD "standard"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns a list of unique canonical collation types supported by this
 * implementation.
 *
 * The values parameter should already be allocated on the stack with enough
 * memory to store all the values. Typically, this should use
 * ECMA402_COLLATION_CAPACITY. For example:
 *
 *     malloc(sizeof(const char *) * ECMA402_COLLATION_CAPACITY)
 *
 * @param values A pointer in which to store the resulting char array of
 * collation values.
 *
 * @return The total count of the number of values stored to the char array.
 */
int ecma402_availableCanonicalCollations(const char **values);

#ifdef __cplusplus
}
#endif

#endif /* ECMA_INTL_ECMA402_COLLATION_H */
