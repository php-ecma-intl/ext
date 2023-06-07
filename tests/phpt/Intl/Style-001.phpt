--TEST--
Style enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Style;

foreach (Style::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
Long - long
Narrow - narrow
Short - short
