--TEST--
Collator::supportedLocalesOf uses "best fit" matcher
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;
use Ecma\Intl\SupportedLocales\Options;

$result = Collator::supportedLocalesOf(
    [
        'ban',
        'de',
        'en-US-u-co-emoji-ca-gregory',
        'en-GB',
        'en-Latn-US',
    ],
    new Options(localeMatcher: 'best fit'),
);

var_export($result);

--EXPECT--
array (
  0 => 'de',
  1 => 'en-US-u-ca-gregory-co-emoji',
  2 => 'en-GB',
  3 => 'en-Latn-US',
)
