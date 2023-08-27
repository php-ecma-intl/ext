.. _ecma.intl.locale.options:

===========================
Ecma\\Intl\\Locale\\Options
===========================

.. php:namespace:: Ecma\Intl\Locale
.. php:class:: Options

    Configuration for the locale.

    Any property set on the Options object passed to the Locale's
    constructor will override the same properties on the language tag passed
    to the Locale.

    This class implements ``Iterator`` to allow instances for use in array
    unpacking scenarios. For example:

    .. code-block:: php

        use Ecma\Intl\Locale\Options;
        $commonOptions = new Options(hourCycle: 'h23');
        $englishOptions = new Options(...[...$commonOptions, 'language' => 'en']);

    Please note that ``null`` values will be skipped when unpacking or iterating
    over them. This facilitates scenarios where you might return JSON-encoded
    values to be used by ``Intl.Locale`` instances in JavaScript.

    .. php:attr:: calendar: string | null, readonly

        The calendar to set on the locale.

    .. php:attr:: caseFirst: string | null, readonly

        The case sorting algorithm to set on the locale.

    .. php:attr:: collation: string | null, readonly

        The collation algorithm to set on the locale.

    .. php:attr:: hourCycle: string | null, readonly

        The hour cycle to set on the locale.

    .. php:attr:: language: string | null, readonly

        The language to set on the locale.

    .. php:attr:: numberingSystem: string | null, readonly

        The numbering system to set on the locale.

    .. php:attr:: numeric: bool | null, readonly

        Whether to sort a sequence of decimal digits with its numeric value
        (i.e, ``"A-21" < "A-123"``).

    .. php:attr:: region: string | null, readonly

        The region to set on the locale.

    .. php:attr:: script: string | null, readonly

        The script to set on the locale.

    .. php:method:: __construct([$calendar = null[, $caseFirst = null[, $collation = null[, $hourCycle = null[, $language = null[, $numberingSystem = null[, $numeric = null[, $region = null[, $script = null]]]]]]]]])

        :param Stringable | string | null $calendar: The calendar to use with the locale.
        :param Stringable | string | false | null $caseFirst: The case sorting algorithm to use with the locale.
        :param Stringable | string | null $collation: The collation algorithm to use with the locale.
        :param Stringable | string | null $hourCycle: The hour cycle to use with the locale.
        :param Stringable | string | null $language: The language to use with the locale.
        :param Stringable | string | null $numberingSystem: The numbering system to use with the locale.
        :param bool | null $numeric: Whether to sort a sequence of decimal digits with its numeric value (i.e, ``"A-21" < "A-123"``).
        :param Stringable | string | null $region: The region to use with the locale.
        :param Stringable | string | null $script: The script to use with the locale.

    .. php:method:: jsonSerialize(): object

        Returns an object of these options, suitable for serializing to JSON.

        Please note that any options with a ``null`` value will not be included
        in the object this method returns. This allows the JSON to be passed to
        JavaScript contexts, where these properties are considered ``undefined``.

    .. php:method:: current(): string | bool

    .. php:method:: next(): void

    .. php:method:: key(): string

    .. php:method:: valid(): bool

    .. php:method:: rewind(): void
