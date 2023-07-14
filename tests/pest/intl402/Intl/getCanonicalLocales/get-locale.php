<?php

declare(strict_types=1);

use Ecma\Intl;

$locales = function (): iterable {
    yield 'en-us';
    yield 'de-de';
    yield throw new RuntimeException('Whoops!');
};

it('iterates through locales generator', function () use ($locales): void {
    expect(fn () => Intl::getCanonicalLocales($locales()))
        ->toThrow(RuntimeException::class);
});
