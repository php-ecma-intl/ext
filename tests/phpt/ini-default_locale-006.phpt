--TEST--
ecma_intl.default_locale can be set from the application
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=
--FILE--
<?php
declare(strict_types=1);

var_dump(ini_set('ecma_intl.default_locale', 'en-US'));
var_dump(ini_set('ecma_intl.default_locale', 'foobar'));
var_dump(ini_set('ecma_intl.default_locale', 'en-Latn-US'));
var_dump(ini_set('ecma_intl.default_locale', 'en-US-POSIX'));
var_dump(ini_set('ecma_intl.default_locale', 'de'));
var_dump(ini_get('ecma_intl.default_locale'));

--EXPECT--
string(0) ""
bool(false)
string(5) "en-US"
string(10) "en-Latn-US"
string(11) "en-US-POSIX"
string(2) "de"
