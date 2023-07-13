<?php

declare(strict_types=1);

use Ecma\Intl;

$regularGrandfathered = [
    [
        'tag' => 'art-lojban',
        'canonical' => 'jbo',
    ],
    [
        'tag' => 'zh-guoyu',
        'canonical' => 'zh',
    ],
    [
        'tag' => 'zh-hakka',
        'canonical' => 'hak',
    ],
    [
        'tag' => 'zh-xiang',
        'canonical' => 'hsn',
    ],
];

it('canonicalizes language tags', function (
    string $tag,
    string $canonical,
): void {
    $canonicalLocales = Intl::getCanonicalLocales($tag);
    expect($canonicalLocales)
        ->toHaveCount(1)
        ->and($canonicalLocales[0])
        ->toBe($canonical);
})->with($regularGrandfathered);
