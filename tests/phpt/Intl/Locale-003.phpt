--TEST--
Locale exports with properties
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale;

$locale = new Locale('cmn-hans-cn-u-ca-t-ca-x-t-u');

var_export($locale);

--EXPECT--
\Ecma\Intl\Locale::__set_state(array(
   'baseName' => 'zh-Hans-CN',
   'calendar' => 'yes',
   'caseFirst' => NULL,
   'collation' => NULL,
   'hourCycle' => NULL,
   'language' => 'zh',
   'numberingSystem' => NULL,
   'numeric' => false,
   'region' => 'CN',
   'script' => 'Hans',
))
