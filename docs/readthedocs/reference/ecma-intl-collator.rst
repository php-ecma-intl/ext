.. _ecma.intl.collator:

====================
Ecma\\Intl\\Collator
====================

.. php:namespace:: Ecma\Intl
.. php:class:: Collator

    .. php:staticmethod:: supportedLocalesOf($locales[, $options = null]): string[]

        Returns an array of those locales provided that are supported by this
        implementation without having to fall back to the default locale.

        :param iterable<Stringable|string> | Stringable | string | null $locales: One
            or more language tags to check for support.
        :param Ecma\\Intl\\SupportedLocales\\Options $options: Options to use when
            evaluating supported locales.
