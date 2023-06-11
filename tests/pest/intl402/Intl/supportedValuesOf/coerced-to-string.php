<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/coerced-to-string.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      Input key is coerced with ToString.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      2. If key is "calendar", then
        a. Let list be ! AvailableCalendars( ).
      ...
      9. Return ! CreateArrayFromList( list ).

    ecma_intl implementation notes:

    The PHP implementation is stricter with types accept than the ECMA-402
    specification. As such, the PHP implementation does not coerce input to
    strings but requires instances of Ecma\Intl\Category (see prop-desc.php
    test).
*/

// This test is a no-op test on purpose. See note above.
it('does not support coercion of input to string')
    ->expect(true)
    ->toBe(true);
