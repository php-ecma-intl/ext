<?php

declare(strict_types=1);

use Ecma\Intl;

$locales = [
    new class {
        public function __toString(): string { return 'en-US'; }
    },
    new class {
        public function __toString(): string { return 'pt-BR'; }
    },
];

it('calls toString() on Stringable objects')
    ->expect(Intl::getCanonicalLocales($locales))
    ->toBe(['en-US', 'pt-BR']);
