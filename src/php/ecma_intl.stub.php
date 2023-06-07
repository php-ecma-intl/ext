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
     * @link https://www.unicode.org/reports/tr35/tr35-collation.html#table-collation-settings Collation Settings
     */
    enum CaseFirst: string
    {
        case False = 'false';
        case Lower = 'lower';
        case Upper = 'upper';
    }
}
