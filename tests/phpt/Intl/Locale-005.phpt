--TEST--
Locale::$baseName is readonly 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale;

$locale = new Locale('cmn-hans-cn-u-ca-t-ca-x-t-u');

$locale->baseName = 'foo';

--EXPECTF--
Fatal error: Uncaught Error: Cannot modify readonly property Ecma\Intl\Locale::$baseName in %s/Intl/Locale-005.php:%d
Stack trace:
#0 {main}
  thrown in %s/Intl/Locale-005.php on line %d
