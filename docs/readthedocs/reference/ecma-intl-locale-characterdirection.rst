.. _ecma.intl.locale.characterdirection:

======================================
Ecma\\Intl\\Locale\\CharacterDirection
======================================

.. php:namespace:: Ecma\Intl\Locale
.. php:enum:: CharacterDirection : string

    The character direction of a locale.

    While ECMA-402 defines these as static string values of "ltr" and "rtl," this
    implementation uses a native PHP enum to take advantage of strong typing.

    .. php:case:: LeftToRight : 'ltr'
    .. php:case:: RightToLeft : 'rtl'
