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
    12.34,
    'en-US',
]);

--EXPECTF--
Fatal error: Uncaught TypeError: Ecma\Intl::getCanonicalLocales(): Argument #1 ($locales) must be of type string or a Traversable|array of type string, int found in Traversable|array in %s/Intl_getCanonicalLocales-003.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-003.php(%d): Ecma\Intl::getCanonicalLocales(Array)
#1 {main}

Next TypeError: Ecma\Intl::getCanonicalLocales(): Argument #1 ($locales) must be of type string or a Traversable|array of type string, float found in Traversable|array in %s/Intl_getCanonicalLocales-003.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-003.php(%d): Ecma\Intl::getCanonicalLocales(Array)
#1 {main}
  thrown in %s/Intl_getCanonicalLocales-003.php on line %d
