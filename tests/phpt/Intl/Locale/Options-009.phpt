--TEST--
Options with stringable parameters
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$newStringable = function (string $value): object {
    return new class ($value) {
        public function __construct(private readonly string $value)
        {
        }
        
        public function __toString(): string
        {
            return $this->value;
        }
    };
};

$options = new Options(
    calendar: $newStringable('gregory'),
    caseFirst: $newStringable('upper'),
    collation: $newStringable('emoji'),
    currency: $newStringable('USD'),
    hourCycle: $newStringable('h23'),
    language: $newStringable('en'),
    numberingSystem: $newStringable('latn'),
    numeric: false,
    region: $newStringable('US'),
    script: $newStringable('Latn'),
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
   'currency' => 'USD',
   'hourCycle' => 'h23',
   'language' => 'en',
   'numberingSystem' => 'latn',
   'numeric' => false,
   'region' => 'US',
   'script' => 'Latn',
))

{"calendar":"gregory","caseFirst":"upper","collation":"emoji","currency":"USD","hourCycle":"h23","language":"en","numberingSystem":"latn","numeric":false,"region":"US","script":"Latn"}
