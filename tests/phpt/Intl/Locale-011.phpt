--TEST--
Locale::getCalendars() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en'))->getCalendars()) . "\n";
echo json_encode((new Locale('en', new Options(calendar: 'buddhist')))->getCalendars()) . "\n";
echo json_encode((new Locale('zh'))->getCalendars()) . "\n";
echo json_encode((new Locale('jp'))->getCalendars()) . "\n";
echo json_encode((new Locale('jp-JP'))->getCalendars()) . "\n";
echo json_encode((new Locale('jp-JP', new Options(calendar: 'japanese')))->getCalendars()) . "\n";
echo json_encode((new Locale('und-Thai'))->getCalendars()) . "\n";

--EXPECT--
["gregory"]
["buddhist"]
["gregory","chinese"]
["gregory"]
["gregory","japanese"]
["japanese"]
["buddhist","gregory"]
