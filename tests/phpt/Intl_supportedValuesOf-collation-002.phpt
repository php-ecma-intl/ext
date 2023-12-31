--TEST--
Intl::supportedValuesOf(collation) must not include "search" or "standard"
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$disallowedValues = [
    'search',
    'standard',
];

$values = Intl::supportedValuesOf(Category::Collation);

echo json_encode($values) . "\n";

foreach ($disallowedValues as $disallowedValue) {
    if (in_array($disallowedValue, $values)) {
        printf("collation values must not include \"%s\"\n", $disallowedValue);
    }
}

--EXPECTF--
[%s]
