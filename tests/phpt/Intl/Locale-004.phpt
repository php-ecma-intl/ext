--TEST--
Locale serializes to JSON with properties
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale;

$locale = new Locale('cmn-hans-cn-u-ca-t-ca-x-t-u');

echo json_encode($locale) . "\n";

--EXPECT--
{"baseName":"zh-Hans-CN"}
