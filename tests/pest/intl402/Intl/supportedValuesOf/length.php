<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/length.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      Intl.supportedValuesOf.length value and descriptor.
    info: |
      Intl.supportedValuesOf ( key )

      18 ECMAScript Standard Built-in Objects:
        Every built-in function object, including constructors, has a "length"
        property whose value is a non-negative integral Number. Unless otherwise
        specified, this value is equal to the number of required parameters shown in
        the subclause heading for the function description. Optional parameters and
        rest parameters are not included in the parameter count.

        Unless otherwise specified, the "length" property of a built-in function
        object has the attributes { [[Writable]]: false, [[Enumerable]]: false,
        [[Configurable]]: true }.

    ecma_intl implementation notes:

    PHP methods/functions do not have properties, since they aren't objects
    themselves, but we can assert attributes of the parameters for a function
    using the Reflection API.
*/

use Ecma\Intl;

it('has one required parameter')
    ->expect(
        (new ReflectionMethod(Intl::class, 'supportedValuesOf'))
            ->getNumberOfRequiredParameters()
    )
    ->toBe(1);
