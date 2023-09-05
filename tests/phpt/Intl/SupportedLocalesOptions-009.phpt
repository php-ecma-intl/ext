--TEST--
SupportedLocalesOptions propagates exceptions thrown from stringable conversion
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\SupportedLocalesOptions;

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
    'localeMatcher' => $throwingStringable('localeMatcher'),
];

foreach ($properties as $property => $value) {
    assert($value instanceof Stringable);

    try {
        new SupportedLocalesOptions(...[$property => $value]);
    } catch (Throwable $exception) {
        echo $exception::class . ' - ' . $exception->getMessage() . "\n";
    }
}

--EXPECT--
CustomError - problem with string conversion for localeMatcher
