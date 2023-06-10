--TEST--
Intl::supportedValuesOf(collation) contains only BCP47 values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$disallowedValues = [
    'dictionary',
    'gb2312han',
    'phonebook',
    'traditional',
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
