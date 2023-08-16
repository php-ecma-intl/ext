--TEST--
WeekInfo property accessors
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\WeekDay;
use Ecma\Intl\Locale\WeekInfo;

$weekInfo = new WeekInfo(WeekDay::Monday, [WeekDay::Saturday, WeekDay::Sunday], 1);

echo var_export($weekInfo->firstDay, true) . "\n";
echo var_export($weekInfo->weekend, true) . "\n";
echo $weekInfo->minimalDays . "\n";

--EXPECT--
\Ecma\Intl\Locale\WeekDay::Monday
array (
  0 => 
  \Ecma\Intl\Locale\WeekDay::Saturday,
  1 => 
  \Ecma\Intl\Locale\WeekDay::Sunday,
)
1
