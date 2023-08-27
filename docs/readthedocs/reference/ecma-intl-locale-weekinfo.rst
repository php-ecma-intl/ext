.. _ecma.intl.locale.weekinfo:

============================
Ecma\\Intl\\Locale\\WeekInfo
============================

.. php:namespace:: Ecma\Intl\Locale
.. php:class:: WeekInfo

    WeekInfo represents locale-specific information about the days of the
    week, for calendar purposes.

    .. php:attr:: firstDay : Ecma\Intl\Locale\WeekDay

        The week day that is considered the first day of the week for the locale.

    .. php:attr:: minimalDays : int<1, 7>

        The minimum days required in the first week of a month or year for the locale.

    .. php:attr:: weekend : Ecma\Intl\Locale\WeekDay[]

        A list of week days that are considered part of the weekend for the locale.

        Please note, the number of weekend days in each locale may be different,
        and they may not be contiguous.

    .. php:method:: __construct($firstDay, $weekend, $minimalDays)

        :param Ecma\\Intl\\Locale\\WeekDay $firstDay: The week day that is considered the *first* day of the week.
        :param Ecma\\Intl\\Locale\\WeekDay[] $weekend: A list of week days that are considered part of the weekend.
        :param int<1, 7> $minimalDays: The minimum days required in the first week of a month or year.

    .. php:method:: jsonSerialize(): object

        Returns an object of WeekInfo properties and their values, suitable for
        serializing to JSON.
