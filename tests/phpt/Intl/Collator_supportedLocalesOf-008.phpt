--TEST--
Collator::supportedLocalesOf with a NULL value
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$result = Collator::supportedLocalesOf(null);

var_export($result);

--EXPECT--
array (
)
