<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

use Ecma\Intl;
use Ecma\Intl\Category;

$reflected = new ReflectionMethod(Intl::class, 'supportedValuesOf');
$parameters = $reflected->getParameters();
$firstParameter = $parameters[0] ?? null;

it('has a first parameter')
    ->expect($firstParameter)
    ->toBeInstanceOf(ReflectionParameter::class);

test("its first parameter is required")
    ->expect($firstParameter->isOptional())
    ->toBeFalse();

test("its first parameter is named 'category'")
    ->expect($firstParameter->getName())
    ->toBe('category');

test("its first parameter's type is 'Ecma\\Intl\\Category'")
    ->expect($firstParameter->getType())
    ->toBeInstanceOf(ReflectionNamedType::class)
    ->and($firstParameter->getType()->getName())
    ->toBe(Category::class);
