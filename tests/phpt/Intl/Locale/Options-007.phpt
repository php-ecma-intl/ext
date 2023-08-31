--TEST--
Options throws exceptions for invalid values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$tests = [
    ['calendar', 'abcdefghi'],        // too long
    ['caseFirst', 'foobar'],          // wrong value
    ['collation', 'ab'],              // too short
    ['currency', 'abcd'],             // too long
    ['hourCycle', 'h10'],             // wrong value
    ['language', 'abcd'],             // too long
    ['numberingSystem', 'abcdefghi'], // too long
    ['numeric', 'foo'],               // not boolean
    ['region', '1234'],               // too long
    ['script', 'lat'],                // too short
    ['caseFirst', true],              // boolean true is not allowed
];


foreach ($tests as $test) {
    [$property, $value] = $test;
    try {
        $options = new Options(...[$property => $value]);
    } catch (Error $error) {
        echo $error->getMessage() . "\n";
    }
}

--EXPECT--
calendar is not a well-formed calendar value
caseFirst must be either "upper", "lower", or "false"
collation is not a well-formed collation value
currency is not a well-formed currency value
hourCycle must be "h11", "h12", "h23", or "h24"
language is not a well-formed language value
numberingSystem is not a well-formed numbering system value
Ecma\Intl\Locale\Options::__construct(): Argument #8 ($numeric) must be of type ?bool, string given
region is not a well-formed region value
script is not a well-formed script value
Ecma\Intl\Locale\Options::__construct(): Argument #2 ($caseFirst) must be of type Stringable|string|false|null, true given
