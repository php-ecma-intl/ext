--TEST--
Intl::supportedValuesOf(collation) is sorted and unique
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$sortedValues = [];
$values = Intl::supportedValuesOf(Intl\Category::Collation);

assert(is_array($values));
echo json_encode($values) . "\n";

$sortedValues = array_map(fn (string $v): $v => strtolower($v), $values);
$sortedValues = array_unique($sortedValues);
sort($sortedValues);

if ($sortedValues !== $values) {
    echo "Expected collation values to be sorted, all lowercase, and have unique values.\n";
}

--EXPECTF--
%s
