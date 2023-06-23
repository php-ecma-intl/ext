<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/d52a5bbbe88b82bee0122689c161f1bf15fe8a0d/test/intl402/Intl/supportedValuesOf/units.js
 */

use Ecma\Intl;
use Ecma\Intl\Category;

$units = Intl::supportedValuesOf(Category::Unit);

it('returns an array')
    ->expect($units)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherUnits = Intl::supportedValuesOf(Category::Unit);
        sort($otherUnits);

        return $otherUnits;
    })
    ->toBe($units);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::Unit)))
    ->toHaveCount(count($units));

it('is a sanctioned single unit')
    ->with($units)
    ->expect(fn (string $unit): string => $unit)
    ->toBeIn(SANCTIONED_SINGLE_UNITS)
    ->not()->toContain('-per-');
