<?php

declare(strict_types=1);

use Ecma\Intl;

$reflected = new ReflectionMethod(Intl::class, 'getCanonicalLocales');

test('its name is getCanonicalLocales')
    ->expect($reflected->getName())
    ->toBe('getCanonicalLocales');
