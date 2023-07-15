<?php

declare(strict_types=1);

use Ecma\Intl;

$irregularGrandfathered = [
    'en-gb-oed',
    'i-ami',
    'i-bnn',
    'i-default',
    'i-enochian',
    'i-hak',
    'i-klingon',
    'i-lux',
    'i-mingo',
    'i-navajo',
    'i-pwn',
    'i-tao',
    'i-tay',
    'i-tsu',
    'sgn-be-fr',
    'sgn-be-nl',
    'sgn-ch-de',
];

$regularGrandfatheredNonUTS35 = [
    'no-bok',
    'no-nyn',
    'zh-min',
    'zh-min-nan',
];

$regularGrandfatheredUTS35 = [
    'art-lojban' => 'jbo',
    'cel-gaulish' => 'xtg',
    'zh-guoyu' => 'zh',
    'zh-hakka' => 'hak',
    'zh-xiang' => 'hsn',
];

test('test data is not a structurally valid language tag')
    ->with(array_merge($irregularGrandfathered, $regularGrandfatheredNonUTS35))
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeFalse();

test('test data is a canonicalized and structurally valid language tag')
    ->with(array_values($regularGrandfatheredUTS35))
    ->expect(fn (string $tag): bool => isCanonicalizedStructurallyValidLanguageTag($tag))
    ->toBeTrue();

it('canonicalizes grandfathered language tags', function (string $tag, string $canonical): void {
    expect(Intl::getCanonicalLocales($tag))
        ->toHaveCount(1)
        ->{0}->toBe($canonical);
})->with(array_map(
    fn ($k, $v) => [$k, $v],
    array_keys($regularGrandfatheredUTS35),
    array_values($regularGrandfatheredUTS35),
));
