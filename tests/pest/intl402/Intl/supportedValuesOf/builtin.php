<?php

declare(strict_types=1);

use Ecma\Intl;

$reflected = new ReflectionMethod(Intl::class, 'supportedValuesOf');

it('is a static method on Ecma\\Intl')
    ->expect($reflected->isStatic())
    ->toBeTrue();

it('is a public method on Ecma\\Intl')
    ->expect($reflected->isPublic())
    ->toBeTrue();
