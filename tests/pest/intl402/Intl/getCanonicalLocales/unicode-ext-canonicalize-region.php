<?php

declare(strict_types=1);

use Ecma\Intl;

$testData = [
    // <subdivisionAlias type="no23" replacement="no50" reason="deprecated"/>
    'no23' => 'no50',

    // <subdivisionAlias type="cn11" replacement="cnbj" reason="deprecated"/>
    'cn11' => 'cnbj',

    // <subdivisionAlias type="cz10a" replacement="cz110" reason="deprecated"/>
    'cz10a' => 'cz110',

    // <subdivisionAlias type="fra" replacement="frges" reason="deprecated"/>
    'fra' => 'frges',

    // <subdivisionAlias type="frg" replacement="frges" reason="deprecated"/>
    'frg' => 'frges',

    // <subdivisionAlias type="lud" replacement="lucl ludi lurd luvd luwi" reason="deprecated"/>
    'lud' => 'lucl',
];

it('canonicalizes for the "rg" Unicode subtag extension key', function (
    string $alias,
    string $name,
): void {
    $tag = 'und-u-rg-' . $alias;
    $canonical = 'und-u-rg-' . $name;

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

