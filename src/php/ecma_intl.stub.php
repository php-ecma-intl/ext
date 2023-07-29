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

namespace Ecma\Intl
{
    /**
     * Categories of values supported by this implementation.
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
     * A Locale represents a Unicode locale identifier.
     *
     * @link https://tc39.es/ecma402/#locale-objects ECMA-402: Locale Objects
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale MDN: Intl.Locale
     * @link https://tc39.es/proposal-intl-locale-info/ Intl Locale Info Proposal
     */
    readonly class Locale implements \JsonSerializable, \Stringable
    {
        /**
         * The `baseName` property is a substring containing this locale's core
         * information, including language, script, region, and variant
         * information.
         *
         * The `baseName` does not contain any of the locale's keyword values.
         */
        public readonly string $baseName;

        /**
         * The `calendar` property has the calendar type for this locale.
         *
         * If neither the `ca` key of the locale identifier nor the `calendar`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $calendar;

        /**
         * The `caseFirst` property conveys whether case is taken into account
         * for this locale's collation rules.
         *
         * The `caseFirst` property can have one of the following three values:
         *
         * - `"upper"`, meaning upper case values are sorted before lower case.
         * - `"lower"`, meaning lower case values are sorted before upper case.
         * - `"false"`, meaning there is no special case ordering (this is a
         *   string value and not a boolean).
         *
         * If neither the `kf` key of the locale identifier nor the `caseFirst`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $caseFirst;

        /**
         * The `collation` property has the collation type for this locale.
         *
         * The collation type is used to order strings according to the locale's
         * rules.
         *
         * If neither the `co` key of the locale identifier nor the `collation`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $collation;

        /**
         * The `hourCycle` property has the hour cycle type for this locale.
         *
         * The `hourCycle` property can have one of the following four values:
         *
         * - `"h12"`, an hour system using 1-12 for a 12-hour clock, with
         *   midnight starting at 12:00 am.
         * - `"h23"`, an hour system using 0-23 for a 24-hour clock, with
         *   midnight starting at 0:00.
         * - `"h11"`, an hour system using 0-11 for a 12-hour clock, with
         *   midnight starting at 0:00 am.
         * - `"h24"`, an hour system using 1-24 for a 24-hour clock, with
         *   midnight starting at 24:00.
         *
         * If neither the `hc` key of the locale identifier nor the `hourCycle`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $hourCycle;

        /**
         * The `language` property has the language code for this locale.
         */
        public readonly string $language;

        /**
         * The `numberingSystem` property has the numeral system for this locale.
         *
         * If neither the `nu` key of the locale identifier nor the
         * `numberingSystem` property of the {@see Locale\Options} is set, this
         * value is `null`.
         */
        public readonly ?string $numberingSystem;

        /**
         * The `numeric` property conveys whether this locale has special
         * collation handling for numeric characters.
         */
        public readonly bool $numeric;

        /**
         * The `region` property has the region code for this locale.
         *
         * If neither the region part of the locale identifier nor the `region`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $region;

        /**
         * The `script` property has the script code for this locale.
         *
         * If neither the script part of the locale identifier nor the `script`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $script;

        /**
         * A Locale represents a Unicode locale identifier.
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
         * Returns a string representation of the full locale identifier.
         */
        public function __toString(): string
        {
        }

        /**
         * Returns an object of Locale properties and their values, suitable for
         * serializing to JSON.
         *
         * @return object
         */
        public function jsonSerialize(): object
        {
        }
    }
}

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
         * @param string|null $calendar The calendar to use with the locale
         * @param string|null $caseFirst The case sorting algorithm to use with
         *     the locale
         * @param string|null $collation The collation algorithm to use with the
         *     locale
         * @param string|null $hourCycle The hour cycle to use with the locale
         * @param string|null $language The locale's language
         * @param string|null $numberingSystem The locale's numbering system
         * @param bool|null $numeric Whether to sort a sequence of decimal
         *     digits with its numeric value (i.e, "A-21" < "A-123")
         * @param string|null $region The locale's region
         * @param string|null $script The locale's script
         */
        public function __construct(
            ?string $calendar = null,
            ?string $caseFirst = null,
            ?string $collation = null,
            ?string $hourCycle = null,
            ?string $language = null,
            ?string $numberingSystem = null,
            ?bool $numeric = null,
            ?string $region = null,
            ?string $script = null,
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
