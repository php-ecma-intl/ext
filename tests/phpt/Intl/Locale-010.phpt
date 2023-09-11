--TEST--
Locale canonicalizes, minimizes, and maximizes (>= ICU 73.1)
--EXTENSIONS--
ecma_intl
--SKIPIF--
<?php if (\Ecma\Intl::ICU_VERSION < '73.1') exit('Skip: Test requires ICU 73.1 or later'); ?>
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Locale;

// Test some language tags where we know that either CLDR or ICU produce
// different results compared to the canonicalization specified in RFC 5646.
$tests = [
    'mo',
    'es-ES-preeuro',
    'uz-UZ-cyrillic',
    'posix',
    'hi-direct',
    'zh-pinyin',
    'zh-stroke',

    // "aar" should be canonicalized into "aa" because "aar" matches the type attribute of
    // a languageAlias element in
    // https://www.unicode.org/repos/cldr/trunk/common/supplemental/supplementalMetadata.xml
    'aar-x-private',

    // "heb" should be canonicalized into "he" because "heb" matches the type attribute of
    // a languageAlias element in
    // https://www.unicode.org/repos/cldr/trunk/common/supplemental/supplementalMetadata.xml
    'heb-x-private',

    'de-u-kf',

    // "ces" should be canonicalized into "cs" because "ces" matches the type attribute of
    // a languageAlias element in
    // https://www.unicode.org/repos/cldr/trunk/common/supplemental/supplementalMetadata.xml
    'ces',

    'hy-arevela',
    'hy-arevmda',
    'en-US-POSIX',
];

foreach ($tests as $test) {
    $canonical = new Locale($test);
    $maximized = $canonical->maximize();
    $minimized = $canonical->minimize();
    
    assert($canonical !== $maximized);
    assert($canonical !== $minimized);
    
    echo "canonical: $canonical\n";
    echo "maximized: $maximized\n";
    echo "minimized: $minimized\n";
    echo "\n";
}

--EXPECT--
canonical: ro
maximized: ro-Latn-RO
minimized: ro

canonical: es-ES-preeuro
maximized: es-Latn-ES-preeuro
minimized: es-preeuro

canonical: uz-UZ-cyrillic
maximized: uz-Latn-UZ-cyrillic
minimized: uz-cyrillic

canonical: posix
maximized: posix
minimized: posix

canonical: hi-direct
maximized: hi-Deva-IN-direct
minimized: hi-direct

canonical: zh-pinyin
maximized: zh-Hans-CN-pinyin
minimized: zh-pinyin

canonical: zh-stroke
maximized: zh-Hans-CN-stroke
minimized: zh-stroke

canonical: aa-x-private
maximized: aa-Latn-ET-x-private
minimized: aa-x-private

canonical: he-x-private
maximized: he-Hebr-IL-x-private
minimized: he-x-private

canonical: de-u-kf
maximized: de-Latn-DE-u-kf
minimized: de-u-kf

canonical: cs
maximized: cs-Latn-CZ
minimized: cs

canonical: hy
maximized: hy-Armn-AM
minimized: hy

canonical: hyw
maximized: hyw-Armn-AM
minimized: hyw

canonical: en-US-u-va-posix
maximized: en-Latn-US-u-va-posix
minimized: en-u-va-posix
