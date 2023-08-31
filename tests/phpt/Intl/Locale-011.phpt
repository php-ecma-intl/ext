--TEST--
Locale handles currency properly
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$tests = [
    'en',
    'en-us',
    'en-US-u-cu-EUR',
    'en-US-u-cu-xx',
    'en-US-u-cu-xxx',
    'en-US-u-cu-xxxx',
];

foreach ($tests as $test) {
    $locale = new Locale($test);

    echo 'Locale: ' . $locale->toString() . "\n";
    echo '  currencies: ' . json_encode($locale->currencies) . "\n";
    echo '  currency:   ' . json_encode($locale->currency) . "\n";
    echo "\n";
}

--EXPECTF--
Locale: en
  currencies: ["USD","USN"]
  currency:   null

Locale: en-US
  currencies: ["USD","USN"]
  currency:   null

Locale: en-US-u-cu-eur
  currencies: ["EUR"]
  currency:   "EUR"

Locale: en-US-u-cu-xx
  currencies: ["USD","USN"]
  currency:   null

Locale: en-US-u-cu-xxx
  currencies: ["XXX"]
  currency:   "XXX"

Locale: en-US-u-cu-xxxx
  currencies: ["USD","USN"]
  currency:   null
