--TEST--
Intl::supportedValuesOf(timeZone) is sorted and unique
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$values = Intl::supportedValuesOf(Category::TimeZone);
$uniqueSortedValues = [];

echo json_encode($values) . "\n";

$uniqueSortedValues = array_unique($values);
sort($uniqueSortedValues);

if ($uniqueSortedValues !== $values) {
    echo "Expected timeZone values to be sorted and have unique values.\n";
}

--EXPECTF--
[%s]
