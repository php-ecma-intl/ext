--TEST--
Intl::defaultLocale() returns the INI-configured locale
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=en_us
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$defaultLocale = Intl::defaultLocale();

var_dump($defaultLocale->toString());

--EXPECT--
string(5) "en-US"
