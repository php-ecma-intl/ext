--TEST--
Collator::supportedLocalesOf with a single Stringable
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$newStringable = function (string $value): object {
    return new class ($value) {
        public function __construct(private readonly string $value)
        {
        }
        
        public function __toString(): string
        {
            return $this->value;
        }
    };
};

$result = Collator::supportedLocalesOf(
    $newStringable('de-de-u-cu-EUR-ca-buddhist'),
);

var_export($result);

--EXPECT--
array (
  0 => 'de-DE-u-ca-buddhist-cu-eur',
)
