<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/prop-desc.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      Intl.supportedValuesOf property attributes.
    info: |
      Intl.supportedValuesOf ( key )

      18 ECMAScript Standard Built-in Objects:
        Every other data property described in clauses 19 through 28 and in Annex B.2
        has the attributes { [[Writable]]: true, [[Enumerable]]: false,
        [[Configurable]]: true } unless otherwise specified.

    ecma_intl implementation notes:

    PHP methods/functions do not have properties, since they aren't objects
    themselves, but we can test properties of functions and their parameters
    using PHP's Reflection API.

    Additionally, PHP functions do not have the properties of being Writable,
    Enumerable, or Configurable, so we are testing a different set of values,
    namely the position and name of the parameters, especially since PHP
    supports named parameters, so the names of arguments are part of a
    function's public API.
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
