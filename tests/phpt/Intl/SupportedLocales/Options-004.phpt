--TEST--
SupportedLocales\Options can set each property to null
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$options = new Options(
    localeMatcher: null,
);

var_dump($options->localeMatcher);

--EXPECT--
NULL
