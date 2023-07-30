--TEST--
Locale must have a valid value
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$tests = [
    '',
    'e',
    'en-',
    'en-Lat',
    'en-Latn-',
    'en-Latn-USA',
    'en-Latn-US-',
    'en-Latn-US-u-ca-gregoryab',
    'en-Latn-US-u-ca-gregory-',
    'en-Latn-US-u-ca-gregory-kf-upperabcd',
    'en-Latn-US-u-ca-gregory-kf-upper-',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emojiabcd',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23abcdef',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latnabcde',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-falseabcd',
    'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-false-',
];

foreach ($tests as $test) {
    try {
        $loc = new Locale($test);
        echo json_encode($loc) . "\n";
    } catch (ValueError $exception) {
        echo $exception->getMessage() . "\n";
    }
}

--EXPECT--
Invalid language tag ""
Invalid language tag "e"
Invalid language tag "en-"
Invalid language tag "en-Lat"
Invalid language tag "en-Latn-"
Invalid language tag "en-Latn-USA"
Invalid language tag "en-Latn-US-"
Invalid language tag "en-Latn-US-u-ca-gregoryab"
Invalid language tag "en-Latn-US-u-ca-gregory-"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upperabcd"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emojiabcd"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23abcdef"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latnabcde"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-falseabcd"
Invalid language tag "en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-false-"
