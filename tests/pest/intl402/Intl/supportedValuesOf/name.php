<?php

declare(strict_types=1);

use Ecma\Intl;

$reflected = new ReflectionMethod(Intl::class, 'supportedValuesOf');

test("its name is 'supportedValuesOf'")
    ->expect($reflected->getName())
    ->toBe('supportedValuesOf');
