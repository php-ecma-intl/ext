--TEST--
Intl::supportedValuesOf(calendar) returns only strings
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$values = Intl::supportedValuesOf(Category::Calendar);

echo json_encode($values) . "\n";

foreach ($values as $value) {
    if (!is_string($value)) {
        printf("Expected string but received %s\n", gettype($value));
    }
}

--EXPECTF--
[%s]
