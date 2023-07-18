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

namespace Ecma
{
    final class Intl
    {
        /**
         * Returns an array of canonical locale names for the input locale(s)
         *
         * @link https://tc39.es/ecma402/#sec-intl.getcanonicallocales ECMA-402, section 8.3.1, Intl.getCanoncialLocales
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/getCanonicalLocales MDN: Intl.getCanonicalLocales()
         *
         * @phpstan-param iterable<\Stringable|string>|\Stringable|string|null $locales
         *
         * @return string[]
         */
        public static function getCanonicalLocales(iterable|\Stringable|string|null $locales): array
        {
        }

        /**
         * Returns an array containing the supported calendar, collation,
         * currency, numbering systems, or unit values supported by this
         * implementation.
         *
         * @link https://tc39.es/ecma402/#sec-intl.supportedvaluesof ECMA-402, section 8.3.2, Intl.supportedValuesOf
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/supportedValuesOf MDN: Intl.supportedValuesOf()
         *
         * @return string[]
         */
        public static function supportedValuesOf(Intl\Category $category): array
        {
        }

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
     * A Locale represents a Unicode locale identifier
     *
     * @link https://tc39.es/ecma402/#locale-objects ECMA-402: Locale Objects
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale MDN: Intl.Locale
     * @link https://tc39.es/proposal-intl-locale-info/ Intl Locale Info Proposal
     */
    readonly class Locale implements \Stringable
    {
        /**
         * A Locale represents a Unicode locale identifier
         *
         * @link https://tc39.es/ecma402/#locale-objects ECMA-402: Locale Objects
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale MDN: Intl.Locale
         * @link https://tc39.es/proposal-intl-locale-info/ Intl Locale Info Proposal
         *
         * @param \Stringable|string $tag The language tag (or locale identifier)
         */
        public function __construct(\Stringable|string $tag)
        {
        }

        /**
         * Returns a string representation of the full locale identifier
         */
        public function __toString(): string
        {
        }
    }
}
