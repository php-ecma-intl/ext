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
var_dump($locale->calendars);
var_dump($locale->caseFirst);
var_dump($locale->collation);
var_dump($locale->collations);
var_dump($locale->currencies);
var_dump($locale->hourCycle);
var_dump($locale->hourCycles);
var_dump($locale->language);
var_dump($locale->numberingSystem);
var_dump($locale->numberingSystems);
var_dump($locale->numeric);
var_dump($locale->region);
var_dump($locale->script);
var_dump($locale->textInfo);
var_dump($locale->timeZones);
var_dump($locale->weekInfo);

--EXPECTF--
string(10) "en-Latn-US"
string(7) "gregory"
array(1) {
  [0]=>
  string(7) "gregory"
}
string(5) "upper"
string(5) "emoji"
array(1) {
  [0]=>
  string(5) "emoji"
}
array(2) {
  [0]=>
  string(3) "USD"
  [1]=>
  string(3) "USN"
}
string(3) "h23"
array(1) {
  [0]=>
  string(3) "h23"
}
string(2) "en"
string(4) "latn"
array(1) {
  [0]=>
  string(4) "latn"
}
bool(true)
string(2) "US"
string(4) "Latn"
object(Ecma\Intl\Locale\TextInfo)#%d (1) {
  ["direction"]=>
  enum(Ecma\Intl\Locale\CharacterDirection::LeftToRight)
}
array(%d) {%A
  [%d]=>
  string(15) "America/Chicago"%A
  [%d]=>
  string(14) "America/Denver"%A
  [%d]=>
  string(19) "America/Los_Angeles"%A
  [%d]=>
  string(16) "America/New_York"%A
}
object(Ecma\Intl\Locale\WeekInfo)#%d (3) {
  ["firstDay"]=>
  enum(Ecma\Intl\Locale\WeekDay::Sunday)
  ["minimalDays"]=>
  int(1)
  ["weekend"]=>
  array(2) {
    [0]=>
    enum(Ecma\Intl\Locale\WeekDay::Saturday)
    [1]=>
    enum(Ecma\Intl\Locale\WeekDay::Sunday)
  }
}
