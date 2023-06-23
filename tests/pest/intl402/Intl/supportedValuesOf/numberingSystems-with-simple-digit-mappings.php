<?php

/**
 * Portions of this file are
 * Copyright (C) 2021 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

use Ecma\Intl;
use Ecma\Intl\Category;

$numberingSystems = Intl::supportedValuesOf(Category::NumberingSystem);

it('includes numbering systems with simple digit mappings')
    ->with(array_keys(NUMBERING_SYSTEM_DIGITS))
    ->expect(fn (string $numberingSystem): string => $numberingSystem)
    ->toBeIn($numberingSystems);
