--TEST--
Intl::supportedValuesOf(collation) returns values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$values = Intl::supportedValuesOf(Intl\Category::Collation);

assert(is_array($values), sprintf('collation values is %s instead of array', gettype($values)));
assert(count($values) > 0, 'collation values count must be greater than zero');

echo json_encode($values) . "\n";
echo count($values) . "\n";

--EXPECTF--
%s
%d
