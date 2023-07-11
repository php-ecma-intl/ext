<?php

declare(strict_types=1);

use Ecma\Intl;

it('has one required parameter')
    ->expect(
        (new ReflectionMethod(Intl::class, 'supportedValuesOf'))
            ->getNumberOfRequiredParameters()
    )
    ->toBe(1);
