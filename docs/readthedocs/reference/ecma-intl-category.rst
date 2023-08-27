.. _ecma.intl.category:

====================
Ecma\\Intl\\Category
====================

.. php:namespace:: Ecma\Intl
.. php:enum:: Category : string

    Categories of values supported by this implementation.

    While ECMA-402 defines these as static string values of "calendar,"
    "collation," "currency," "numberingSystem," "timeZone," and "unit," this
    implementation uses a native PHP enum to take advantage of strong typing.

    .. php:case:: Calendar : 'calendar'
    .. php:case:: Collation : 'collation'
    .. php:case:: Currency : 'currency'
    .. php:case:: NumberingSystem : 'numberingSystem'
    .. php:case:: TimeZone : 'timeZone'
    .. php:case:: Unit : 'unit'
