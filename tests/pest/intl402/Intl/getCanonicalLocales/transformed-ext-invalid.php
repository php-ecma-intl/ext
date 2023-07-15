<?php

declare(strict_types=1);

use Ecma\Intl;

$invalid = [
    // empty
    'en-t',
    'en-t-a',
    'en-t-x',
    'en-t-0',

    // incomplete
    'en-t-',
    'en-t-en-',
    'en-t-0x-',

    // tlang: unicode_language_subtag must be 2-3 or 5-8 characters and mustn't
    // contain extlang subtags.
    'en-t-root',
    'en-t-abcdefghi',
    'en-t-ar-aao',

    // tlang: unicode_script_subtag must be 4 alphabetical characters, can't
    // be repeated.
    'en-t-en-lat0',
    'en-t-en-latn-latn',

    // tlang: unicode_region_subtag must either be 2 alpha characters or a three
    // digit code.
    'en-t-en-0',
    'en-t-en-00',
    'en-t-en-0x',
    'en-t-en-x0',
    'en-t-en-latn-0',
    'en-t-en-latn-00',
    'en-t-en-latn-xyz',

    // tlang: unicode_variant_subtag is either 5-8 alphanum characters or 4
    // characters starting with a digit.
    'en-t-en-abcdefghi',
    'en-t-en-latn-gb-ab',
    'en-t-en-latn-gb-abc',
    'en-t-en-latn-gb-abcd',
    'en-t-en-latn-gb-abcdefghi',

    // tkey must be followed by tvalue.
    'en-t-d0',
    'en-t-d0-m0',
    'en-t-d0-x-private',
];

test('test data is not a structurally valid language tag')
    ->with($invalid)
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeFalse();

// ECMA-402 specifies that it throws a RangeError, but PHP has ValueError, which
// means what ECMA-402 intends RangeError to mean.
it('throws a ValueError when a language tag includes an invalid transformed extension subtag', function (
    string $tag,
): void {
    expect(fn (): array => Intl::getCanonicalLocales($tag))
        ->toThrow(ValueError::class, "Invalid language tag \"$tag\"");
})->with($invalid);

