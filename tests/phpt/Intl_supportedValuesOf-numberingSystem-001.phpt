--TEST--
Intl::supportedValuesOf(numberingSystem) returns values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;
use Ecma\Intl\Category;

$values = Intl::supportedValuesOf(Category::NumberingSystem);

echo json_encode($values) . "\n";
echo count($values) . "\n";

if (!is_array($values)) {
    printf("numberingSystem values is %s instead of array\n", gettype($values));
}

if (count($values) === 0) {
    echo "numberingSystem values count must be greater than zero\n";
}

--EXPECTF--
[%s]
%d
