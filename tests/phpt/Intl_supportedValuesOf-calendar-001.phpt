--TEST--
Intl::supportedValuesOf(calendar) returns values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$values = Intl::supportedValuesOf(Category::Calendar);

echo json_encode($values) . "\n";
echo count($values) . "\n";

if (!is_array($values)) {
    printf("calendar values is %s instead of array\n", gettype($values));
}

if (count($values) === 0) {
    echo "calendar values count must be greater than zero\n";
}

--EXPECTF--
[%s]
%d
