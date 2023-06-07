<?php

/**
 * ecma_intl extension for PHP
 *
 * Copyright (c) Ben Ramsey <ben@benramsey.com>
 *
 * This source file is subject to the MIT license that is bundled with
 * this package in the file LICENSE, and is available at the following
 * web address: https://opensource.org/license/mit/
 *
 * @generate-class-entries
 */

namespace Ecma
{
    final class Intl
    {
        /**
         * Intl may not be instantiated
         */
        private function __construct()
        {
        }
    }
}

namespace Ecma\Intl
{
    /**
     * Values for calendar (ca) options
     *
     * @link https://tc39.es/ecma402/#sec-calendar-types ECMA-402, section 6.9, Calendar Types
     * @link https://github.com/unicode-org/cldr/blob/192d861db07be95544312e70fa009d163ebbf169/common/bcp47/calendar.xml Unicode CLDR calendar values
     */
    enum Calendar: string
    {
        case Buddhist = 'buddhist';
        case Chinese = 'chinese';
        case Coptic = 'coptic';
        case Dangi = 'dangi';
        case Ethioaa = 'ethioaa';
        case Ethiopic = 'ethiopic';
        case Gregory = 'gregory';
        case Hebrew = 'hebrew';
        case Indian = 'indian';
        case Islamic = 'islamic';
        case IslamicCivil = 'islamic-civil';
        case IslamicRgsa = 'islamic-rgsa';
        case IslamicTbla = 'islamic-tbla';
        case IslamicUmalqura = 'islamic-umalqura';
        case Iso8601 = 'iso8601';
        case Japanese = 'japanese';
        case Persian = 'persian';
        case Roc = 'roc';
    }

    /**
     * Values for case first (kf) options
     *
     * When used with the caseFirst option (or the "kf" language tag parameter),
     * these values determine whether to sort by upper case or lower case first.
     * The default (i.e., "false") is to use the locale's default sorting.
     *
     * @link https://www.unicode.org/reports/tr35/tr35-collation.html#table-collation-settings Unicode Collation Settings
     */
    enum CaseFirst: string
    {
        case False = 'false';
        case Lower = 'lower';
        case Upper = 'upper';
    }

    /**
     * Categories of values supported by this implementation
     *
     * @link https://tc39.es/ecma402/#sec-intl.supportedvaluesof ECMA-402, section 8.3.2, Intl.supportedValuesOf
     */
    enum Category: string
    {
        case Calendar = 'calendar';
        case Collation = 'collation';
        case Currency = 'currency';
        case NumberingSystem = 'numberingSystem';
        case TimeZone = 'timeZone';
        case Unit = 'unit';
    }

    /**
     * Values for collation (co) options
     *
     * @link https://github.com/unicode-org/cldr/blob/a2af7f838c035ef9b40162d24dd7cf9227e9590c/common/bcp47/collation.xml Unicode CLDR collation values
     */
    enum Collation: string
    {
        case Big5han = 'big5han';
        case Compat = 'compat';
        case Dict = 'dict';
        case Direct = 'direct';
        case Ducet = 'ducet';
        case Emoji = 'emoji';
        case Eor = 'eor';
        case Gb2312 = 'gb2312';
        case Phonebk = 'phonebk';
        case Phonetic = 'phonetic';
        case Pinyin = 'pinyin';
        case Reformed = 'reformed';
        case Search = 'search';
        case Searchjl = 'searchjl';
        case Standard = 'standard';
        case Stroke = 'stroke';
        case Trad = 'trad';
        case Unihan = 'unihan';
        case Zhuyin = 'zhuyin';
    }

    /**
     * Values for hour cycle (hc) options
     *
     * @link https://tc39.es/ecma402/#sec-intl.datetimeformat-internal-slots ECMA-402, section 11.2.3, DateTimeFormat internal slots
     * @link https://www.unicode.org/reports/tr35/#UnicodeHourCycleIdentifier Unicode Hour Cycle Identifier
     * @link https://github.com/unicode-org/cldr/blob/a2af7f838c035ef9b40162d24dd7cf9227e9590c/common/bcp47/calendar.xml Unicode CLDR hour cycle
     */
    enum HourCycle: string
    {
        case H11 = 'h11';
        case H12 = 'h12';
        case H23 = 'h23';
        case H24 = 'h24';
    }

    /**
     * An IcuException occurs when the underlying ICU library raises an error
     * that ecma_intl cannot handle
     */
    class IcuException extends \RuntimeException
    {
    }

    /**
     * Locale matching algorithms for use in locale identification and negotiation
     *
     * @link https://tc39.es/ecma402/#sec-supportedlocales ECMA-402, section 9.2.10, SupportedLocales
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl#locale_identification_and_negotiation MDN: Locale identification and negotiation
     */
    enum LocaleMatcher: string
    {
        case BestFit = 'best fit';
        case Lookup = 'lookup';
    }

    /**
     * Values for numbering system (nu) options
     *
     * @link https://tc39.es/ecma402/#sec-numberingsystem-identifiers ECMA-402, section 6.7, Numbering System Identifiers
     * @link https://github.com/unicode-org/cldr/blob/a2af7f838c035ef9b40162d24dd7cf9227e9590c/common/bcp47/number.xml Unicode CLDR numbering system values
     */
    enum NumberingSystem: string
    {
        case Adlm = 'adlm';
        case Ahom = 'ahom';
        case Arab = 'arab';
        case Arabext = 'arabext';
        case Armn = 'armn';
        case Armnlow = 'armnlow';
        case Bali = 'bali';
        case Beng = 'beng';
        case Bhks = 'bhks';
        case Brah = 'brah';
        case Cakm = 'cakm';
        case Cham = 'cham';
        case Cyrl = 'cyrl';
        case Deva = 'deva';
        case Diak = 'diak';
        case Ethi = 'ethi';
        case Finance = 'finance';
        case Fullwide = 'fullwide';
        case Geor = 'geor';
        case Gong = 'gong';
        case Gonm = 'gonm';
        case Grek = 'grek';
        case Greklow = 'greklow';
        case Gujr = 'gujr';
        case Guru = 'guru';
        case Hanidays = 'hanidays';
        case Hanidec = 'hanidec';
        case Hans = 'hans';
        case Hansfin = 'hansfin';
        case Hant = 'hant';
        case Hantfin = 'hantfin';
        case Hebr = 'hebr';
        case Hmng = 'hmng';
        case Hmnp = 'hmnp';
        case Java = 'java';
        case Jpan = 'jpan';
        case Jpanfin = 'jpanfin';
        case Jpanyear = 'jpanyear';
        case Kali = 'kali';
        case Kawi = 'kawi';
        case Khmr = 'khmr';
        case Knda = 'knda';
        case Lana = 'lana';
        case Lanatham = 'lanatham';
        case Laoo = 'laoo';
        case Latn = 'latn';
        case Lepc = 'lepc';
        case Limb = 'limb';
        case Mathbold = 'mathbold';
        case Mathdbl = 'mathdbl';
        case Mathmono = 'mathmono';
        case Mathsanb = 'mathsanb';
        case Mathsans = 'mathsans';
        case Mlym = 'mlym';
        case Modi = 'modi';
        case Mong = 'mong';
        case Mroo = 'mroo';
        case Mtei = 'mtei';
        case Mymr = 'mymr';
        case Mymrshan = 'mymrshan';
        case Mymrtlng = 'mymrtlng';
        case Nagm = 'nagm';
        case Native = 'native';
        case Newa = 'newa';
        case Nkoo = 'nkoo';
        case Olck = 'olck';
        case Orya = 'orya';
        case Osma = 'osma';
        case Rohg = 'rohg';
        case Roman = 'roman';
        case Romanlow = 'romanlow';
        case Saur = 'saur';
        case Segment = 'segment';
        case Shrd = 'shrd';
        case Sind = 'sind';
        case Sinh = 'sinh';
        case Sora = 'sora';
        case Sund = 'sund';
        case Takr = 'takr';
        case Talu = 'talu';
        case Taml = 'taml';
        case Tamldec = 'tamldec';
        case Telu = 'telu';
        case Thai = 'thai';
        case Tibt = 'tibt';
        case Tirh = 'tirh';
        case Tnsa = 'tnsa';
        case Traditio = 'traditio';
        case Vaii = 'vaii';
        case Wara = 'wara';
        case Wcho = 'wcho';
    }

    /**
     * Common style options used throughout ECMA-402
     */
    enum Style: string
    {
        case Long = 'long';
        case Narrow = 'narrow';
        case Short = 'short';
    }
}
