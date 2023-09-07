--TEST--
Collator::supportedLocalesOf with an empty array
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$result = Collator::supportedLocalesOf([]);

var_export($result);

--EXPECT--
array (
)
