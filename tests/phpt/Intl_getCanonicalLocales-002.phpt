--TEST--
Intl::getCanonicalLocales() canonicalizes array values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$canonicalized = Intl::getCanonicalLocales([
    'sl-rozaj-biske-1994',
    'cmn-hans-cn-u-ca-t-ca-x-t-u',
    'CMN-hANS',
    'sgn-GR',
]);

var_export($canonicalized);

--EXPECT--
array (
  0 => 'sl-1994-biske-rozaj',
  1 => 'zh-Hans-CN-t-ca-u-ca-x-t-u',
  2 => 'zh-Hans',
  3 => 'gss',
)
