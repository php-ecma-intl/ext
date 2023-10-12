--TEST--
Intl::defaultLocale() falls back to the ICU default
--EXTENSIONS--
ecma_intl
--ENV--
LC_ALL=
--INI--
ecma_intl.default_locale=
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$defaultLocale = Intl::defaultLocale();
var_dump($defaultLocale->toString());
var_dump(strlen($defaultLocale->toString()) > 0);

--EXPECTF--
string(%d) "%s"
bool(true)
