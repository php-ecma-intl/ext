<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/name.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      Intl.supportedValuesOf.name value and descriptor.
    info: |
      Intl.supportedValuesOf ( key )

      18 ECMAScript Standard Built-in Objects:
        Every built-in function object, including constructors, has a "name"
        property whose value is a String. Unless otherwise specified, this value is
        the name that is given to the function in this specification. Functions that
        are identified as anonymous functions use the empty String as the value of
        the "name" property. For functions that are specified as properties of
        objects, the name value is the property name string used to access the
        function.

        Unless otherwise specified, the "name" property of a built-in function object
        has the attributes { [[Writable]]: false, [[Enumerable]]: false,
        [[Configurable]]: true }.

    ecma_intl implementation notes:

    PHP methods/functions do not have properties, since they aren't objects
    themselves, but we can get the name of a function using the Reflection API.
*/

use Ecma\Intl;

$reflected = new ReflectionMethod(Intl::class, 'supportedValuesOf');

test("its name is 'supportedValuesOf'")
    ->expect($reflected->getName())
    ->toBe('supportedValuesOf');
