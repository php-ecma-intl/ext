--TEST--
Locale properties are readonly
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$properties = [
    'baseName' => 'en-Latn-US',
    'calendar' => 'gregory',
    'calendars' => ['gregory'],
    'caseFirst' => 'upper',
    'collation' => 'emoji',
    'collations' => ['emoji'],
    'currencies' => ['usd'],
    'hourCycle' => 'h23',
    'hourCycles' => ['h23'],
    'language' => 'en',
    'numberingSystem' => 'latn',
    'numberingSystems' => ['latn'],
    'numeric' => true,
    'region' => 'US',
    'script' => 'Latn',
];

$locale = new Locale('en');

foreach ($properties as $property => $value) {
    try {
        $locale->{$property} = $value;
    } catch (Error $error) {
        echo $error->getMessage() . "\n";
    }
}

--EXPECTF--
Cannot modify readonly property Ecma\Intl\Locale::$baseName
Cannot modify readonly property Ecma\Intl\Locale::$calendar
Cannot modify readonly property Ecma\Intl\Locale::$calendars
Cannot modify readonly property Ecma\Intl\Locale::$caseFirst
Cannot modify readonly property Ecma\Intl\Locale::$collation
Cannot modify readonly property Ecma\Intl\Locale::$collations
Cannot modify readonly property Ecma\Intl\Locale::$currencies
Cannot modify readonly property Ecma\Intl\Locale::$hourCycle
Cannot modify readonly property Ecma\Intl\Locale::$hourCycles
Cannot modify readonly property Ecma\Intl\Locale::$language
Cannot modify readonly property Ecma\Intl\Locale::$numberingSystem
Cannot modify readonly property Ecma\Intl\Locale::$numberingSystems
Cannot modify readonly property Ecma\Intl\Locale::$numeric
Cannot modify readonly property Ecma\Intl\Locale::$region
Cannot modify readonly property Ecma\Intl\Locale::$script
