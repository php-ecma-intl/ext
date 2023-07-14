--TEST--
Intl::getCanonicalLocales() canonicalizes Generator values
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
        'es-419',
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
