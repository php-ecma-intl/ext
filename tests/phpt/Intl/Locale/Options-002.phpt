--TEST--
Options with all parameters serializes to full JSON object
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$options = new Options(
    calendar: 'gregory',
    caseFirst: 'upper',
    collation: 'emoji',
    hourCycle: 'h23',
    language: 'en',
    numberingSystem: 'latn',
    numeric: true,
    region: 'US',
    script: 'Latn',
);

var_export($options);
echo "\n\n";
echo json_encode($options);
echo "\n";

--EXPECT--
\Ecma\Intl\Locale\Options::__set_state(array(
   'calendar' => 'gregory',
   'caseFirst' => 'upper',
   'collation' => 'emoji',
   'hourCycle' => 'h23',
   'language' => 'en',
   'numberingSystem' => 'latn',
   'numeric' => true,
   'region' => 'US',
   'script' => 'Latn',
))

{"calendar":"gregory","caseFirst":"upper","collation":"emoji","hourCycle":"h23","language":"en","numberingSystem":"latn","numeric":true,"region":"US","script":"Latn"}
