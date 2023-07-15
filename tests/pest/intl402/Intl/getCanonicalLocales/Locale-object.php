<?php

declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Locale;

$stringable1 = new class () implements Stringable {
    public function __toString(): string
    {
        return 'de';
    }
};

// Implicit Stringable has __toString() but does not implement Stringable.
$stringable2 = new class () {
    public function __toString(): string
    {
        return 'zh';
    }
};

// @todo Implement Ecma\Intl\Locale class.
it('accepts Locale objects')
    ->expect(Intl::getCanonicalLocales([
        'fr-CA',
        // new Locale('en-gb-oxendict'),
        $stringable1,
        // new Locale('jp', ['calendar' => 'gregory']),
        $stringable2,
        // new Locale('fr-CA'),
    ]))
    ->toBe([
        'fr-CA',
        // 'en-GB-oxendict',
        'de',
        // 'jp-u-ca-gregory',
        'zh',
    ]);
