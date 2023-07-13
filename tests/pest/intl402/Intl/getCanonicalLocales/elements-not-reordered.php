<?php

declare(strict_types=1);

use Ecma\Intl;

$canonicalLocales = Intl::getCanonicalLocales(['zu', 'af']);

it('maintains the input order of locales')
    ->expect($canonicalLocales)
    ->toBeArray()
    ->toHaveCount(2)
    ->{0}->toBe('zu')
    ->{1}->toBe('af');
