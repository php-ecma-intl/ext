<?php

declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$timeZones = Intl::supportedValuesOf(Category::TimeZone);

it('returns an array')
    ->expect($timeZones)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherTimeZones = Intl::supportedValuesOf(Category::TimeZone);
        sort($otherTimeZones);

        return $otherTimeZones;
    })
    ->toBe($timeZones);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::TimeZone)))
    ->toHaveCount(count($timeZones));

it('is canonicalized')
    ->with($timeZones)
    ->expect(fn (string $tz): bool => isCanonicalizedStructurallyValidTimeZoneName($tz))
    ->toBeTrue();
