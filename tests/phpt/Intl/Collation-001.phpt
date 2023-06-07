--TEST--
Collation enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Collation;

foreach (Collation::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
Big5han - big5han
Compat - compat
Dict - dict
Direct - direct
Ducet - ducet
Emoji - emoji
Eor - eor
Gb2312 - gb2312
Phonebk - phonebk
Phonetic - phonetic
Pinyin - pinyin
Reformed - reformed
Search - search
Searchjl - searchjl
Standard - standard
Stroke - stroke
Trad - trad
Unihan - unihan
Zhuyin - zhuyin
