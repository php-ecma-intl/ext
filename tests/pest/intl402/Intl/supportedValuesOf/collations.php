<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$collations = Intl::supportedValuesOf(Category::Collation);

it('returns an array')
    ->expect($collations)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherCollations = Intl::supportedValuesOf(Category::Collation);
        sort($otherCollations);

        return $otherCollations;
    })
    ->toBe($collations);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::Collation)))
    ->toHaveCount(count($collations));

it("matches the 'type' production")
    ->with($collations)
    ->expect(fn (string $collation): string => $collation)
    ->toMatch(TYPE_PRODUCTION_PATTERN);

it("does not include the 'standard' collation type")
    ->expect($collations)
    ->not()
    ->toContain('standard');

it("does not include the 'search' collation type")
    ->expect($collations)
    ->not()
    ->toContain('search');
