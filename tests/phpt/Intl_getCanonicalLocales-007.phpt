--TEST--
Intl::getCanonicalLocales() canonicalizes Iterator values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$makeStringable = function (string $value): Stringable {
    return new class ($value) implements Stringable {
        public function __construct(private readonly string $value) {}

        public function __toString(): string
        {
            return $this->value;
        }
    };
};

$tags = [
    'de',
    $makeStringable('DE-de'),
    'de-DE',
    'cmn',
    'CMN-hANS',
    'cmn-hans-cn',
    'es-419',
    'es-419-u-nu-latn',
    $makeStringable('cmn-hans-cn-u-ca-t-ca-x-t-u'),
    $makeStringable('de-gregory-u-ca-gregory'),
    'sgn-GR',
    $makeStringable('ji'),
    'de-DD',
    'in',
    'sr-cyrl-ekavsk',
    'en-ca-newfound',
    'sl-rozaj-biske-1994',
    'da-u-attr',
    $makeStringable('da-u-attr-co-search'),
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

--EXPECT--
array (
  0 => 'de',
  1 => 'de-DE',
  2 => 'zh',
  3 => 'zh-Hans',
  4 => 'zh-Hans-CN',
  5 => 'es-419',
  6 => 'es-419-u-nu-latn',
  7 => 'zh-Hans-CN-t-ca-u-ca-x-t-u',
  8 => 'de-gregory-u-ca-gregory',
  9 => 'gss',
  10 => 'yi',
  11 => 'id',
  12 => 'sr-Cyrl-ekavsk',
  13 => 'en-CA-newfound',
  14 => 'sl-1994-biske-rozaj',
  15 => 'da-u-attr',
  16 => 'da-u-attr-co-search',
)
