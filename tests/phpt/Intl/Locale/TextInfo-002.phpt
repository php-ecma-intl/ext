--TEST--
TextInfo properties are readonly
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\CharacterDirection;
use Ecma\Intl\Locale\TextInfo;

$properties = [
    'direction' => CharacterDirection::RightToLeft,
];

$textInfo = new TextInfo(CharacterDirection::LeftToRight);

foreach ($properties as $property => $value) {
    try {
        $textInfo->{$property} = $value;
    } catch (Error $error) {
        echo $error->getMessage() . "\n";
    }
}

--EXPECTF--
Cannot modify readonly property Ecma\Intl\Locale\TextInfo::$direction
