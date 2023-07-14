--TEST--
Intl::getCanonicalLocales() throws exception for invalid value in Generator
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$generate = function (): iterable {
    $tags = [
        'de',
        'DE-de',
        'de-DE',
        'cmn',
        'CMN-hANS',
        'cmn-hans-cn',
        1234,                            // Here is the invalid value.
        'es-419-u-nu-latn',
        'cmn-hans-cn-u-ca-t-ca-x-t-u',
        'de-gregory-u-ca-gregory',
        'sgn-GR',
        'ji',
        'de-DD',
        'in',
        'sr-cyrl-ekavsk',
        'en-ca-newfound',
        'sl-rozaj-biske-1994',
        'da-u-attr',
        'da-u-attr-co-search',
    ];

    foreach ($tags as $tag) {
        yield $tag;
    }
};

var_export(Intl::getCanonicalLocales($generate()));

--EXPECTF--
Fatal error: Uncaught TypeError: Ecma\Intl::getCanonicalLocales(): Argument #1 ($locales) must be of type string or a Traversable|array of type string, int found in Traversable|array in %s/Intl_getCanonicalLocales-008.php:%d
Stack trace:
#0 %s/Intl_getCanonicalLocales-008.php(%d): Ecma\Intl::getCanonicalLocales(Object(Generator))
#1 {main}
  thrown in %s/Intl_getCanonicalLocales-008.php on line %d
