--TEST--
Intl::defaultLocale() defaults to the system value
--EXTENSIONS--
ecma_intl
--ENV--
LC_ALL=nld_nld
--INI--
ecma_intl.default_locale=
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$defaultLocale = Intl::defaultLocale();
var_dump($defaultLocale->toString());

--EXPECT--
string(5) "nl-NL"
