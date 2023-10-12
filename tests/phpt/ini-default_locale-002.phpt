--TEST--
ecma_intl.default_locale has a value when set to a valid value
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=en-US
--FILE--
<?php
declare(strict_types=1);

var_dump(ini_get('ecma_intl.default_locale'));

--EXPECT--
string(5) "en-US"
