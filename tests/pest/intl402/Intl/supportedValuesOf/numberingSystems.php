<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$numberingSystems = Intl::supportedValuesOf(Category::NumberingSystem);

it('returns an array')
    ->expect($numberingSystems)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherNumberingSystems = Intl::supportedValuesOf(Category::NumberingSystem);
        sort($otherNumberingSystems);

        return $otherNumberingSystems;
    })
    ->toBe($numberingSystems);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::NumberingSystem)))
    ->toHaveCount(count($numberingSystems));

it("matches the 'type' production")
    ->with($numberingSystems)
    ->expect(fn (string $numberingSystem): string => $numberingSystem)
    ->toMatch(TYPE_PRODUCTION_PATTERN);

// TODO: Add test for canonicalized strings.
// See: https://github.com/tc39/test262/blob/d52a5bbbe88b82bee0122689c161f1bf15fe8a0d/test/intl402/Intl/supportedValuesOf/numberingSystems.js#L52-L55
