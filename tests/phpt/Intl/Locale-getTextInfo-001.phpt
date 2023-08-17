--TEST--
Locale::getTextInfo() returns expected values 
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;
use Ecma\Intl\Locale\Options;

echo json_encode((new Locale('en'))->getTextInfo()) . "\n";
echo json_encode((new Locale('ar'))->getTextInfo()) . "\n";

--EXPECT--
{"direction":"ltr"}
{"direction":"rtl"}
