--TEST--
Collator::supportedLocalesOf with a single string
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$result = Collator::supportedLocalesOf(
    'de-DE-POSIX',
);

var_export($result);

--EXPECT--
array (
  0 => 'de-DE-u-va-posix',
)
