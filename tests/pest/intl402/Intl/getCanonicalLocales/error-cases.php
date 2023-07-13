<?php

declare(strict_types=1);

use Ecma\Intl;

$valueErrorCases = [
    'en-us-',
    '-en-us',
    'en-us-en-us',
    '--',
    '-',
    '',
    '-e-',
];

it('throws a ValueError for invalid input', function (mixed $test): void {
    expect(fn () => Intl::getCanonicalLocales($test))
        ->toThrow(ValueError::class);
})->with($valueErrorCases);

$typeErrorCases = [
    null,
    false,
    0,
    1234,
    [null],
    [true],
    [NAN],
    [2],
];

it('throws a TypeError for invalid types', function (mixed $test): void {
    expect(fn () => Intl::getCanonicalLocales($test))
        ->toThrow(TypeError::class);
})->with($typeErrorCases);
