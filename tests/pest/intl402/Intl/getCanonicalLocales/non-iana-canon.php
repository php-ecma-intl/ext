<?php

declare(strict_types=1);

use Ecma\Intl;

// Test some language tags where we know that either CLDR or ICU produce
// different results compared to the canonicalization specified in RFC 5646.
$testData = [
    [
        'tag' => 'mo',
        'canonical' => 'ro',
    ],
    [
        'tag' => 'es-ES-preeuro',
        'canonical' => 'es-ES-preeuro',
    ],
    [
        'tag' => 'uz-UZ-cyrillic',
        'canonical' => 'uz-UZ-cyrillic',
    ],
    [
        'tag' => 'posix',
        'canonical' => 'posix',
    ],
    [
        'tag' => 'hi-direct',
        'canonical' => 'hi-direct',
    ],
    [
        'tag' => 'zh-pinyin',
        'canonical' => 'zh-pinyin',
    ],
    [
        'tag' => 'zh-stroke',
        'canonical' => 'zh-stroke',
    ],
    [
        'tag' => 'aar-x-private',
        // "aar" should be canonicalized into "aa" because "aar" matches the type attribute of
        // a languageAlias element in
        // https://www.unicode.org/repos/cldr/trunk/common/supplemental/supplementalMetadata.xml
        'canonical' => 'aa-x-private',
    ],
    [
        'tag' => 'heb-x-private',
        // "heb" should be canonicalized into "he" because "heb" matches the type attribute of
        // a languageAlias element in
        // https://www.unicode.org/repos/cldr/trunk/common/supplemental/supplementalMetadata.xml
        'canonical' => 'he-x-private',
    ],
    [
        'tag' => 'de-u-kf',
        'canonical' => 'de-u-kf',
    ],
    [
        'tag' => 'ces',
        // "ces" should be canonicalized into "cs" because "ces" matches the type attribute of
        // a languageAlias element in
        // https://www.unicode.org/repos/cldr/trunk/common/supplemental/supplementalMetadata.xml
        'canonical' => 'cs',
    ],
    [
        'tag' => 'hy-arevela',
        'canonical' => 'hy',
    ],
    [
        'tag' => 'hy-arevmda',
        'canonical' => 'hyw',
    ],
];

it('canonicalizes specific known tags', function (
    string $tag,
    string $canonical,
): void {
    expect(Intl::getCanonicalLocales($tag))->toBe([$canonical]);
})->with($testData);
