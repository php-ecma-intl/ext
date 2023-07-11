<?php

declare(strict_types=1);

use Ecma\Intl;

$canonicalizedTags = [
    'de' => 'de',
    'DE-de' => 'de-DE',
    'de-DE' => 'de-DE',
    'cmn' => 'zh',
    'CMN-hANS' => 'zh-Hans',
    'cmn-hans-cn' => 'zh-Hans-CN',
    'es-419' => 'es-419',
    'es-419-u-nu-latn' => 'es-419-u-nu-latn',
    'cmn-hans-cn-u-ca-t-ca-x-t-u' => 'zh-Hans-CN-t-ca-u-ca-x-t-u',
    'de-gregory-u-ca-gregory' => 'de-gregory-u-ca-gregory',
    'sgn-GR' => 'gss',
    'ji' => 'yi',
    'de-DD' => 'de-DE',
    'in' => 'id',
    'sr-cyrl-ekavsk' => 'sr-Cyrl-ekavsk',
    'en-ca-newfound' => 'en-CA-newfound',
    'sl-rozaj-biske-1994' => 'sl-1994-biske-rozaj',
    'da-u-attr' => 'da-u-attr',
    'da-u-attr-co-search' => 'da-u-attr-co-search',
];

test('test data is correct')
    ->with(array_values($canonicalizedTags))
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeTrue();

it('canonicalizes language tags', function (
    string $tag,
    string $canonicalized,
): void {
    $canonicalLocales = Intl::getCanonicalLocales($tag);
    expect($canonicalLocales)
        ->toHaveCount(1)
        ->and($canonicalLocales[0])
        ->toBe($canonicalized);
})->with(function () use ($canonicalizedTags): Generator {
    foreach ($canonicalizedTags as $tag => $canonicalized) {
        yield [$tag, $canonicalized];
    }
});
