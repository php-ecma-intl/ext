<?php

declare(strict_types=1);

use Ecma\Intl;

$weirdCases = [
    'en-x-u-foo',
    'en-a-bar-x-u-foo',
    'en-x-u-foo-a-bar',
    'en-a-bar-u-baz-x-u-foo',
];

it('allows "weird" tags', function (string $weird): void {
    expect(Intl::getCanonicalLocales($weird))
        ->toBe([$weird]);
})->with($weirdCases);
