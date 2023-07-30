--TEST--
Intl::getCanonicalLocales() canonicalizes implicit Stringable values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl;

// This class does not implement Stringable, but it's implied with __toString().
$stringable = new class () {
    public function __toString(): string
    {
        return 'cmn-hans-cn';
    }
};

$canonicalized = Intl::getCanonicalLocales($stringable);

var_export($canonicalized);

--EXPECT--
array (
  0 => 'zh-Hans-CN',
)
