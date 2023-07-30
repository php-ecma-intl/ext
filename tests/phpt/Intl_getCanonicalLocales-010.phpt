--TEST--
Intl::getCanonicalLocales() canonicalizes Stringable values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

$stringable = new class () implements Stringable {
    public function __toString(): string
    {
        return 'cmn-hans-cn-u-ca-t-ca-x-t-u';
    }
};

$canonicalized = Intl::getCanonicalLocales($stringable);

var_export($canonicalized);

--EXPECT--
array (
  0 => 'zh-Hans-CN-t-ca-u-ca-x-t-u',
)
