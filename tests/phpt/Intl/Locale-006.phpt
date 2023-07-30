--TEST--
Locale can access each property
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$locale = new Locale('en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn');

var_dump($locale->baseName);
var_dump($locale->calendar);
var_dump($locale->caseFirst);
var_dump($locale->collation);
var_dump($locale->hourCycle);
var_dump($locale->language);
var_dump($locale->numberingSystem);
var_dump($locale->numeric);
var_dump($locale->region);
var_dump($locale->script);

--EXPECT--
string(10) "en-Latn-US"
string(7) "gregory"
string(5) "upper"
string(5) "emoji"
string(3) "h23"
string(2) "en"
string(4) "latn"
bool(true)
string(2) "US"
string(4) "Latn"
