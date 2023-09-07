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
     * WeekInfo represents locale-specific information about the days of the
     * week, for calendar purposes.
     *
     * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getWeekInfo Intl Locale Info Proposal: getTextInfo()
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getWeekInfo Intl.Locale.prototype.getWeekInfo()
     * @link https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Patterns_Week_Elements UTS 35: Week Elements
     *
     * @strict-properties
     */
    readonly class WeekInfo implements \JsonSerializable
    {
        /**
         * The week day that is considered the first day of the week
         * for the locale.
         */
        public readonly WeekDay $firstDay;

        /**
         * The minimum days required in the first week of a month or year
         * for the locale.
         *
         * @phpstan-var int<1, 7>
         */
        public readonly int $minimalDays;

        /**
         * A list of week days that are considered part of the weekend
         * for the locale.
         *
         * Please note, the number of weekend days in each locale may be
         * different, and they may not be contiguous.
         *
         * @var WeekDay[]
         */
        public readonly array $weekend;

        /**
         * WeekInfo represents locale-specific information about the days of the
         * week, for calendar purposes.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getWeekInfo Intl Locale Info Proposal: getTextInfo()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getWeekInfo Intl.Locale.prototype.getWeekInfo()
         * @link https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Patterns_Week_Elements UTS 35: Week Elements
         *
         * @param WeekDay $firstDay The week day that is considered the _first_ day of the week.
         * @param WeekDay[] $weekend A list of week days that are considered part of the weekend.
         * @phpstan-param int<1, 7> $minimalDays The minimum days required in the first week of a month or year.
         */
        public function __construct(
            WeekDay $firstDay,
            array $weekend,
            int $minimalDays,
        ) {
        }

        /**
         * Returns an object of WeekInfo properties and their values, suitable
         * for serializing to JSON.
         *
         * @return object
         */
        public function jsonSerialize(): object
        {
        }
    }
}
