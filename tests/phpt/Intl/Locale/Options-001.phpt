--TEST--
Options without any parameters serializes to empty JSON object
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale\Options;

$options = new Options();

var_export($options);
echo "\n\n";
echo json_encode($options);
echo "\n";

--EXPECT--
\Ecma\Intl\Locale\Options::__set_state(array(
   'calendar' => NULL,
   'caseFirst' => NULL,
   'collation' => NULL,
   'hourCycle' => NULL,
   'language' => NULL,
   'numberingSystem' => NULL,
   'numeric' => NULL,
   'region' => NULL,
   'script' => NULL,
))

{}
