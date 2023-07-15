<?php

declare(strict_types=1);

use Ecma\Intl;

$testData = [
    // Variant subtags are alphabetically ordered.
    'sl-t-sl-rozaj-biske-1994' => 'sl-t-sl-1994-biske-rozaj',

  // tfield subtags are alphabetically ordered.
  // (Also tests subtag case normalisation.)
  'DE-T-M0-DIN-K0-QWERTZ' => 'de-t-k0-qwertz-m0-din',

  // 'true' tvalue subtags aren't removed.
  // (UTS 35 version 36, §3.2.1 claims otherwise, but tkey must be followed by
  // tvalue, so that's likely a spec bug in UTS 35.)
  'en-t-m0-true' => 'en-t-m0-true',

  // tlang subtags are canonicalized.
  'en-t-iw' => 'en-t-he',

  // Deprecated tvalue subtags are replaced by their preferred value.
  'und-Latn-t-und-hani-m0-names' => 'und-Latn-t-und-hani-m0-prprname',
];

test('test data is a canonicalized and structurally valid language tag')
    ->with(array_values($testData))
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeTrue();

it('canonicalizes within transformed extension subtags', function(
    string $tag,
    string $canonical,
): void {
    expect(Intl::getCanonicalLocales($tag))
        ->toHaveCount(1)
        ->{0}->toBe($canonical);
})->with(array_map(
    fn ($k, $v) => [$k, $v],
    array_keys($testData),
    array_values($testData),
));

