--TEST--
SupportedLocales\Options can access each property
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$options = new Options(
    localeMatcher: 'lookup',
);

var_dump($options->localeMatcher);

--EXPECT--
string(6) "lookup"
