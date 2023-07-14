<?php

declare(strict_types=1);

use Ecma\Intl;

it('returns empty array for empty input array')
    ->expect(Intl::getCanonicalLocales([]))
    ->toBe([]);

$notStringTests = [
    NULL,
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
                . 'be of type string or a Traversable|array of type string, %s given',
                $type
            ),
        );
})->with($notStringTests);
