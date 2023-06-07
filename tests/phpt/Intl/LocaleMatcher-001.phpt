--TEST--
LocaleMatcher enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\LocaleMatcher;

foreach (LocaleMatcher::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
BestFit - best fit
Lookup - lookup
