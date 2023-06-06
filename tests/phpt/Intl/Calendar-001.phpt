--TEST--
Calendar enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\Calendar;

foreach (Calendar::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
Buddhist - buddhist
Chinese - chinese
Coptic - coptic
Dangi - dangi
Ethioaa - ethioaa
Ethiopic - ethiopic
Gregory - gregory
Hebrew - hebrew
Indian - indian
Islamic - islamic
IslamicCivil - islamic-civil
IslamicRgsa - islamic-rgsa
IslamicTbla - islamic-tbla
IslamicUmalqura - islamic-umalqura
Iso8601 - iso8601
Japanese - japanese
Persian - persian
Roc - roc
