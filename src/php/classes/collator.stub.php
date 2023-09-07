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

namespace Ecma\Intl
{
    /**
     * @strict-properties
     */
    readonly class Collator
    {
        /**
         * Returns an array of those locales provided that are supported by this
         * implementation without having to fall back to the default locale.
         *
         * @phpstan-param iterable<\Stringable|string>|\Stringable|string|null $locales One or more language tags to check for support.
         * @param SupportedLocales\Options|null $options Options to use when evaluating supported locales.
         *
         * @return string[]
         */
        public static function supportedLocalesOf(iterable|\Stringable|string|null $locales, SupportedLocales\Options $options = null): array
        {
        }
    }
}
