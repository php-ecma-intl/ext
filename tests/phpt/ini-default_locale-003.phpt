--TEST--
ecma_intl.default_locale can be set to en-US-POSIX
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=en-US-POSIX
--FILE--
<?php
declare(strict_types=1);

var_dump(ini_get('ecma_intl.default_locale'));

--EXPECT--
string(11) "en-US-POSIX"
