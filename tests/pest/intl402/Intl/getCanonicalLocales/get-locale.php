<?php

declare(strict_types=1);

use Ecma\Intl;

// PHP arrays and iterables don't have "get" or "length" properties, so we will
// test that we reach all items of the iterable by testing for an exception
// thrown from a Generator.

$locales = function (): iterable {
    yield 'en-us';
    yield 'de-de';
    yield throw new RuntimeException('Whoops!');
};

it('iterates through locales generator', function () use ($locales): void {
    expect(fn () => Intl::getCanonicalLocales($locales()))
        ->toThrow(RuntimeException::class, 'Whoops!');
});
