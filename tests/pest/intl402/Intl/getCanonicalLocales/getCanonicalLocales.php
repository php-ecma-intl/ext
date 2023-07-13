<?php

declare(strict_types=1);

use Ecma\Intl;

$reflected = new ReflectionClass(Intl::class);

it('has method getCanonicalLocales')
    ->expect($reflected->hasMethod('getCanonicalLocales'))
    ->toBeTrue();
