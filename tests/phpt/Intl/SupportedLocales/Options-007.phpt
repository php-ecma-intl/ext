--TEST--
SupportedLocales\Options can be combined with array unpacking
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$options1 = new Options(localeMatcher: 'best fit');
$options2 = new Options(localeMatcher: 'lookup');

echo json_encode(new Options(...[...$options1, ...$options2])) . "\n";
echo json_encode(new Options(...[...$options2, ...$options1])) . "\n";

--EXPECT--
{"localeMatcher":"lookup"}
{"localeMatcher":"best fit"}
