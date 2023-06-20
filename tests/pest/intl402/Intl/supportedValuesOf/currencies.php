<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/2f0193d4cf583091f7717b7851270a75a78826e4/test/intl402/Intl/supportedValuesOf/currencies.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      The returned "currency" values are sorted, unique, and upper-case canonicalised.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      ...
      4. Else if key is "currency", then
        a. Let list be ! AvailableCurrencies( ).
      ...
      9. Return ! CreateArrayFromList( list ).

      AvailableCurrencies ( )
        The AvailableCurrencies abstract operation returns a List, ordered as if an
        Array of the same values had been sorted using %Array.prototype.sort% using
        undefined as comparefn, that contains unique, well-formed, and upper case
        canonicalized 3-letter ISO 4217 currency codes, identifying the currencies
        for which the implementation provides the functionality of Intl.DisplayNames
        and Intl.NumberFormat objects.
*/

use Ecma\Intl;
use Ecma\Intl\Category;

$currencies = Intl::supportedValuesOf(Category::Currency);

it('returns an array')
    ->expect($currencies)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherCalendars = Intl::supportedValuesOf(Category::Currency);
        sort($otherCalendars);

        return $otherCalendars;
    })
    ->toBe($currencies);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::Currency)))
    ->toHaveCount(count($currencies));

it('is a 3-letter ISO 4217 currency code')
    ->with($currencies)
    ->expect(fn (string $currency): string => $currency)
    ->toMatch(CURRENCY_PATTERN);
