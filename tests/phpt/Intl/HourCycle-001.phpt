--TEST--
HourCycle enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\HourCycle;

foreach (HourCycle::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
H11 - h11
H12 - h12
H23 - h23
H24 - h24
