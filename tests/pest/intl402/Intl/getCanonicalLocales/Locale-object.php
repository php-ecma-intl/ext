<?php

declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Locale;

// @todo Implement Ecma\Intl\Locale class.
it('accepts Locale objects')
    ->expect(Intl::getCanonicalLocales([
        'fr-CA',
        // new Locale('en-gb-oxendict'),
        'de',
        // new Locale('jp', ['calendar' => 'gregory']),
        'zh',
        // new Locale('fr-CA'),
    ]))
    ->toBe([
        'fr-CA',
        // 'en-GB-oxendict',
        'de',
        // 'jp-u-ca-gregory',
        'zh',
    ]);
