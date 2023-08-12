--TEST--
Locale::getNumberingSystems() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en-US'))->getNumberingSystems()) . "\n";
echo json_encode((new Locale('en-US-u-nu-arab'))->getNumberingSystems()) . "\n";
echo json_encode((new Locale('en-US', new Options(numberingSystem: 'arabext')))->getNumberingSystems()) . "\n";
echo json_encode((new Locale('fa'))->getNumberingSystems()) . "\n";

--EXPECT--
["latn"]
["arab"]
["arabext"]
["arabext"]
