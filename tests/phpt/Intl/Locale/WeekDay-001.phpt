--TEST--
WeekDay enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\WeekDay;

foreach (WeekDay::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
Monday - 1
Tuesday - 2
Wednesday - 3
Thursday - 4
Friday - 5
Saturday - 6
Sunday - 7
