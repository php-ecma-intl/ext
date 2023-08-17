--TEST--
Locale::getWeekInfo() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$tests = [
    'und-AF',
    'und-BH',
    'und-GB',
    'und-IN',
    'und-IR',
    'und-MV',
    'und-UG',
    'und-US',
    'und-YE',
];

foreach ($tests as $test) {
    $locale = new Locale($test);
    echo $locale->toString() . ' - ' . json_encode($locale->getWeekInfo()) . "\n";
}

--EXPECT--
und-AF - {"firstDay":6,"weekend":[4,5],"minimalDays":1}
und-BH - {"firstDay":6,"weekend":[5,6],"minimalDays":1}
und-GB - {"firstDay":1,"weekend":[6,7],"minimalDays":4}
und-IN - {"firstDay":7,"weekend":[7],"minimalDays":1}
und-IR - {"firstDay":6,"weekend":[5],"minimalDays":1}
und-MV - {"firstDay":5,"weekend":[6,7],"minimalDays":1}
und-UG - {"firstDay":1,"weekend":[7],"minimalDays":1}
und-US - {"firstDay":7,"weekend":[6,7],"minimalDays":1}
und-YE - {"firstDay":7,"weekend":[5,6],"minimalDays":1}
