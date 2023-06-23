<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

use Ecma\Intl;

$invalidKeys = [
    // Empty string is invalid.
    '',

    // Various unsupported keys.
    'hourCycle', 'locale', 'language', 'script', 'region',

    // Plural form of supported keys not valid.
    'calendars', 'collations', 'currencies', 'numberingSystems', 'timeZones', 'units',

    // Wrong case for supported keys.
    'CALENDAR', 'Collation', 'Currency', 'numberingsystem', 'timezone', 'UNIT',

    // NUL character must be handled correctly.
    "calendar\0",

    // Non-string cases.
    null, false, true, NAN, 0, M_PI, PHP_INT_MAX, PHP_INT_MIN, (object) [], [[]],
];

it('throws a TypeError if the key is invalid')
    ->throws(TypeError::class)
    ->with($invalidKeys)
    ->expect(fn (mixed $invalidKey): array => Intl::supportedValuesOf($invalidKey));
