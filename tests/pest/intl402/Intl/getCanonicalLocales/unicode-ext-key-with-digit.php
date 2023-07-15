<?php

declare(strict_types=1);

use Ecma\Intl;

// Unicode locale extension sequences don't allow keys with a digit as their
// second character.
$invalidCases = [
    'en-u-c0',
    'en-u-00',
];

// The first character is allowed to be a digit.
$validCases = [
    'en-u-0c',
];

it('throws ValueError if the second char of the key is a digit', function (
    string $invalid,
): void {
    expect(isCanonicalizedStructurallyValidLanguageTag($invalid))
        ->toBeFalse()
        ->and(fn (): array => Intl::getCanonicalLocales($invalid))
        ->toThrow(ValueError::class, "Invalid language tag \"$invalid\"");
})->with($invalidCases);

it('allows a digit as the first char of the key', function (
    string $valid,
): void {
    expect(isCanonicalizedStructurallyValidLanguageTag($valid))
        ->toBeTrue()
        ->and(Intl::getCanonicalLocales($valid))
        ->toHaveCount(1)
        ->{0}->toBe($valid);
})->with($validCases);
