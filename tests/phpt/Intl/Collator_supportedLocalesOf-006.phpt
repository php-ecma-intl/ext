--TEST--
Collator::supportedLocalesOf with no matching locales
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$result = Collator::supportedLocalesOf(
    'ban',
);

var_export($result);

--EXPECT--
array (
)
