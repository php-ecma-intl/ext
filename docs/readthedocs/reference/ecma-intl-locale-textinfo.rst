.. _ecma.intl.locale.textinfo:

============================
Ecma\\Intl\\Locale\\TextInfo
============================

.. php:namespace:: Ecma\Intl\Locale
.. php:class:: TextInfo

    TextInfo represents typesetting information for the locale.

    .. php:attr:: direction: Ecma\Intl\Locale\CharacterDirection, readonly

        The character direction of the locale.

    .. php:method:: __construct($direction)

        :param Ecma\\Intl\\Locale\\CharacterDirection $direction: The character direction of the locale.

    .. php:method:: jsonSerialize(): object

        Returns an object of TextInfo properties and their values, suitable for
        serializing to JSON.
