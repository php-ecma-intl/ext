--TEST--
Locale exports with properties
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$locale = new Locale('en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-cu-usd');

var_export($locale);

--EXPECTF--
\Ecma\Intl\Locale::__set_state(array(
   'baseName' => 'en-Latn-US',
   'calendar' => 'gregory',
   'calendars' => 
  array (
    0 => 'gregory',
  ),
   'caseFirst' => 'upper',
   'collation' => 'emoji',
   'collations' => 
  array (
    0 => 'emoji',
  ),
   'currencies' => 
  array (
    0 => 'USD',
  ),
   'currency' => 'USD',
   'hourCycle' => 'h23',
   'hourCycles' => 
  array (
    0 => 'h23',
  ),
   'language' => 'en',
   'numberingSystem' => 'latn',
   'numberingSystems' => 
  array (
    0 => 'latn',
  ),
   'numeric' => true,
   'region' => 'US',
   'script' => 'Latn',
   'textInfo' => 
  \Ecma\Intl\Locale\TextInfo::__set_state(array(
     'direction' => 
    \Ecma\Intl\Locale\CharacterDirection::LeftToRight,
  )),
   'timeZones' => 
  array (%A
    %d => 'America/Chicago',%A
    %d => 'America/Denver',%A
    %d => 'America/Los_Angeles',%A
    %d => 'America/New_York',%A
  ),
   'weekInfo' => 
  \Ecma\Intl\Locale\WeekInfo::__set_state(array(
     'firstDay' => 
    \Ecma\Intl\Locale\WeekDay::Sunday,
     'minimalDays' => 1,
     'weekend' => 
    array (
      0 => 
      \Ecma\Intl\Locale\WeekDay::Saturday,
      1 => 
      \Ecma\Intl\Locale\WeekDay::Sunday,
    ),
  )),
))
