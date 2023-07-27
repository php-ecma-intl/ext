--TEST--
Locale serializes to JSON with properties
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale;

$tests = [
    'en',
    'en-us',
    'en-latn',
    'en-latn-us',
    'en-US-u-ca-gregory',
    'en-u-kf-false',
    'en-u-co-phonebk',
    'en-u-hc-h12',
    'en-u-kn-false',
    'en-u-nu-arab',
    'en-latn-us-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-true',
];

foreach ($tests as $test) {
    echo json_encode(new Locale($test)) . "\n";
}

--EXPECT--
{"baseName":"en","calendar":null,"caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":null,"script":null}
{"baseName":"en-US","calendar":null,"caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":"US","script":null}
{"baseName":"en-Latn","calendar":null,"caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":null,"script":"Latn"}
{"baseName":"en-Latn-US","calendar":null,"caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":"US","script":"Latn"}
{"baseName":"en-US","calendar":"gregory","caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":"US","script":null}
{"baseName":"en","calendar":null,"caseFirst":"false","collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":null,"script":null}
{"baseName":"en","calendar":null,"caseFirst":null,"collation":"phonebk","hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":null,"script":null}
{"baseName":"en","calendar":null,"caseFirst":null,"collation":null,"hourCycle":"h12","language":"en","numberingSystem":null,"numeric":false,"region":null,"script":null}
{"baseName":"en","calendar":null,"caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":null,"numeric":false,"region":null,"script":null}
{"baseName":"en","calendar":null,"caseFirst":null,"collation":null,"hourCycle":null,"language":"en","numberingSystem":"arab","numeric":false,"region":null,"script":null}
{"baseName":"en-Latn-US","calendar":"gregory","caseFirst":"upper","collation":"emoji","hourCycle":"h23","language":"en","numberingSystem":"latn","numeric":true,"region":"US","script":"Latn"}
