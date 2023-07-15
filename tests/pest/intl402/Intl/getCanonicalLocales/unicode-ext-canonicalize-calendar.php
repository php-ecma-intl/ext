<?php

declare(strict_types=1);

use Ecma\Intl;

$testData = [
    // <type name="ethioaa" [...] alias="ethiopic-amete-alem"/>
    'ethiopic-amete-alem' => 'ethioaa',

    // <type name="islamic-civil" [...] />
    // <type name="islamicc" [...] deprecated="true" preferred="islamic-civil" alias="islamic-civil"/>
    //
    // "name" and "alias" for "islamic-civil" don't quite match of what's spec'ed in UTS 35, §3.2.1.
    // Specifically following §3.2.1 to the letter means "islamicc" is the canonical value whereas
    // "islamic-civil" is an alias value. Assume the definitions in
    // https://unicode.org/reports/tr35/#Unicode_Locale_Extension_Data_Files overrule UTS 35, §3.2.1.
    'islamicc' => 'islamic-civil',
];

it('canonicalizes for the "ca" Unicode subtag extension key', function (
    string $alias,
    string $name,
): void {
    $tag = 'und-u-ca-' . $alias;
    $canonical = 'und-u-ca-' . $name;

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

