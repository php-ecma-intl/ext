--TEST--
Locale serializes to JSON with properties
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
    'en-latn-us-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-true',
];

foreach ($tests as $test) {
    echo "\n" . json_encode(new Locale($test), JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES) . "\n";
}

--EXPECTF--
{
    "baseName": "en",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": null,
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en-US",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": "US",
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": [%A
        "America/Chicago",%A
        "America/Denver",%A
        "America/Los_Angeles",%A
        "America/New_York",%A
    ]
}

{
    "baseName": "en-Latn",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": null,
    "script": "Latn",
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en-Latn-US",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": "US",
    "script": "Latn",
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": [%A
        "America/Chicago",%A
        "America/Denver",%A
        "America/Los_Angeles",%A
        "America/New_York",%A
    ]
}

{
    "baseName": "en-US",
    "calendar": "gregory",
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": "US",
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": [%A
        "America/Chicago",%A
        "America/Denver",%A
        "America/Los_Angeles",%A
        "America/New_York",%A
    ]
}

{
    "baseName": "en",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": "false",
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": null,
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": "phonebk",
    "collations": [
        "phonebk"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": null,
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": "h12",
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": null,
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": null,
    "numberingSystems": [
        "latn"
    ],
    "numeric": false,
    "region": null,
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en",
    "calendar": null,
    "calendars": [
        "gregory"
    ],
    "caseFirst": null,
    "collation": null,
    "collations": [
        "emoji",
        "eor"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": null,
    "hourCycles": [
        "h12"
    ],
    "language": "en",
    "numberingSystem": "arab",
    "numberingSystems": [
        "arab"
    ],
    "numeric": false,
    "region": null,
    "script": null,
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": null
}

{
    "baseName": "en-Latn-US",
    "calendar": "gregory",
    "calendars": [
        "gregory"
    ],
    "caseFirst": "upper",
    "collation": "emoji",
    "collations": [
        "emoji"
    ],
    "currencies": [
        "USD",
        "USN"
    ],
    "hourCycle": "h23",
    "hourCycles": [
        "h23"
    ],
    "language": "en",
    "numberingSystem": "latn",
    "numberingSystems": [
        "latn"
    ],
    "numeric": true,
    "region": "US",
    "script": "Latn",
    "textInfo": {
        "direction": "ltr"
    },
    "timeZones": [%A
        "America/Chicago",%A
        "America/Denver",%A
        "America/Los_Angeles",%A
        "America/New_York",%A
    ]
}
