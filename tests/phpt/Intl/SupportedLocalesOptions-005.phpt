--TEST--
SupportedLocalesOptions properties are readonly
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

$properties = [
    'localeMatcher' => 'best fit',
];

$options = new SupportedLocalesOptions();

foreach ($properties as $property => $value) {
    assert($options->{$property} === null);
    
    try {
        $options->{$property} = $value;
    } catch (Error $error) {
        echo $error->getMessage() . "\n";
    }
}

--EXPECT--
Cannot modify readonly property Ecma\Intl\SupportedLocalesOptions::$localeMatcher
