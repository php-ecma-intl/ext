--TEST--
Locale accepts Stringable
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Locale;

$string = new class () {
    public function __toString(): string {
        return 'cmn-hans-cn-u-ca-t-ca-x-t-u';
    }
};

$locale = new Locale($string);

echo $locale;

--EXPECT--
zh-Hans-CN-t-ca-u-ca-x-t-u
