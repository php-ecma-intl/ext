<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/d52a5bbbe88b82bee0122689c161f1bf15fe8a0d/test/intl402/Intl/supportedValuesOf/numberingSystems-with-simple-digit-mappings.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      The returned "numberingSystem" values contain all numbering systems with simple digit mappings.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      ...
      5. Else if key is "numberingSystem", then
        a. Let list be ! AvailableNumberingSystems( ).
      ...
      9. Return ! CreateArrayFromList( list ).

      AvailableNumberingSystems ( )
        The AvailableNumberingSystems abstract operation returns a List, ordered as
        if an Array of the same values had been sorted using %Array.prototype.sort%
        using undefined as comparefn, that contains unique numbering systems
        identifiers identifying the numbering systems for which the implementation
        provides the functionality of Intl.DateTimeFormat, Intl.NumberFormat, and
        Intl.RelativeTimeFormat objects. The list must include the Numbering System
        value of every row of Table 4, except the header row.
*/

use Ecma\Intl;
use Ecma\Intl\Category;

$numberingSystems = Intl::supportedValuesOf(Category::NumberingSystem);

it('includes numbering systems with simple digit mappings')
    ->with(array_keys(NUMBERING_SYSTEM_DIGITS))
    ->expect(fn (string $numberingSystem): string => $numberingSystem)
    ->toBeIn($numberingSystems);
