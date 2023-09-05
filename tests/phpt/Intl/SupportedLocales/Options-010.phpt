--TEST--
SupportedLocales\Options supports full array unpacking
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$options = new Options(
    localeMatcher: 'best fit',
);

var_export([...$options]);

--EXPECT--
array (
  'localeMatcher' => 'best fit',
)
