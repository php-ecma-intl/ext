--TEST--
Intl::supportedValuesOf(collation) returns only Collation cases
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;
use Ecma\Intl\Category;
use Ecma\Intl\Collation;

$values = Intl::supportedValuesOf(Category::Collation);
$uniqueSortedValues = [];

echo json_encode($values) . "\n";

foreach ($values as $value) {
    if (!$value instanceof Collation) {
        printf(
            "Expected %s but received %s\n",
            Collation::class,
            is_object($value) ? get_class($value) : gettype($value),
        );
    }
}

--EXPECTF--
[%s]
