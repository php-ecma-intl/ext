--TEST--
SupportedLocales\Options properties are readonly
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$properties = [
    'localeMatcher' => 'best fit',
];

$options = new Options();

foreach ($properties as $property => $value) {
    assert($options->{$property} === null);
    
    try {
        $options->{$property} = $value;
    } catch (Error $error) {
        echo $error->getMessage() . "\n";
    }
}

--EXPECT--
Cannot modify readonly property Ecma\Intl\SupportedLocales\Options::$localeMatcher
