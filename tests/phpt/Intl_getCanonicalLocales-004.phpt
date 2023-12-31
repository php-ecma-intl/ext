--TEST--
Intl::getCanonicalLocales() throws ValueError for invalid tag string
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$canonicalized = Intl::getCanonicalLocales('foo bar');

--EXPECTF--
Fatal error: Uncaught ValueError: Invalid language tag "foo bar" in %s/Intl_getCanonicalLocales-004.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-004.php(%d): Ecma\Intl::getCanonicalLocales('foo bar')
#1 {main}
  thrown in %s/Intl_getCanonicalLocales-004.php on line %d
