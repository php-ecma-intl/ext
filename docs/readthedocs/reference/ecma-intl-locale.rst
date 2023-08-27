.. _ecma.intl.locale:

==================
Ecma\\Intl\\Locale
==================

.. php:namespace:: Ecma\Intl
.. php:class:: Locale

    A Locale represents a Unicode locale identifier.

    .. php:attr:: baseName: string | null, readonly

        The ``baseName`` property is a substring containing this locale's core
        information, including language, script, region, and variant
        information.

        The ``baseName`` does not contain any of the locale's keyword values.

    .. php:attr:: calendar: string | null, readonly

        The ``calendar`` property has the calendar type for this locale.

        If neither the ``ca`` key of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$calendar` option is set, this
        value is `null`.

    .. php:attr:: calendars: string[], readonly

        See :php:meth:`Ecma\\Intl\\Locale::getCalendars()`.

    .. php:attr:: caseFirst: string | null, readonly

        The ``caseFirst`` property conveys whether case is taken into account
        for this locale's collation rules.

        The ``caseFirst`` property can have one of the following three values:

        - ``"upper"``, meaning upper case values are sorted before lower case.
        - ``"lower"``, meaning lower case values are sorted before upper case.
        - ``"false"``, meaning there is no special case ordering (this is a
          string value and not a boolean).

        If neither the ``kf`` key of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$caseFirst` option is set, this
        value is `null`.

    .. php:attr:: collation: string | null, readonly

        The ``collation`` property has the collation type for this locale.

        The collation type is used to order strings according to the locale's
        rules.

        If neither the ``co`` key of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$collation` option is set, this
        value is `null`.

    .. php:attr:: collations: string[], readonly

        See :php:meth:`Ecma\\Intl\\Locale::getCollations()`.

    .. php:attr:: hourCycle: string | null, readonly

        The ``hourCycle`` property has the hour cycle type for this locale.

        The ``hourCycle`` property can have one of the following four values:

        - ``"h12"``, an hour system using 1-12 for a 12-hour clock, with
          midnight starting at 12:00 am.
        - ``"h23"``, an hour system using 0-23 for a 24-hour clock, with
          midnight starting at 0:00.
        - ``"h11"``, an hour system using 0-11 for a 12-hour clock, with
          midnight starting at 0:00 am.
        - ``"h24"``, an hour system using 1-24 for a 24-hour clock, with
          midnight starting at 24:00.

        If neither the ``hc`` key of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$hourCycle` option is set, this
        value is `null`.

    .. php:attr:: hourCycles: string[], readonly

        See :php:meth:`Ecma\\Intl\\Locale::getHourCycles()`.

    .. php:attr:: language: string | null, readonly

        The ``language`` property has the language code for this locale.

        In the case of an undefined language code (i.e., "und"), this value
        is ``null``.

    .. php:attr:: numberingSystem: string | null, readonly

        The ``numberingSystem`` property has the numeral system for this locale.

        If neither the ``nu`` key of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$numberingSystem` option is set,
        this value is `null`.

    .. php:attr:: numberingSystems: string[], readonly

        See :php:meth:`Ecma\\Intl\\Locale::getNumberingSystems()`.

    .. php:attr:: numeric: bool, readonly

        The ``numeric`` property conveys whether this locale has special
        collation handling for numeric characters.

    .. php:attr:: region: string | null, readonly

        The ``region`` property has the region code for this locale.

        If neither the region part of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$region` option is set, this
        value is `null`.

    .. php:attr:: script: string | null, readonly

        The ``script`` property has the script code for this locale.

        If neither the script part of the locale identifier nor the
        :php:attr:`Ecma\\Intl\\Locale\\Options::$script` option is set, this
        value is `null`.

    .. php:attr:: textInfo: Ecma\Intl\Locale\TextInfo, readonly

        See :php:meth:`Ecma\\Intl\\Locale::getTextInfo()`.

    .. php:attr:: timeZones: string[] | null, readonly

        See :php:meth:`Ecma\\Intl\\Locale::getTimeZones()`.

    .. php:attr:: weekInfo: Ecma\Intl\Locale\WeekInfo, readonly

        See :php:meth:`Ecma\\Intl\\Locale::getWeekInfo()`.

    .. php:method:: __construct($tag[, $options = null])

        Constructs an instance of a Unicode locale identifier.

        :param Stringable | string $tag: The language tag (or locale identifier).
        :param Ecma\\Intl\\Locale\\Options $options: Additional options to
            apply to the locale. If the ``$tag`` already has values for any of the
            options provided, the values on the ``$options`` parameter will override
            those on the ``$tag``.

    .. php:method:: __toString(): string

        Returns a string representation of the full locale identifier.

        Alias of :php:meth:`Ecma\\Intl\\Locale::toString()`.

    .. php:method:: getCalendars(): string[]

        Returns a list of one or more calendar types commonly used for this
        locale.

        If the locale already includes a calendar (e.g., ``en-u-ca-buddhist``)
        or one was provided via the constructor's ``$options`` parameter, this
        list will contain only that calendar type.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``calendars``, so
        most browsers implement this as ``Locale.calendars``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getCalendars()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getCalendars()` and
        :php:attr:`Ecma\\Intl\\Locale::$calendars`, each of which return the same
        value.

    .. php:method:: getCollations(): string[]

        Returns a list of one or more collation types commonly used for this
        locale.

        If the locale already includes a collation (e.g., ``en-u-co-emoji``) or
        one was provided via the constructor's ``$options`` parameter, this
        list will contain only that collation type.

        The ``standard`` and ``search`` collation types are always excluded from
        this list.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``collations``, so
        most browsers implement this as ``Locale.collations``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getCollations()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getCollations()` and
        :php:attr:`Ecma\\Intl\\Locale::$collations`, each of which return the same
        value.

    .. php:method:: getCurrencies(): string[]

        Returns a list of one or more currency types commonly used for this
        locale.

        This method is not defined in ECMA-402 or in the `Intl Locale Info
        Proposal <https://tc39.es/proposal-intl-locale-info/>`_ in which other
        similar methods are described. Instead, this is unique to the PHP
        implementation and draws its inspiration from the Intl Locale Info
        Proposal.

    .. php:method:: getHourCycles(): string[]

        Returns a list of one or more hour cycle types commonly used for this
        locale.

        If the locale already includes an hour cycle (e.g., ``en-u-hc-h11``) or
        one was provided via the constructor's ``$options`` parameter, this
        list will contain only that hour cycle type.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``hourCycles``, so
        most browsers implement this as ``Locale.hourCycles``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getHourCycles()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getHourCycles()` and
        :php:attr:`Ecma\\Intl\\Locale::$hourCycles`, each of which return the same
        value.

    .. php:method:: getNumberingSystems(): string[]

        Returns a list of one or more numbering systems commonly used for
        this locale.

        If the locale already includes a numbering system (e.g.,
        ``en-u-nu-arab``) or one was provided via the constructor's ``$options``
        parameter, this list will contain only that numbering system.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``numberingSystems``, so
        most browsers implement this as ``Locale.numberingSystems``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getNumberingSystems()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getNumberingSystems()` and
        :php:attr:`Ecma\\Intl\\Locale::$numberingSystems`, each of which return the same
        value.

    .. php:method:: getTextInfo(): Ecma\Intl\Locale\TextInfo

        Returns an :php:class:`Ecma\\Intl\\Locale\\TextInfo` object representing
        typesetting information for the locale.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``textInfo``, so
        most browsers implement this as ``Locale.textInfo``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getTextInfo()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getTextInfo()` and
        :php:attr:`Ecma\\Intl\\Locale::$textInfo`, each of which return the same
        value.

    .. php:method:: getTimeZones(): string[] | null

        Returns a list of one or more time zone identifiers commonly used for
        this locale.

        If the locale identifier does not contain a region subtag, this
        returns ``null``. If it has a region subtag but the region does not have
        any commonly used time zone identifiers, this returns an empty array.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``timeZones``, so
        most browsers implement this as ``Locale.timeZones``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getTimeZones()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getTimeZones()` and
        :php:attr:`Ecma\\Intl\\Locale::$timeZones`, each of which return the same
        value.

    .. php:method:: getWeekInfo(): Ecma\Intl\Locale\WeekInfo

        Returns an :php:class:`Ecma\\Intl\\Locale\\WeekInfo` object representing
        locale-specific information about the days of the week, for calendar purposes.

        This method is defined as part of the `Intl Locale Info Proposal
        <https://tc39.es/proposal-intl-locale-info/>`_, an ECMA-402 stage 3 draft.
        Originally, it was defined as a property accessor named ``weekInfo``, so
        most browsers implement this as ``Locale.weekInfo``. However, recent
        drafts of this proposal have changed the design to the method
        ``Locale.getWeekInfo()``. As a result, this implementation provides both
        :php:meth:`Ecma\\Intl\\Locale::getWeekInfo()` and
        :php:attr:`Ecma\\Intl\\Locale::$weekInfo`, each of which return the same
        value.

    .. php:method:: jsonSerialize(): object

        Returns an object of Locale properties and their values, suitable for
        serializing to JSON.

    .. php:method:: maximize(): Ecma\Intl\Locale

        Returns a new instance of :php:class:`Ecma\\Intl\\Locale` with all likely
        sub tags added according to `the algorithm in Unicode Technical Standard #35
        <https://www.unicode.org/reports/tr35/#Likely_Subtags>`_.

        For example:

        - "en" maximizes to "en-Latn-US"
        - "de" maximizes to "de-Latn-DE"
        - "sr" maximizes to "sr-Cyrl-RS"
        - "sh" maximizes to "sr-Latn-RS"
        - "zh" maximizes to "zh-Hans-CN"

    .. php:method:: minimize(): Ecma\Intl\Locale

        Returns a new instance of :php:class:`Ecma\\Intl\\Locale` with sub tags
        removed according to `the algorithm in Unicode Technical Standard #35
        <https://www.unicode.org/reports/tr35/#Likely_Subtags>`_.

        For example:

        - "en-Latn-US" minimizes to "en"
        - "de-Latn-DE" minimizes to "de"
        - "sr-Cyrl-RS" minimizes to "sr"
        - "zh-Hant-TW" minimizes to "zh-TW"

    .. php:method:: toString(): string

        Returns a string representation of the full locale identifier.
