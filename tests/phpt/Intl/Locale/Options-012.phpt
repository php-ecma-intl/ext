--TEST--
Options throws the first encountered stringable conversion exception
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
    'calendar' => 'gregory',
    'caseFirst' => 'upper',
    'collation' => 'emoji',
    'hourCycle' => $throwingStringable('hourCycle'),
    'language' => 'en',
    'numberingSystem' => $throwingStringable('numberingSystem'),
    'region' => 'US',
    'script' => $throwingStringable('script'),
];

new Options(...$properties);

--EXPECTF--
Fatal error: Uncaught CustomError: problem with string conversion for hourCycle in %s/Intl/Locale/Options-012.php:%d
Stack trace:
#0 [internal function]: class@anonymous->__toString()
#1 %s/Intl/Locale/Options-012.php(%d): Ecma\Intl\Locale\Options->__construct('gregory', 'upper', 'emoji', Object(class@anonymous), 'en', Object(class@anonymous), NULL, 'US', Object(class@anonymous))
#2 {main}
  thrown in %s/Intl/Locale/Options-012.php on line %d
