<?php

declare(strict_types=1);

use Ecma\Intl;

it('returns empty array for empty input array')
    ->expect(Intl::getCanonicalLocales([]))
    ->toBe([]);

it('returns empty array for NULL')
    ->expect(Intl::getCanonicalLocales(null))
    ->toBe([]);

$notStringTests = [
    false,
    true,
    NAN,
    1,
    3.14,
    new stdClass(),
];

it('throws TypeError when locales is not a string', function (mixed $test): void {
    $type = get_debug_type($test);
    expect(fn () => Intl::getCanonicalLocales($test))
        ->toThrow(
            TypeError::class,
            sprintf(
                'Ecma\\Intl::getCanonicalLocales(): Argument #1 ($locales) must '
                . 'be of type iterable<Stringable|string>|Stringable|string|null, %s given',
                $type
            ),
        );
})->with($notStringTests);
