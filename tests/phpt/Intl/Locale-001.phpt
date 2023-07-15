--TEST--
Locale casts to string
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale;

$locale = new Locale('cmn-hans-cn-u-ca-t-ca-x-t-u');

echo $locale;

--EXPECT--
zh-Hans-CN-t-ca-u-ca-x-t-u
