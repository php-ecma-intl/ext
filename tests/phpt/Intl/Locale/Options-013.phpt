--TEST--
Options supports full array unpacking
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
    currency: 'USD',
    hourCycle: 'h23',
    language: 'en',
    numberingSystem: 'latn',
    numeric: true,
    region: 'US',
    script: 'Latn',
);

var_export([...$options]);

--EXPECT--
array (
  'calendar' => 'gregory',
  'caseFirst' => 'upper',
  'collation' => 'emoji',
  'currency' => 'USD',
  'hourCycle' => 'h23',
  'language' => 'en',
  'numberingSystem' => 'latn',
  'numeric' => true,
  'region' => 'US',
  'script' => 'Latn',
)
