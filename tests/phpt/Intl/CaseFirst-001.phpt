--TEST--
CaseFirst enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\CaseFirst;

foreach (CaseFirst::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
False - false
Lower - lower
Upper - upper
