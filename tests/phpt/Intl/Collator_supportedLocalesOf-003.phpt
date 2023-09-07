--TEST--
Collator::supportedLocalesOf uses "lookup" matcher
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;
use Ecma\Intl\SupportedLocales\Options;

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
        $newStringable('ban'),
        $newStringable('de'),
        $newStringable('en-US-u-co-emoji-ca-gregory'),
        $newStringable('en-GB'),
        $newStringable('en-Latn-US'),
    ],
    new Options(localeMatcher: 'lookup'),
);

var_export($result);

--EXPECT--
array (
  0 => 'de',
  1 => 'en-US-u-ca-gregory-co-emoji',
  2 => 'en-GB',
  3 => 'en-Latn-US',
)
