--TEST--
Collator::supportedLocalesOf with invalid locale
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$tests = [
    'foo-bar-baz',
];

foreach ($tests as $test) {
    try {
        Collator::supportedLocalesOf($test);
    } catch (Throwable $exception) {
        echo $exception->getMessage() . "\n";
    }
}

--EXPECT--
Invalid language tag "foo-bar-baz"
