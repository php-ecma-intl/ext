<?php

declare(strict_types=1);

use Ecma\Intl;

$canonicalizedTags = [
    'ja-latn-hepburn-heploc' => 'ja-Latn-alalc97',
];

test('test data is a canonicalized and structurally valid language tag')
    ->with(array_values($canonicalizedTags))
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeTrue();

it('canonicalizes grandfathered language tags with variants', function (
    string $tag,
    string $canonical,
): void {
    expect(Intl::getCanonicalLocales($tag))
        ->toHaveCount(1)
        ->{0}->toBe($canonical);
})->with(array_map(
    fn ($k, $v) => [$k, $v],
    array_keys($canonicalizedTags),
    array_values($canonicalizedTags),
));
