<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/d52a5bbbe88b82bee0122689c161f1bf15fe8a0d/test/intl402/Intl/supportedValuesOf/timeZones.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      The returned "timeZone" values are sorted, unique, and canonicalised.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      ...
      6. Else if key is "timeZone", then
        a. Let list be ! AvailableTimeZones( ).
      ...
      9. Return ! CreateArrayFromList( list ).

      AvailableTimeZones ()
        The AvailableTimeZones abstract operation returns a sorted List of supported
        Zone and Link names in the IANA Time Zone Database. The following steps are
        taken:

        1. Let names be a List of all supported Zone and Link names in the IANA Time
           Zone Database.
        2. Let result be a new empty List.
        3. For each element name of names, do
            a. Assert: ! IsValidTimeZoneName( name ) is true.
            b. Let canonical be ! CanonicalizeTimeZoneName( name ).
            c. If result does not contain an element equal to canonical, then
                i. Append canonical to the end of result.
        4. Sort result in order as if an Array of the same values had been sorted using
           %Array.prototype.sort% using undefined as comparefn.
        5. Return result.
*/

use Ecma\Intl;
use Ecma\Intl\Category;

$timeZones = Intl::supportedValuesOf(Category::TimeZone);

it('returns an array')
    ->expect($timeZones)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherNumberingSystems = Intl::supportedValuesOf(Category::TimeZone);
        sort($otherNumberingSystems);

        return $otherNumberingSystems;
    })
    ->toBe($timeZones);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::TimeZone)))
    ->toHaveCount(count($timeZones));

it('is canonicalized')
    ->with($timeZones)
    ->expect(fn (string $tz): bool => isCanonicalizedStructurallyValidTimeZoneName($tz))
    ->toBeTrue();
