--TEST--
SupportedLocalesOptions without any parameters serializes to empty JSON object
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

$options = new SupportedLocalesOptions();

var_export($options);
echo "\n\n";
echo json_encode($options);
echo "\n";

--EXPECT--
\Ecma\Intl\SupportedLocalesOptions::__set_state(array(
   'localeMatcher' => NULL,
))

{}
