--TEST--
Locale::getCurrencies() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en-US'))->getCurrencies()) . "\n";
echo json_encode((new Locale('en-US-u-cu-uss'))->getCurrencies()) . "\n";
echo json_encode((new Locale('de-DE'))->getCurrencies()) . "\n";
echo json_encode((new Locale('es-MX'))->getCurrencies()) . "\n";
echo json_encode((new Locale('es'))->getCurrencies()) . "\n";
echo json_encode((new Locale('fr-CA'))->getCurrencies()) . "\n";
echo json_encode((new Locale('fr'))->getCurrencies()) . "\n";
echo json_encode((new Locale('fr-MG'))->getCurrencies()) . "\n";

--EXPECT--
["USD","USN"]
["USD","USN"]
["EUR"]
["MXN","MXV"]
["EUR"]
["CAD"]
["EUR"]
["MGA"]
