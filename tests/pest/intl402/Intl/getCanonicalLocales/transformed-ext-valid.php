<?php

declare(strict_types=1);

use Ecma\Intl;

$valid = [
    // tlang with unicode_language_subtag.
    'en-t-en',

    // tlang with unicode_script_subtag.
    'en-t-en-latn',

    // tlang with unicode_region_subtag.
    'en-t-en-ca',

    // tlang with unicode_script_subtag and unicode_region_subtag.
    'en-t-en-latn-ca',

    // tlang with unicode_variant_subtag.
    'en-t-en-emodeng',

    // tlang with unicode_script_subtag and unicode_variant_subtag.
    'en-t-en-latn-emodeng',

    // tlang with unicode_script_subtag and unicode_variant_subtag.
    'en-t-en-ca-emodeng',

    // tlang with unicode_script_subtag, unicode_region_subtag, and unicode_variant_subtag.
    'en-t-en-latn-ca-emodeng',

    // No tlang. (Must contain at least one tfield.)
    'en-t-d0-ascii',
];

$extraFields = [
    // No extra tfield
    '',

    // tfield with a tvalue consisting of a single subtag.
    '-i0-handwrit',

    // tfield with a tvalue consisting of two subtags.
    '-s0-accents-publish',
];

$actualTags = [];
foreach ($valid as $tag) {
    foreach ($extraFields as $extra) {
        $actualTags[] = $tag . $extra;
    }
}

test('test data is a canonical and structurally valid language tag')
    ->with($actualTags)
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeTrue();

it('no ValueError is thrown when a language tag includes a valid transformed extension subtag', function (
    string $actualTag,
): void {
    expect(Intl::getCanonicalLocales($actualTag))
        ->toHaveCount(1)
        ->{0}->toBe($actualTag);
})->with($actualTags);

