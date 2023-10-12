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
         * The current ICU library version.
         *
         * @var string
         * @cvalue U_ICU_VERSION
         */
        public const ICU_VERSION = UNKNOWN;

        /**
         * Unicode version number.
         *
         * @var string
         * @cvalue U_UNICODE_VERSION
         */
        public const UNICODE_VERSION = UNKNOWN;

        /**
         * Returns the currently configured default locale as an
         * {@see \Ecma\Intl\Locale} instance.
         *
         * The default locale is the value set using the INI property
         * `ecma_intl.default_locale`. If this property is not set or does not
         * validate as a supported locale for this implementation, this falls
         * back to the default locale determined by the ICU library. If that
         * fails to find a default locale (unlikely), the default locale falls
         * back to `"en"`.
         *
         * The return value is always a new object instance, even if the default
         * locale does not change. This means:
         *
         *     Intl::defaultLocale() !== Intl::defaultLocale()
         *
         * This static method is not defined by ECMA-402.
         */
        public static function defaultLocale(): Intl\Locale
        {
        }

        /**
         * Returns an array of canonical locale names for the input locale(s).
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
         * Intl may not be instantiated.
         */
        private function __construct()
        {
        }
    }
}
