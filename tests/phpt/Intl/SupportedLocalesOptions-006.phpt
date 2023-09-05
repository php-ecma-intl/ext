--TEST--
SupportedLocalesOptions throws exceptions for invalid values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

$tests = [
    ['localeMatcher', 'abcd'],        // wrong value
];


foreach ($tests as $test) {
    [$property, $value] = $test;
    try {
        $options = new SupportedLocalesOptions(...[$property => $value]);
    } catch (Error $error) {
        echo $error->getMessage() . "\n";
    }
}

--EXPECT--
localeMatcher must be either "lookup" or "best fit"
