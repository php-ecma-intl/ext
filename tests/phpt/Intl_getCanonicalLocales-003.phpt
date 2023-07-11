--TEST--
Intl::getCanonicalLocales() throws value error for non-string element
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$canonicalized = Intl::getCanonicalLocales([
    'sl-rozaj-biske-1994',
    'CMN-hANS',
    1234,
    'sgn-GR',
]);

--EXPECTF--
Fatal error: Uncaught TypeError: The $locales argument must be of type string or an array of type string in %s/Intl_getCanonicalLocales-003.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-003.php(%d): Ecma\Intl::getCanonicalLocales(Array)
#1 {main}
  thrown in %s/Intl_getCanonicalLocales-003.php on line %d
