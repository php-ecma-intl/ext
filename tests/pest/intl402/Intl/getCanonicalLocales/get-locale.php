<?php

declare(strict_types=1);

use Ecma\Intl;

$locales = ['en-US'];
$locales[] = '--';

it('iterates through locales list', function () use ($locales): void {
    expect(fn () => Intl::getCanonicalLocales($locales))
        ->toThrow(ValueError::class);
});
