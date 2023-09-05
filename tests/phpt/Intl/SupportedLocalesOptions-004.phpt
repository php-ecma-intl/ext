--TEST--
SupportedLocalesOptions can set each property to null
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

$options = new SupportedLocalesOptions(
    localeMatcher: null,
);

var_dump($options->localeMatcher);

--EXPECT--
NULL
