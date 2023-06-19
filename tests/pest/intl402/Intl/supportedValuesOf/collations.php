<?php

/**
 * Adapted from Test262: ECMAScript Test Suite
 *
 * Original test code from Test262 is copyright (c) André Bargull and used under
 * the terms of the BSD License.
 *
 * Test262: https://github.com/tc39/test262
 * License: https://github.com/tc39/test262/blob/main/LICENSE
 * Original test: https://github.com/tc39/test262/blob/c4642dd714175b5d27939c920abc6059c9fddb06/test/intl402/Intl/supportedValuesOf/collations.js
 */

/*
    esid: sec-intl.supportedvaluesof
    description: >
      The returned "collation" values are sorted, unique, and match the type production.
    info: |
      Intl.supportedValuesOf ( key )

      1. Let key be ? ToString(key).
      ...
      3. Else if key is "collation", then
        a. Let list be ! AvailableCollations( ).
      ...
      9. Return ! CreateArrayFromList( list ).

      AvailableCollations ( )
        The AvailableCollations abstract operation returns a List, ordered as if an
        Array of the same values had been sorted using %Array.prototype.sort% using
        undefined as comparefn, that contains unique collation types identifying the
        collations for which the implementation provides the functionality of
        Intl.Collator objects.
*/

use Ecma\Intl;
use Ecma\Intl\Category;

$collations = Intl::supportedValuesOf(Category::Collation);

it('returns an array')
    ->expect($collations)
    ->toBeArray();

it('sorts the array')
    ->expect(function (): array {
        $otherCollations = Intl::supportedValuesOf(Category::Collation);
        sort($otherCollations);

        return $otherCollations;
    })
    ->toBe($collations);

it("doesn't contain duplicates")
    ->expect(array_unique(Intl::supportedValuesOf(Category::Collation)))
    ->toHaveCount(count($collations));

it("matches the 'type' production")
    ->with($collations)
    ->expect(fn (string $collation): string => $collation)
    ->toMatch(TYPE_VALUE_PATTERN);

it("does not include the 'standard' collation type")
    ->expect($collations)
    ->not()
    ->toContain('standard');

it("does not include the 'search' collation type")
    ->expect($collations)
    ->not()
    ->toContain('search');
