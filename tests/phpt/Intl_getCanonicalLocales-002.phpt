--TEST--
Intl::getCanonicalLocales() canonicalizes array values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl;

$stringable1 = new class () implements Stringable {
    public function __toString(): string
    {
        return 'sl-rozaj-biske-1994';
    }
};

// Implicit Stringable has __toString() but does not implement Stringable.
$stringable2 = new class () {
    public function __toString(): string
    {
        return 'sgn-GR';
    }
};

$canonicalized = Intl::getCanonicalLocales([
    $stringable1,
    'cmn-hans-cn-u-ca-t-ca-x-t-u',
    'CMN-hANS',
    $stringable2,
]);

var_export($canonicalized);

--EXPECT--
array (
  0 => 'sl-1994-biske-rozaj',
  1 => 'zh-Hans-CN-t-ca-u-ca-x-t-u',
  2 => 'zh-Hans',
  3 => 'gss',
)
