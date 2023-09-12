--TEST--
ecma_intl.default_locale cannot recognize underscores in locale IDs
--EXTENSIONS--
ecma_intl
--INI--
ecma_intl.default_locale=en_US_POSIX
--FILE--
<?php
declare(strict_types=1);

var_dump(ini_get('ecma_intl.default_locale'));

--EXPECT--
string(0) ""
