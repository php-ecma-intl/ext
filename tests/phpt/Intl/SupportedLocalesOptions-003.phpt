--TEST--
SupportedLocalesOptions can access each property
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

$options = new SupportedLocalesOptions(
    localeMatcher: 'lookup',
);

var_dump($options->localeMatcher);

--EXPECT--
string(6) "lookup"
