<?php

declare(strict_types=1);

use Ecma\Intl;

it('removes duplicate locales after canonicalizing')
    ->expect(Intl::getCanonicalLocales(['ab-cd', 'ff', 'de-rt', 'ab-Cd']))
    ->toBe(['ab-CD', 'ff', 'de-RT']);

it('removes duplicate identical locales')
    ->expect(Intl::getCanonicalLocales(['en-US', 'en-US']))
    ->toBe(['en-US']);
