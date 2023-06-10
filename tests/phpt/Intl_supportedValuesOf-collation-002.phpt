--TEST--
Intl::supportedValuesOf(collation) must not include "search" or "standard"
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$disallowedValues = [
    'search',
    'standard',
];

$values = Intl::supportedValuesOf(Intl\Category::Collation);

assert(is_array($values));
echo json_encode($values) . "\n";

foreach ($disallowedValues as $disallowedValue) {
    if (in_array($disallowedValue, $values)) {
        echo "collation values must not include '$disallowedValue'\n";
    }
}

--EXPECTF--
%s
