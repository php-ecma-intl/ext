--TEST--
Locale::getCollations() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en-US'))->getCollations()) . "\n";
echo json_encode((new Locale('en-US', new Options(collation: 'phonebk')))->getCollations()) . "\n";
echo json_encode((new Locale('en-US-u-co-trad'))->getCollations()) . "\n";
echo json_encode((new Locale('de-DE'))->getCollations()) . "\n";
echo json_encode((new Locale('es-MX'))->getCollations()) . "\n";

--EXPECT--
["emoji","eor"]
["phonebk"]
["trad"]
["phonebk","emoji","eor"]
["trad","emoji","eor"]
