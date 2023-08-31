--TEST--
Locale accepts Stringable
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale;

$string = new class () {
    public function __toString(): string {
        return 'en-Latn-US-u-ca-gregory-kf-upper-co-emoji-hc-h23-nu-latn-kn-cu-USD';
    }
};

$locale = new Locale($string);

echo $locale;

--EXPECT--
en-Latn-US-u-ca-gregory-co-emoji-cu-usd-hc-h23-kf-upper-kn-nu-latn
