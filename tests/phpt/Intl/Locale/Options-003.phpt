--TEST--
Options can access each property
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$options = new Options(
    calendar: 'gregory',
    caseFirst: 'upper',
    collation: 'emoji',
    hourCycle: 'h23',
    language: 'en',
    numberingSystem: 'latn',
    numeric: true,
    region: 'US',
    script: 'Latn',
);

var_dump($options->calendar);
var_dump($options->caseFirst);
var_dump($options->collation);
var_dump($options->hourCycle);
var_dump($options->language);
var_dump($options->numberingSystem);
var_dump($options->numeric);
var_dump($options->region);
var_dump($options->script);

--EXPECT--
string(7) "gregory"
string(5) "upper"
string(5) "emoji"
string(3) "h23"
string(2) "en"
string(4) "latn"
bool(true)
string(2) "US"
string(4) "Latn"
