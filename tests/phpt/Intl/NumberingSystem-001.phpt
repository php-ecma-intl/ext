--TEST--
NumberingSystem enum has expected values
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\NumberingSystem;

foreach (NumberingSystem::cases() as $case) {
    echo "$case->name - $case->value\n";
}

--EXPECT--
Adlm - adlm
Ahom - ahom
Arab - arab
Arabext - arabext
Armn - armn
Armnlow - armnlow
Bali - bali
Beng - beng
Bhks - bhks
Brah - brah
Cakm - cakm
Cham - cham
Cyrl - cyrl
Deva - deva
Diak - diak
Ethi - ethi
Finance - finance
Fullwide - fullwide
Geor - geor
Gong - gong
Gonm - gonm
Grek - grek
Greklow - greklow
Gujr - gujr
Guru - guru
Hanidays - hanidays
Hanidec - hanidec
Hans - hans
Hansfin - hansfin
Hant - hant
Hantfin - hantfin
Hebr - hebr
Hmng - hmng
Hmnp - hmnp
Java - java
Jpan - jpan
Jpanfin - jpanfin
Jpanyear - jpanyear
Kali - kali
Kawi - kawi
Khmr - khmr
Knda - knda
Lana - lana
Lanatham - lanatham
Laoo - laoo
Latn - latn
Lepc - lepc
Limb - limb
Mathbold - mathbold
Mathdbl - mathdbl
Mathmono - mathmono
Mathsanb - mathsanb
Mathsans - mathsans
Mlym - mlym
Modi - modi
Mong - mong
Mroo - mroo
Mtei - mtei
Mymr - mymr
Mymrshan - mymrshan
Mymrtlng - mymrtlng
Nagm - nagm
Native - native
Newa - newa
Nkoo - nkoo
Olck - olck
Orya - orya
Osma - osma
Rohg - rohg
Roman - roman
Romanlow - romanlow
Saur - saur
Segment - segment
Shrd - shrd
Sind - sind
Sinh - sinh
Sora - sora
Sund - sund
Takr - takr
Talu - talu
Taml - taml
Tamldec - tamldec
Telu - telu
Thai - thai
Tibt - tibt
Tirh - tirh
Tnsa - tnsa
Traditio - traditio
Vaii - vaii
Wara - wara
Wcho - wcho
