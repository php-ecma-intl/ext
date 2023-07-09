<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

declare(strict_types=1);

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
