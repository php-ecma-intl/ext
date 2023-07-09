<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

declare(strict_types=1);

use Ecma\Intl;

it('has one required parameter')
    ->expect(
        (new ReflectionMethod(Intl::class, 'supportedValuesOf'))
            ->getNumberOfRequiredParameters()
    )
    ->toBe(1);
