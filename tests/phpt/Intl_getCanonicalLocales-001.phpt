--TEST--
Intl::getCanonicalLocales() canonicalizes string values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$canonicalized = Intl::getCanonicalLocales('cmn-hans-cn-u-ca-t-ca-x-t-u');

var_export($canonicalized);

--EXPECT--
array (
  0 => 'zh-Hans-CN-t-ca-u-ca-x-t-u',
)
