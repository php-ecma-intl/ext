--TEST--
ecma_intl.default_locale can be reset to empty
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=en_US
--FILE--
<?php
declare(strict_types=1);

var_dump(ini_set('ecma_intl.default_locale', ''));
var_dump(ini_get('ecma_intl.default_locale'));

--EXPECT--
string(5) "en_US"
string(0) ""
