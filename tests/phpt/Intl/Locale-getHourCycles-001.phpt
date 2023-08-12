--TEST--
Locale::getHourCycles() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en-US'))->getHourCycles()) . "\n";
echo json_encode((new Locale('en-US-u-hc-h24'))->getHourCycles()) . "\n";
echo json_encode((new Locale('en-US', new Options(hourCycle: 'h11')))->getHourCycles()) . "\n";

--EXPECT--
["h12"]
["h24"]
["h11"]
