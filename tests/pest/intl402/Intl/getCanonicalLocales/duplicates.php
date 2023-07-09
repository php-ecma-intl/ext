<?php

/**
 * Portions of this file are
 * Copyright 2016 Mozilla Corporation. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

declare(strict_types=1);

use Ecma\Intl;

it('removes duplicate locales after canonicalizing')
    ->expect(Intl::getCanonicalLocales(['ab-cd', 'ff', 'de-rt', 'ab-Cd']))
    ->toBe(['ab-CD', 'ff', 'de-RT']);

it('removes duplicate identical locales')
    ->expect(Intl::getCanonicalLocales(['en-US', 'en-US']))
    ->toBe(['en-US']);
