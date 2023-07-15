<?php

declare(strict_types=1);

use Ecma\Intl;

$unicodeKeys = [
    // <key name="kb" [...] alias="colBackwards">
    //   <type name="true" [...] alias="yes"/>
    'kb',

    // <key name="kc" [...] alias="colCaseLevel">
    //   <type name="true" [...] alias="yes"/>
    'kc',

    // <key name="kh" [...] alias="colBackwards">
    //   <type name="true" [...] alias="yes"/>
    'kh',

    // <key name="kh" [...] alias="colHiraganaQuaternary">
    //   <type name="true" [...] alias="yes"/>
    'kk',

    // <key name="kn" [...] alias="colNumeric">
    //   <type name="true" [...] alias="yes"/>
    'kn',
];

it('canonicalizes "yes" to "true" for Unicode extension keys', function (
    string $key,
): void {
    $tag = "und-u-$key-yes";
    $canonical = "und-u-$key";

    expect(isCanonicalizedStructurallyValidLanguageTag($tag))
        ->toBeFalse()
        ->and(isCanonicalizedStructurallyValidLanguageTag($canonical))
        ->toBeTrue()
        ->and(Intl::getCanonicalLocales($tag))
        ->toHaveCount(1)
        ->{0}->toBe($canonical);
})->with($unicodeKeys);
