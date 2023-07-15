--TEST--
Intl::getCanonicalLocales() canonicalizes Generator values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
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

// Implicit Stringable has __toString() but does not implement Stringable.
$makeImplicitStringable = function (string $value): object {
    return new class ($value) {
        public function __construct(private readonly string $value) {}

        public function __toString(): string
        {
            return $this->value;
        }
    };
};

$generate = function () use ($makeStringable, $makeImplicitStringable): iterable {
    $tags = [
        'de',
        'DE-de',
        'de-DE',
        'cmn',
        'CMN-hANS',
        $makeStringable('cmn-hans-cn'),
        'es-419',
        $makeStringable('es-419-u-nu-latn'),
        'cmn-hans-cn-u-ca-t-ca-x-t-u',
        $makeImplicitStringable('de-gregory-u-ca-gregory'),
        'sgn-GR',
        'ji',
        'de-DD',
        $makeStringable('in'),
        $makeImplicitStringable('sr-cyrl-ekavsk'),
        $makeStringable('en-ca-newfound'),
        'sl-rozaj-biske-1994',
        $makeImplicitStringable('da-u-attr'),
        'da-u-attr-co-search',
    ];

    foreach ($tags as $tag) {
        yield $tag;
    }
};

var_export(Intl::getCanonicalLocales($generate()));

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
