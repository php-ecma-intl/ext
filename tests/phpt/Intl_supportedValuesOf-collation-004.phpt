--TEST--
Intl::supportedValuesOf(collation) returns only strings
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;
use Ecma\Intl\Category;
use Ecma\Intl\Collation;

$values = Intl::supportedValuesOf(Category::Collation);

echo json_encode($values) . "\n";

foreach ($values as $value) {
    if (!is_string($value)) {
        printf("Expected string but received %s\n", gettype($value));
    }
}

--EXPECTF--
[%s]
