--TEST--
Category enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Category;

foreach (Category::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
Calendar - calendar
Collation - collation
Currency - currency
NumberingSystem - numberingSystem
TimeZone - timeZone
Unit - unit
