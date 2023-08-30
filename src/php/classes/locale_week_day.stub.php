<?php

/**
 * Copyright (c) php-ecma-intl contributors.
 *
 * This source file is subject to the BSD-3-Clause license that is bundled with
 * this package in the file LICENSE and is available at the following web
 * address: https://opensource.org/license/bsd-3-clause/
 *
 * This source file may utilize copyrighted material from third-party open
 * source projects, the use of which is acknowledged in the NOTICE file bundled
 * with this package.
 *
 * @generate-class-entries
 */

namespace Ecma\Intl\Locale
{
    /**
     * Days of the week.
     *
     * Each case is mapped to an integer value corresponding to the values
     * defined in {@link https://tc39.es/proposal-intl-locale-info/#table-locale-weekinfo-record WeekInfo Record Fields}.
     */
    enum WeekDay: int
    {
        case Monday = 1;
        case Tuesday = 2;
        case Wednesday = 3;
        case Thursday = 4;
        case Friday = 5;
        case Saturday = 6;
        case Sunday = 7;
    }
}
