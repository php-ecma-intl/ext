--TEST--
Collator::supportedLocalesOf with a Generator
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$func = function (): Generator {
    yield 'en-US';
    yield 'fr';
    yield 'de';
    yield 'es-MX';
};

$generator = $func();

$result = Collator::supportedLocalesOf($generator);

var_export($result);

--EXPECT--
array (
  0 => 'en-US',
  1 => 'fr',
  2 => 'de',
  3 => 'es-MX',
)
