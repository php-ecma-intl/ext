--TEST--
WeekInfo constructor exceptions
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\WeekDay;
use Ecma\Intl\Locale\WeekInfo;

$tests = [
    ['Sunday', [WeekDay::Saturday], 1],
    [WeekDay::Monday, [WeekDay::Saturday, 'Sunday'], 2],
    [WeekDay::Friday, [1234], 3],
    [WeekDay::Thursday, [WeekDay::Friday, WeekDay::Saturday], -1],
    [WeekDay::Tuesday, [WeekDay::Sunday, WeekDay::Monday, WeekDay::Tuesday], 0],
    [WeekDay::Wednesday, [], 8],
];

foreach ($tests as $test) {
    try {
        new WeekInfo(...$test);
    } catch (Throwable $exception) {
        echo get_class($exception) . ' : ' . $exception->getMessage() . "\n";
    }
}

--EXPECT--
TypeError : Ecma\Intl\Locale\WeekInfo::__construct(): Argument #1 ($firstDay) must be of type Ecma\Intl\Locale\WeekDay, string given
TypeError : Ecma\Intl\Locale\WeekInfo::__construct(): Argument #2 ($weekend) must be of type array<Ecma\Intl\Locale\WeekDay>, string found in array
TypeError : Ecma\Intl\Locale\WeekInfo::__construct(): Argument #2 ($weekend) must be of type array<Ecma\Intl\Locale\WeekDay>, int found in array
ValueError : Ecma\Intl\Locale\WeekInfo::__construct(): Argument #3 ($minimalDays) must be an integer from 1 to 7
ValueError : Ecma\Intl\Locale\WeekInfo::__construct(): Argument #3 ($minimalDays) must be an integer from 1 to 7
ValueError : Ecma\Intl\Locale\WeekInfo::__construct(): Argument #3 ($minimalDays) must be an integer from 1 to 7
