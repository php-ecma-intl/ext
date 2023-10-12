--TEST--
Intl::defaultLocale() returns a new instance on each call
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=en_us
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$defaultLocale1 = Intl::defaultLocale();
$defaultLocale2 = Intl::defaultLocale();
$defaultLocale3 = Intl::defaultLocale();

var_dump($defaultLocale1->toString());
var_dump($defaultLocale2->toString());
var_dump($defaultLocale3->toString());
var_dump($defaultLocale1 === $defaultLocale2);
var_dump($defaultLocale2 === $defaultLocale3);

--EXPECT--
string(5) "en-US"
string(5) "en-US"
string(5) "en-US"
bool(false)
bool(false)
