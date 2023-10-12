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

    .. php:staticmethod:: defaultLocale(): Ecma\Intl\Locale

        Returns the currently configured default locale as an
        :php:class:`Ecma\\Intl\\Locale` instance.

        The default locale is the value set using the INI property
        ``ecma_intl.default_locale``. If this property is not set or does not
        validate as a supported locale for this implementation, this falls
        back to the default locale determined by the ICU library. If that
        fails to find a default locale (unlikely), the default locale falls
        back to ``"en"``.

        The return value is always a new object instance, even if the default
        locale does not change. This means:
        ``Intl::defaultLocale() !== Intl::defaultLocale()``.

        .. note::

            This static method is not defined by ECMA-402.

    .. php:staticmethod:: getCanonicalLocales($locales): string[]

        Returns an array of canonical locale names for the input locale(s).

        :param iterable<Stringable|string> | Stringable | string | null $locales: One or more locales to canonicalize.

    .. php:staticmethod:: supportedValuesOf($category): string[]

        Returns an array containing the calendar, collation, currency, numbering
        system, or unit values supported by this implementation.

        :param Ecma\\Intl\\Category $category: The category to get the supported values of.
