<?php

/**
 * Portions of this file are
 * Copyright (C) 2020 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

use Ecma\Intl;

// CLDR contains language mappings where in addition to the language subtag also
// the script or region subtag is modified, unless they're already present.

$testData = [
    // "sh" adds "Latn", unless a script subtag is already present.
    // <languageAlias type="sh" replacement="sr_Latn" reason="legacy"/>
    'sh' => 'sr-Latn',
    'sh-Cyrl' => 'sr-Cyrl',

    // "cnr" adds "ME", unless a region subtag is already present.
    // <languageAlias type="cnr" replacement="sr_ME" reason="legacy"/>
    'cnr' => 'sr-ME',
    'cnr-BA' => 'sr-BA',
];

test('test data is correct')
    ->with(array_values($testData))
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeTrue();

test('non-simple language subtag replacements work as expected', function (
    string $tag,
    string $canonicalized,
): void {
    $canonicalLocales = Intl::getCanonicalLocales($tag);
    expect($canonicalLocales)
        ->toHaveCount(1)
        ->and($canonicalLocales[0])
        ->toBe($canonicalized);
})->with(function () use ($testData): Generator {
    foreach ($testData as $tag => $canonicalized) {
        yield [$tag, $canonicalized];
    }
});
