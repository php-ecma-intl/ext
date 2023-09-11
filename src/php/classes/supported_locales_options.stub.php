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

namespace Ecma\Intl\SupportedLocales
{
    /**
     * Options to use when evaluating supported locales.
     *
     * @link https://tc39.es/ecma402/#sec-supportedlocales ECMA-402, section 9.2.10, SupportedLocales
     *
     * @strict-properties
     */
    readonly class Options implements \Iterator, \JsonSerializable
    {
        /**
         * The locale-matching algorithm to use when evaluating supported locales.
         */
        public readonly ?string $localeMatcher;

        /**
         * Options to use when evaluating supported locales.
         *
         * @link https://tc39.es/ecma402/#sec-supportedlocales ECMA-402, section 9.2.10, SupportedLocales
         *
         * @param \Stringable|string|null $localeMatcher The locale-matching algorithm to use when evaluating supported locales.
         */
        public function __construct(
            \Stringable|string|null $localeMatcher = null,
        ) {
        }

        /**
         * Returns an object of these options, suitable for serializing to JSON.
         *
         * @return object
         */
        public function jsonSerialize(): object
        {
        }

        public function current(): string|bool
        {
        }

        public function next(): void
        {
        }

        public function key(): string
        {
        }

        public function valid(): bool
        {
        }

        public function rewind(): void
        {
        }
    }
}
