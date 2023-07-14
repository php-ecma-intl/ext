<?php

declare(strict_types=1);

// PHP arrays and iterables don't have "length" properties, so this test is a
// no-op test on purpose. It exists for the sake of parity with the Test262
// test suite.

it('getCanonicalLocales does not have a length property')
    ->expect(true)
    ->toBe(true);
