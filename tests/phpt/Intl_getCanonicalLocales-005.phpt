--TEST--
Intl::getCanonicalLocales() throws value error for invalid tag in array
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$canonicalized = Intl::getCanonicalLocales([
    'sl-rozaj-biske-1994',
    'CMN-hANS',
    'not a valid tag',
    'sgn-GR',
]);

--EXPECTF--
Fatal error: Uncaught ValueError: Invalid language tag "not a valid tag" in %s/Intl_getCanonicalLocales-005.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-005.php(%d): Ecma\Intl::getCanonicalLocales(Array)
#1 {main}
  thrown in %s/Intl_getCanonicalLocales-005.php on line %d
