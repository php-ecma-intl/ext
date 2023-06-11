<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/builtin.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      Intl.supportedValuesOf is a built-in function object..
    info: |
      Intl.supportedValuesOf ( key )

      18 ECMAScript Standard Built-in Objects:
        Unless specified otherwise, a built-in object that is callable as a function
        is a built-in function object with the characteristics described in 10.3.
        Unless specified otherwise, the [[Extensible]] internal slot of a built-in
        object initially has the value true.

        Unless otherwise specified every built-in function and every built-in
        constructor has the Function prototype object, which is the initial value
        of the expression Function.prototype (20.2.3), as the value of its
        [[Prototype]] internal slot.

        Built-in function objects that are not identified as constructors do not
        implement the [[Construct]] internal method unless otherwise specified in
        the description of a particular function.

    ecma_intl implementation notes:

    PHP's object model differs from JavaScript's. As a result, we aren't
    checking whether the method is a "function object" or is "extensible."
    Instead, we check to ensure the method exists on the Ecma\Intl class and
    that it is a static method.
*/

use Ecma\Intl;

$reflected = new ReflectionMethod(Intl::class, 'supportedValuesOf');

it('is a static method on Ecma\\Intl')
    ->expect($reflected->isStatic())
    ->toBeTrue();

it('is a public method on Ecma\\Intl')
    ->expect($reflected->isPublic())
    ->toBeTrue();
