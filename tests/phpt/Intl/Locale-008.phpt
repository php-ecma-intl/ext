--TEST--
Locale with Options
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

$tests = [
    ['en', new Options(calendar: 'gregory')],
    ['en-us', new Options(region: 'ca')],
    ['en-latn', new Options(region: 'us')],
    ['en-latn-us', new Options(caseFirst: 'upper', collation: 'emoji', script: 'what')],
    ['en-US-u-ca-gregory', new Options(calendar: 'buddhist')],
    ['en-u-kf-false', new Options(caseFirst: 'lower')],
    ['en-u-co-phonebk', new Options(language: 'fr')],
    ['en-u-hc-h12', new Options(hourCycle: 'h23')],
    ['en-u-kn-false', new Options(numeric: true)],
    ['en-u-nu-arab', new Options(numberingSystem: 'latn')],
    ['en-latn-us-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-true', new Options(
        language: 'es',
        script: 'some',
        region: 'mx',
        calendar: 'buddhist',
        caseFirst: 'false',
        collation: 'phonebk',
        hourCycle: 'h11',
        numberingSystem: 'arab',
        numeric: false,
    )],
    ['en-latn-us-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-true', new Options()],
];

foreach ($tests as $params) {
    echo (new Locale(...$params)) . "\n";
}

--EXPECT--
en-u-ca-gregory
en-CA
en-Latn-US
en-What-US-u-co-emoji-kf-upper
en-US-u-ca-buddhist
en-u-kf-lower
fr-u-co-phonebk
en-u-hc-h23
en-u-kn
en-u-nu-latn
es-Some-MX-u-ca-buddhist-co-phonebk-hc-h11-kf-false-kn-false-nu-arab
en-Latn-US-u-ca-gregory-co-emoji-hc-h23-kf-upper-kn-nu-latn
