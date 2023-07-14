--TEST--
Intl::getCanonicalLocales() throws exception for invalid value in Iterator
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$tags = [
    'de',
    'DE-de',
    'de-DE',
    'cmn',
    'CMN-hANS',
    'cmn-hans-cn',
    'es-419',
    'es-419-u-nu-latn',
    'cmn-hans-cn-u-ca-t-ca-x-t-u',
    'de-gregory-u-ca-gregory',
    'sgn-GR',
    'ji',
    'de-DD',
    new stdClass(),                      // Here is the invalid value.
    'sr-cyrl-ekavsk',
    'en-ca-newfound',
    'sl-rozaj-biske-1994',
    'da-u-attr',
    'da-u-attr-co-search',
];

$iterator = new class ($tags) implements IteratorAggregate {
    public function __construct(private readonly array $tags)
    {
    }
    
    public function getIterator() : Traversable
    {
        return new ArrayIterator($this->tags);
    }
};

var_export(Intl::getCanonicalLocales($iterator));

--EXPECTF--
Fatal error: Uncaught TypeError: Ecma\Intl::getCanonicalLocales(): Argument #1 ($locales) must be of type string or a Traversable|array of type string, stdClass found in Traversable|array in %s/Intl_getCanonicalLocales-009.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-009.php(%d): Ecma\Intl::getCanonicalLocales(Object(IteratorAggregate@anonymous))
#1 {main}
  thrown in %s/Intl_getCanonicalLocales-009.php on line %d
