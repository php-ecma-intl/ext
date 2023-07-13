<?php

declare(strict_types=1);

use Ecma\Intl;

it('throws ValueError for invalid tag', function (string $invalidTag): void {
    expect(fn () => Intl::getCanonicalLocales($invalidTag))
        ->toThrow(ValueError::class);
})->with(getInvalidLanguageTags());
