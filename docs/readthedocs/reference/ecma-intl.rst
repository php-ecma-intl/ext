.. _ecma.intl:

==========
Ecma\\Intl
==========

.. php:namespace:: Ecma
.. php:class:: Intl

    .. php:const:: ICU_VERSION

        The current ICU library version.

    .. php:const:: UNICODE_VERSION

        The current Unicode version number.

    .. php:staticmethod:: getCanonicalLocales($locales): string[]

        Returns an array of canonical locale names for the input locale(s).

        :param iterable<Stringable|string> | Stringable | string | null $locales: One or more locales to canonicalize.

    .. php:staticmethod:: supportedValuesOf($category): string[]

        Returns an array containing the calendar, collation, currency, numbering
        system, or unit values supported by this implementation.

        :param Ecma\\Intl\\Category $category: The category to get the supported values of.
