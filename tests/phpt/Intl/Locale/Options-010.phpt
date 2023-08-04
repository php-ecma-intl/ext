--TEST--
Options allows boolean false for caseFirst
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$options = new Options(
    caseFirst: false,
);

var_dump($options->caseFirst);

--EXPECT--
string(5) "false"
