--TEST--
CharacterDirection enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\CharacterDirection;

foreach (CharacterDirection::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
LeftToRight - ltr
RightToLeft - rtl
