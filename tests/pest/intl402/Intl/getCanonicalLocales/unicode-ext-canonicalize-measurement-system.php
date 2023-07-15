<?php

declare(strict_types=1);

use Ecma\Intl;

// <key name="ms" [...] alias="measure" since="28">
$testData = [
    // <type name="uksystem" [...] alias="imperial" since="28" />
    'imperial' => 'uksystem',
];

it('canonicalizes for the "ms" Unicode subtag extension key', function (
    string $alias,
    string $name,
): void {
    $tag = 'und-u-ms-' . $alias;
    $canonical = 'und-u-ms-' . $name;

    expect(isCanonicalizedStructurallyValidLanguageTag($tag))
        ->toBeFalse()
        ->and(isCanonicalizedStructurallyValidLanguageTag($canonical))
        ->toBeTrue()
        ->and(Intl::getCanonicalLocales($tag))
        ->toHaveCount(1)
        ->{0}->toBe($canonical);
})->with(array_map(
    fn ($k, $v) => [$k, $v],
    array_keys($testData),
    array_values($testData),
));

