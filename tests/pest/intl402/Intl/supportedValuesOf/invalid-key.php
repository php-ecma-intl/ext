<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/invalid-key.js
 */


/*
    esid: sec-intl.supportedvaluesof
    description: >
      Intl.supportedValuesOf throws a RangeError if the key is invalid.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      ...
      8. Else,
        a. Throw a RangeError exception.
      ...

    ecma_intl implementation notes:

    In PHP, we use enums for type-safety, which means the language gives us
    input validation of the "keys" for free. Any invalid type provided to
    supportedValuesOf() will throw a TypeError.
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
