--TEST--
Collator::supportedLocalesOf with invalid values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Collator;

$tests = [
    123,
    12.3,
    false,
    (object) [],
    ['en-US', 'fr', 123, 'de'],
    ['en-US', 123, 12.3, 'de'],
    ['en-US', 123, null, 'de'],
    ['en-US', 123, (object) [], 'de'],
    (function (): Generator {
        yield 'en-US';
        yield 'fr';
        yield null;
        yield 'de';
    })(),
];

foreach ($tests as $test) {
    try {
        Collator::supportedLocalesOf($test);
    } catch (Throwable $exception) {
        echo $exception->getMessage() . "\n";
    }
}

--EXPECT--
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, int given
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, float given
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, bool given
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, stdClass given
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, int given in iterable
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, float given in iterable
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, null given in iterable
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, stdClass given in iterable
Ecma\Intl\Collator::supportedLocalesOf(): Argument #1 ($locales) must be of type iterable<Stringable|string>|Stringable|string|null, null given in iterable
