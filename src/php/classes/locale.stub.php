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
         *
         * In the case of an undefined language code (i.e., "und"), this value
         * is `null`.
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
         * See {@see Locale::getTextInfo()}.
         */
        public readonly Locale\TextInfo $textInfo;

        /**
         * See {@see Locale::getTimeZones()}.
         *
         * @var string[]
         */
        public readonly ?array $timeZones;

        /**
         * See {@see Locale::getWeekInfo()}.
         */
        public readonly Locale\WeekInfo $weekInfo;

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
         *
         * @alias Ecma\Intl\Locale::toString
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
         * Returns a TextInfo object representing typesetting information for
         * the locale.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `textInfo`, so most browsers implement this as
         * `Locale.textInfo`. However, recent drafts of this proposal have
         * changed the design to the method `Locale.getTextInfo()`. As a result,
         * this implementation provides both {@see Locale::getTextInfo()} and
         * {@see Locale::$textInfo}, each of which return the same value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getTextInfo Intl Locale Info Proposal: getTextInfo()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getTextInfo MDN: Intl.Locale.prototype.getTextInfo()
         * @link https://www.unicode.org/reports/tr35/tr35-general.html#Layout_Elements UTS 35: Layout Elements
         */
        public function getTextInfo(): Locale\TextInfo
        {
        }

        /**
         * Returns a list of one or more time zone identifiers commonly used for
         * this locale.
         *
         * If the locale identifier does not contain a region subtag, this
         * returns null. If it has a region subtag but the region does not have
         * any commonly used time zone identifiers, this returns an empty array.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `timeZones`, so most browsers implement this as
         * `Locale.timeZones`. However, recent drafts of this proposal
         * have changed the design to the method `Locale.getTimeZones()`. As a
         * result, this implementation provides both
         * {@see Locale::getTimeZones()} and
         * {@see Locale::$timeZones}, each of which return the same
         * value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getTimeZones Intl Locale Info Proposal: getTimeZones()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getTimeZones MDN: Intl.Locale.prototype.getTimeZones()
         *
         * @return string[]|null
         */
        public function getTimeZones(): ?array
        {
        }

        /**
         * Returns a WeekInfo object representing locale-specific information
         * about the days of the week, for calendar purposes.
         *
         * This method is defined as part of the "Intl Locale Info Proposal," an
         * ECMA-402 stage 3 draft. Originally, it was defined as a property
         * accessor named `weekInfo`, so most browsers implement this as
         * `Locale.weekInfo`. However, recent drafts of this proposal have
         * changed the design to the method `Locale.getWeekInfo()`. As a result,
         * this implementation provides both {@see Locale::getWeekInfo()} and
         * {@see Locale::$weekInfo}, each of which return the same value.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getWeekInfo Intl Locale Info Proposal: getWeekInfo()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getWeekInfo MDN: Intl.Locale.prototype.getWeekInfo()
         * @link https://www.unicode.org/reports/tr35/tr35-dates.html#Date_Patterns_Week_Elements UTS 35: Week Elements
         */
        public function getWeekInfo(): Locale\WeekInfo
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

        /**
         * Returns a string representation of the full locale identifier.
         */
        public function toString(): string
        {
        }
    }
}
