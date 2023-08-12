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
     *
     * @strict-properties
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
        public readonly ?string $baseName;

        /**
         * The `calendar` property has the calendar type for this locale.
         *
         * If neither the `ca` key of the locale identifier nor the `calendar`
         * property of the {@see Locale\Options} is set, this value is `null`.
         */
        public readonly ?string $calendar;

        /**
         * See {@see Locale::getCalendars()}.
         *
         * @var string[]
         */
        public readonly array $calendars;

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
         * See {@see Locale::getCollations()}.
         *
         * @var string[]
         */
        public readonly array $collations;

        /**
         * See {@see Locale::getCurrencies()}.
         *
         * @var string[]
         */
        public readonly array $currencies;

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
         * See {@see Locale::getHourCycles()}.
         *
         * @var string[]
         */
        public readonly array $hourCycles;

        /**
         * The `language` property has the language code for this locale.
         */
        public readonly ?string $language;

        /**
         * The `numberingSystem` property has the numeral system for this locale.
         *
         * If neither the `nu` key of the locale identifier nor the
         * `numberingSystem` property of the {@see Locale\Options} is set, this
         * value is `null`.
         */
        public readonly ?string $numberingSystem;

        /**
         * See {@see Locale::getNumberingSystems()}.
         *
         * @var string[]
         */
        public readonly array $numberingSystems;

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
         * @param Locale\Options|null $options Additional options to apply to
         *     the locale. If the $tag already has values for any of the options
         *     provided, the values on the $options parameter will override
         *     those on the $tag.
         */
        public function __construct(\Stringable|string $tag, ?Locale\Options $options = null)
        {
        }

        /**
         * Returns a string representation of the full locale identifier.
         */
        public function __toString(): string
        {
        }

        /**
         * Returns a list of one or more calendar types commonly used for this
         * locale.
         *
         * If the locale already includes a calendar (e.g., `en-u-ca-buddhist`)
         * or one was provided via the constructor's `$options` parameter, this
         * list will contain only that calendar type.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `calendars`, so most browsers implement this as
         * `Locale.calendars`. However, recent drafts of this proposal have
         * changed the design to the method `Locale.getCalendars()`. As a result,
         * this implementation provides both {@see Locale::getCalendars()} and
         * {@see Locale::$calendars}, each of which return the same value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getCalendars Intl Locale Info Proposal: getCalendars()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getCalendars MDN: Intl.Locale.prototype.getCalendars()
         *
         * @return string[]
         */
        public function getCalendars(): array
        {
        }

        /**
         * Returns a list of one or more collation types commonly used for this
         * locale.
         *
         * If the locale already includes a collation (e.g., `en-u-co-emoji`) or
         * one was provided via the constructor's `$options` parameter, this
         * list will contain only that collation type.
         *
         * The `standard` and `search` collation types are always excluded from
         * this list.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `collations`, so most browsers implement this as
         * `Locale.collations`. However, recent drafts of this proposal have
         * changed the design to the method `Locale.getCollation()`. As a result,
         * this implementation provides both {@see Locale::getCollations()} and
         * {@see Locale::$collations}, each of which return the same value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getCollations Intl Locale Info Proposal: getCollations()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getCollations MDN: Intl.Locale.prototype.getCollations()
         *
         * @return string[]
         */
        public function getCollations(): array
        {
        }

        /**
         * Returns a list of one or more currency types commonly used for this
         * locale.
         *
         * This method is not defined in ECMA-402 or in the Intl Locale Info
         * Proposal in which other similar methods are described. Instead, this
         * is unique to the PHP implementation and draws its inspiration from
         * the Intl Locale Info Proposal.
         *
         * @link https://tc39.es/proposal-intl-locale-info/ Intl Locale Info Proposal
         * @link https://github.com/tc39/proposal-intl-locale-info/issues/75 Possible of addition of Intl.Locale.prototype.getCurrencies()?
         *
         * @return string[]
         */
        public function getCurrencies(): array
        {
        }

        /**
         * Returns a list of one or more hour cycle types commonly used for this
         * locale.
         *
         * If the locale already includes an hour cycle (e.g., `en-u-hc-h11`) or
         * one was provided via the constructor's `$options` parameter, this
         * list will contain only that hour cycle type.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `hourCycles`, so most browsers implement this as
         * `Locale.hourCycles`. However, recent drafts of this proposal have
         * changed the design to the method `Locale.getHourCycles()`. As a
         * result, this implementation provides both
         * {@see Locale::getHourCycles()} and {@see Locale::$hourCycles}, each
         * of which return the same value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getHourCycles Intl Locale Info Proposal: getHourCycles()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getHourCycles MDN: Intl.Locale.prototype.getHourCycles()
         *
         * @return string[]
         */
        public function getHourCycles(): array
        {
        }

        /**
         * Returns a list of one or more numbering systems commonly used for
         * this locale.
         *
         * If the locale already includes a numbering system (e.g.,
         * `en-u-nu-arab`) or one was provided via the constructor's `$options`
         * parameter, this list will contain only that numbering system.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `numberingSystems`, so most browsers implement this as
         * `Locale.numberingSystems`. However, recent drafts of this proposal
         * have changed the design to the method `Locale.getNumberingSystems()`.
         * As a result, this implementation provides both
         * {@see Locale::getNumberingSystems()} and
         * {@see Locale::$numberingSystems}, each of which return the same
         * value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getNumberingSystems Intl Locale Info Proposal: getNumberingSystems()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getNumberingSystems MDN: Intl.Locale.prototype.getNumberingSystems()
         *
         * @return string[]
         */
        public function getNumberingSystems(): array
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

        /**
         * Returns a new instance of the locale with all likely sub tags added according to the
         * {@link https://www.unicode.org/reports/tr35/#Likely_Subtags algorithm in Unicode Technical Standard #35}.
         *
         * For example:
         *
         * - "en" maximizes to "en-Latn-US"
         * - "de" maximizes to "de-Latn-DE"
         * - "sr" maximizes to "sr-Cyrl-RS"
         * - "sh" maximizes to "sr-Latn-RS"
         * - "zh" maximizes to "zh-Hans-CN"
         */
        public function maximize(): Locale
        {
        }

        /**
         * Returns a new instance of the locale with sub tags removed according to the
         * {@link https://www.unicode.org/reports/tr35/#Likely_Subtags algorithm in Unicode Technical Standard #35}.
         *
         * For example:
         *
         * - "en-Latn-US" minimizes to "en"
         * - "de-Latn-DE" minimizes to "de"
         * - "sr-Cyrl-RS" minimizes to "sr"
         * - "zh-Hant-TW" minimizes to "zh-TW"
         */
        public function minimize(): Locale
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
