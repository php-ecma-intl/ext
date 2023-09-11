--TEST--
Locale casts to string
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

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
    'en-latn-us-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-true-cu-USD',
    'en-US-POSIX',
];

foreach ($tests as $test) {
    echo (new Locale($test)) . "\n";
}

--EXPECT--
en
en-US
en-Latn
en-Latn-US
en-US-u-ca-gregory
en-u-kf-false
en-u-co-phonebk
en-u-hc-h12
en-u-kn-false
en-u-nu-arab
en-Latn-US-u-ca-gregory-co-emoji-cu-usd-hc-h23-kf-upper-kn-nu-latn
en-US-u-va-posix
