--TEST--
Options properties are readonly
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale\Options;

$properties = [
    'calendar' => 'gregory',
    'caseFirst' => 'upper',
    'collation' => 'emoji',
    'hourCycle' => 'h23',
    'language' => 'en',
    'numberingSystem' => 'latn',
    'numeric' => true,
    'region' => 'US',
    'script' => 'Latn',
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
Cannot modify readonly property Ecma\Intl\Locale\Options::$calendar
Cannot modify readonly property Ecma\Intl\Locale\Options::$caseFirst
Cannot modify readonly property Ecma\Intl\Locale\Options::$collation
Cannot modify readonly property Ecma\Intl\Locale\Options::$hourCycle
Cannot modify readonly property Ecma\Intl\Locale\Options::$language
Cannot modify readonly property Ecma\Intl\Locale\Options::$numberingSystem
Cannot modify readonly property Ecma\Intl\Locale\Options::$numeric
Cannot modify readonly property Ecma\Intl\Locale\Options::$region
Cannot modify readonly property Ecma\Intl\Locale\Options::$script
