--TEST--
Options propagates exceptions thrown from stringable conversion
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

class CustomError extends RuntimeException
{
}

$throwingStringable = function (string $property): object {
    return new class ($property) {
        public function __construct(private readonly string $property)
        {
        }
 
        public function __toString(): string
        {
            throw new CustomError('problem with string conversion for ' . $this->property);
        }
    };
};

$properties = [
    'calendar' => $throwingStringable('calendar'),
    'caseFirst' => $throwingStringable('caseFirst'),
    'collation' => $throwingStringable('collation'),
    'currency' => $throwingStringable('currency'),
    'hourCycle' => $throwingStringable('hourCycle'),
    'language' => $throwingStringable('language'),
    'numberingSystem' => $throwingStringable('numberingSystem'),
    'region' => $throwingStringable('region'),
    'script' => $throwingStringable('script'),
];

foreach ($properties as $property => $value) {
    assert($value instanceof Stringable);

    try {
        new Options(...[$property => $value]);
    } catch (Throwable $exception) {
        echo $exception::class . ' - ' . $exception->getMessage() . "\n";
    }
}

--EXPECT--
CustomError - problem with string conversion for calendar
CustomError - problem with string conversion for caseFirst
CustomError - problem with string conversion for collation
CustomError - problem with string conversion for currency
CustomError - problem with string conversion for hourCycle
CustomError - problem with string conversion for language
CustomError - problem with string conversion for numberingSystem
CustomError - problem with string conversion for region
CustomError - problem with string conversion for script
