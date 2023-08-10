--TEST--
Locale exports with properties
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$locale = new Locale('en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn');

var_export($locale);

--EXPECT--
\Ecma\Intl\Locale::__set_state(array(
   'baseName' => 'en-Latn-US',
   'calendar' => 'gregory',
   'calendars' => 
  array (
    0 => 'gregory',
  ),
   'caseFirst' => 'upper',
   'collation' => 'emoji',
   'hourCycle' => 'h23',
   'language' => 'en',
   'numberingSystem' => 'latn',
   'numeric' => true,
   'region' => 'US',
   'script' => 'Latn',
))
