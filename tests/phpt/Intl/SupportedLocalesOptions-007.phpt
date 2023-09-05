--TEST--
SupportedLocalesOptions can be combined with array unpacking
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

$options1 = new SupportedLocalesOptions(localeMatcher: 'best fit');
$options2 = new SupportedLocalesOptions(localeMatcher: 'lookup');

echo json_encode(new SupportedLocalesOptions(...[...$options1, ...$options2])) . "\n";
echo json_encode(new SupportedLocalesOptions(...[...$options2, ...$options1])) . "\n";

--EXPECT--
{"localeMatcher":"lookup"}
{"localeMatcher":"best fit"}
