--TEST--
Locale::getTimeZones() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en-GB'))->getTimeZones()) . "\n";
echo json_encode((new Locale('en-GB'))->timeZones) . "\n";
echo json_encode((new Locale('en'))->getTimeZones()) . "\n";
echo json_encode((new Locale('en'))->timeZones) . "\n";
echo json_encode((new Locale('en-ZZ'))->getTimeZones()) . "\n";
echo json_encode((new Locale('en-ZZ'))->timeZones) . "\n";

--EXPECT--
["Europe\/London"]
["Europe\/London"]
null
null
[]
[]
