--TEST--
Intl::defaultLocale() changes when ini_set() changes the default locale
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$tests = [
    'en-US',
    'deu_deu',
    'fr-FR',
    '',
    'de-DE',
    'en_US_POSIX',
];

foreach ($tests as $test) {
    ini_set('ecma_intl.default_locale', $test);
    $defaultLocale = Intl::defaultLocale();
    var_dump($defaultLocale->toString());
}

--EXPECTF--
string(5) "en-US"
string(5) "de-DE"
string(5) "fr-FR"
string(%d) "%s"
string(5) "de-DE"
string(16) "en-US-u-va-posix"
