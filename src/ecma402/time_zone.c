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

#include "ecma402/time_zone.h"

#include "ecma402/locale.h"
#include "ecma402/util.h"

#include <stdlib.h>
#include <string.h>
#include <unicode/ucal.h>
#include <unicode/uenum.h>

#define TIME_ZONE_UTC "UTC"

static const char *canonicalizeTimeZoneName(const char *timeZoneIdentifier);

int ecma402_availableCanonicalTimeZones(const char **values) {
	UEnumeration *enumeration = NULL;
	UErrorCode status = U_ZERO_ERROR;
	const char *identifier;
	int identifierLength, valuesCount = 0;

	enumeration = ucal_openTimeZoneIDEnumeration(UCAL_ZONE_TYPE_CANONICAL, NULL, NULL, &status);

	if (U_FAILURE(status)) {
		return 0;
	}

	while ((identifier = uenum_next(enumeration, &identifierLength, &status))) {
		const char *tmpIdentifier = NULL;
		tmpIdentifier = canonicalizeTimeZoneName(identifier);

		size_t tmpIdLength = strlen(tmpIdentifier);
		values[valuesCount] = (const char *)malloc(tmpIdLength + 1);
		memcpy((void *)values[valuesCount], tmpIdentifier, tmpIdLength + 1);

		valuesCount++;
	}

	uenum_close(enumeration);

	return ecma402_sortAndRemoveDuplicates((char **)values, valuesCount, NULL);
}

int ecma402_timeZonesOfLocale(ecma402_locale *locale, const char **values) {
	return ecma402_keywordsOfLocale(locale, ICU_KEYWORD_TIME_ZONE, values);
}

static const char *canonicalizeTimeZoneName(const char *timeZoneIdentifier) {
	if (strcasecmp(timeZoneIdentifier, "Etc/UTC") == 0 || strcasecmp(timeZoneIdentifier, "Etc/GMT") == 0 ||
	    strcasecmp(timeZoneIdentifier, "GMT") == 0) {
		return TIME_ZONE_UTC;
	}

	return timeZoneIdentifier;
}
