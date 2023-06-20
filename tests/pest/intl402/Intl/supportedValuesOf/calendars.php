<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/2f0193d4cf583091f7717b7851270a75a78826e4/test/intl402/Intl/supportedValuesOf/calendars.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      The returned "calendar" values are sorted, unique, and match the type production.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      2. If key is "calendar", then
        a. Let list be ! AvailableCalendars( ).
      ...
      9. Return ! CreateArrayFromList( list ).

      AvailableCalendars ( )
        The AvailableCalendars abstract operation returns a List, ordered as if an
        Array of the same values had been sorted using %Array.prototype.sort% using
        undefined as comparefn, that contains unique calendar types identifying the
        calendars for which the implementation provides the functionality of
        Intl.DateTimeFormat objects. The list must include "gregory".
*/

use Ecma\Intl;
use Ecma\Intl\Category;

$calendars = Intl::supportedValuesOf(Category::Calendar);

it('returns an array')
    ->expect($calendars)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherCalendars = Intl::supportedValuesOf(Category::Calendar);
        sort($otherCalendars);

        return $otherCalendars;
    })
    ->toBe($calendars);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::Calendar)))
    ->toHaveCount(count($calendars));

it("matches the 'type' production")
    ->with($calendars)
    ->expect(fn (string $calendar): string => $calendar)
    ->toMatch(TYPE_PRODUCTION_PATTERN);

// ECMA-402 section 6.9.1 requires "iso8601" in the list of calendars:
// https://tc39.es/ecma402/#sec-availablecanonicalcalendars
it("must include 'iso8601'")
    ->expect($calendars)
    ->toContain('iso8601');

// The Test262 test suite requires "gregory" in the list of calendars:
// https://github.com/tc39/test262/blob/2f0193d4cf583091f7717b7851270a75a78826e4/test/intl402/Intl/supportedValuesOf/calendars.js#L54
it("must include 'gregory'")
    ->expect($calendars)
    ->toContain('gregory');
