--TEST--
TextInfo creation and JSON serialization
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\CharacterDirection;
use Ecma\Intl\Locale\TextInfo;

$textInfoLtr = new TextInfo(CharacterDirection::LeftToRight);
$textInfoRtl = new TextInfo(CharacterDirection::RightToLeft);

echo json_encode($textInfoLtr) . "\n";
echo json_encode($textInfoRtl) . "\n";

--EXPECT--
{"direction":"ltr"}
{"direction":"rtl"}
