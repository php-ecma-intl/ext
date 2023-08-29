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
     * Configuration for the locale.
     *
     * Any property set on the Options object passed to the Locale's
     * constructor will override the same properties on the language tag passed
     * to the Locale.
     *
     * @link https://tc39.es/ecma402/#sec-intl-locale-constructor ECMA-402: The Intl.Locale Constructor
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/Locale MDN: Intl.Locale() constructor
     *
     * @strict-properties
     */
    readonly class Options implements \Iterator, \JsonSerializable
    {
        /**
         * The calendar to set on the locale.
         */
        public readonly ?string $calendar;

        /**
         * The case sorting algorithm to set on the locale.
         */
        public readonly ?string $caseFirst;

        /**
         * The collation algorithm to set on the locale.
         */
        public readonly ?string $collation;

        /**
         * The hour cycle to set on the locale.
         */
        public readonly ?string $hourCycle;

        /**
         * The language to set on the locale.
         */
        public readonly ?string $language;

        /**
         * The locale's numbering system
         */
        public readonly ?string $numberingSystem;

        /**
         * Whether to sort a sequence of decimal digits with its numeric value
         * (i.e, "A-21" < "A-123")
         */
        public readonly ?bool $numeric;

        /**
         * The locale's region.
         */
        public readonly ?string $region;

        /**
         * The locale's script.
         */
        public readonly ?string $script;

        /**
         * Configuration for the locale
         *
         * Any property set on the Options object passed to the Locale's
         * constructor will override the same properties on the language tag passed
         * to the Locale.
         *
         * @link https://tc39.es/ecma402/#sec-intl-locale-constructor ECMA-402: The Intl.Locale Constructor
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/Locale MDN: Intl.Locale() constructor
         *
         * @param \Stringable|string|null $calendar The calendar to use with the locale
         * @param \Stringable|string|false|null $caseFirst The case sorting algorithm to use with the locale
         * @param \Stringable|string|null $collation The collation algorithm to use with the locale
         * @param \Stringable|string|null $hourCycle The hour cycle to use with the locale
         * @param \Stringable|string|null $language The locale's language
         * @param \Stringable|string|null $numberingSystem The locale's numbering system
         * @param bool|null $numeric Whether to sort a sequence of decimal digits with its numeric value (i.e, "A-21" < "A-123")
         * @param \Stringable|string|null $region The locale's region
         * @param \Stringable|string|null $script The locale's script
         */
        public function __construct(
            \Stringable|string|null $calendar = null,
            \Stringable|string|false|null $caseFirst = null,
            \Stringable|string|null $collation = null,
            \Stringable|string|null $hourCycle = null,
            \Stringable|string|null $language = null,
            \Stringable|string|null $numberingSystem = null,
            ?bool $numeric = null,
            \Stringable|string|null $region = null,
            \Stringable|string|null $script = null,
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

        /**
         * Returns the current element when iterating over the object properties.
         *
         * This allows the object to be used in array unpacking scenarios. For
         * example:
         *
         * ```php
         * use Ecma\Intl\Locale\Options;
         * $commonOptions = new Options(hourCycle: 'h23');
         * $englishOptions = new Options(...[...$commonOptions, 'language' => 'en']);
         * ```
         *
         * Please note that `null` values will be skipped when iterating over
         * them. This facilitates scenarios where you might return JSON-encoded
         * values to be used by `Intl.Locale` instances in JavaScript.
         */
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
