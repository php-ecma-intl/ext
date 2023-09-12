--TEST--
ecma_intl.default_locale has an empty string when set to an invalid value
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=foobar
--FILE--
<?php
declare(strict_types=1);

var_dump(ini_get('ecma_intl.default_locale'));

--EXPECT--
string(0) ""
