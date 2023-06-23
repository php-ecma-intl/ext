--TEST--
Intl::supportedValuesOf(unit) returns sanctioned values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;
use Ecma\Intl\Category;

$values = Intl::supportedValuesOf(Category::Unit);

echo json_encode($values) . "\n";
echo count($values) . "\n";

if (!is_array($values)) {
    printf("unit values is %s instead of array\n", gettype($values));
}

if (count($values) === 0) {
    echo "unit values count must be greater than zero\n";
}

--EXPECTF--
[%s]
%d
