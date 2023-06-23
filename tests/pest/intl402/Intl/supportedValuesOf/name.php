<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

use Ecma\Intl;

$reflected = new ReflectionMethod(Intl::class, 'supportedValuesOf');

test("its name is 'supportedValuesOf'")
    ->expect($reflected->getName())
    ->toBe('supportedValuesOf');
