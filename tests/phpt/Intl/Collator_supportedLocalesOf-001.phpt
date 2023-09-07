--TEST--
Collator::supportedLocalesOf returns supported locales
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
    [
        'en-US',
        'foobar',
        $newStringable('en-US'),
        'en-Latn-US',
        $newStringable('en-Latn-US'),
        'ban',
        'de',
        $newStringable('ban'),
        'en-GB',
    ],
);

var_export($result);

--EXPECT--
array (
  0 => 'en-US',
  1 => 'en-Latn-US',
  2 => 'de',
  3 => 'en-GB',
)
