<?php

declare(strict_types=1);

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
