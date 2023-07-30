--TEST--
Options can be combined with array unpacking
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$optionsEnglish = new Options(language: 'en');
$optionsFrench = new Options(language: 'fr');
$optionsCA = new Options(region: 'CA');
$optionsUS = new Options(region: 'US');
$optionsGB = new Options(region: 'GB');

echo json_encode(new Options(...[...$optionsCA, ...$optionsEnglish])) . "\n";
echo json_encode(new Options(...[...$optionsGB, ...$optionsEnglish])) . "\n";
echo json_encode(new Options(...[...$optionsUS, ...$optionsEnglish])) . "\n";
echo json_encode(new Options(...[...$optionsCA, ...$optionsFrench])) . "\n";

--EXPECT--
{"language":"en","region":"CA"}
{"language":"en","region":"GB"}
{"language":"en","region":"US"}
{"language":"fr","region":"CA"}
