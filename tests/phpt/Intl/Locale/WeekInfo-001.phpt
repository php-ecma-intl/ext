--TEST--
WeekInfo creation and JSON serialization
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\WeekDay;
use Ecma\Intl\Locale\WeekInfo;

$weekInfo1 = new WeekInfo(WeekDay::Monday, [WeekDay::Saturday, WeekDay::Sunday], 1);
$weekInfo2 = new WeekInfo(WeekDay::Sunday, [WeekDay::Thursday, WeekDay::Saturday], 3);

echo json_encode($weekInfo1) . "\n";
echo json_encode($weekInfo2) . "\n";

--EXPECT--
{"firstDay":1,"weekend":[6,7],"minimalDays":1}
{"firstDay":7,"weekend":[4,6],"minimalDays":3}
