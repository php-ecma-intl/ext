--TEST--
SupportedLocales\Options with stringable parameters
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocales\Options;

$newStringable = function (string $value): object {
    return new class ($value) {
        public function __construct(private readonly string $value)
        {
        }
        
        public function __toString(): string
        {
            return $this->value;
        }
    };
};

$options = new Options(
    localeMatcher: $newStringable('lookup'),
);

var_export($options);
echo "\n\n";
echo json_encode($options);
echo "\n";

--EXPECT--
\Ecma\Intl\SupportedLocales\Options::__set_state(array(
   'localeMatcher' => 'lookup',
))

{"localeMatcher":"lookup"}
