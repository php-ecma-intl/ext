--TEST--
SupportedLocales\Options with all parameters serializes to full JSON object
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$options = new Options(
    localeMatcher: 'best fit',
);

var_export($options);
echo "\n\n";
echo json_encode($options);
echo "\n";

--EXPECT--
\Ecma\Intl\SupportedLocales\Options::__set_state(array(
   'localeMatcher' => 'best fit',
))

{"localeMatcher":"best fit"}
