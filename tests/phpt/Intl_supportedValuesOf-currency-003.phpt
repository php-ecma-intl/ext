--TEST--
Intl::supportedValuesOf(currency) returns only uppercase strings
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Category;

$values = Intl::supportedValuesOf(Category::Currency);

echo json_encode($values) . "\n";

foreach ($values as $value) {
    if (!is_string($value)) {
        printf("Expected string but received %s\n", gettype($value));
    } elseif (preg_match('/^[A-Z]+$/', $value) === 0) {
        printf("Expected only uppercase letters in value \"%s\"\n", $value);
    }
}

--EXPECTF--
[%s]
