--TEST--
Options can set each property to null
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$options = new Options(
    calendar: null,
    caseFirst: null,
    collation: null,
    currency: null,
    hourCycle: null,
    language: null,
    numberingSystem: null,
    numeric: null,
    region: null,
    script: null,
);

var_dump($options->calendar);
var_dump($options->caseFirst);
var_dump($options->collation);
var_dump($options->currency);
var_dump($options->hourCycle);
var_dump($options->language);
var_dump($options->numberingSystem);
var_dump($options->numeric);
var_dump($options->region);
var_dump($options->script);

--EXPECT--
NULL
NULL
NULL
NULL
NULL
NULL
NULL
NULL
NULL
NULL
