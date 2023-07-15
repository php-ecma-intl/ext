<?php

declare(strict_types=1);

use Ecma\Intl;

// <key name="ca" [...] alias="calendar">
$testData = [
    // <type name="level1" [...] alias="primary"/>
    'primary' => 'level1',

    // "secondary" doesn't match |uvalue|, so we can skip it.
    // <type name="level2" [...] alias="secondary"/>
    //'secondary' => 'level2',

    // <type name="level3" [...] alias="tertiary"/>
    'tertiary' => 'level3',

    // Neither "quaternary" nor "quarternary" match |uvalue|, so we can skip them.
    // <type name="level4" [...] alias="quaternary quarternary"/>
    //'quaternary' => 'level4',
    //'quarternary' => 'level4',

    // "identical" doesn't match |uvalue|, so we can skip it.
    // <type name="identic" [...] alias="identical"/>
    //'identical' => 'identic',
];

it('canonicalizes for the "ks" Unicode subtag extension key', function (
    string $alias,
    string $name,
): void {
    $tag = 'und-u-ks-' . $alias;
    $canonical = 'und-u-ks-' . $name;

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

