.. _ecma.intl.supportedlocalesoptions:

===================================
Ecma\\Intl\\SupportedLocalesOptions
===================================

.. php:namespace:: Ecma\Intl
.. php:class:: SupportedLocalesOptions

    Options to use when evaluating supported locales.

    ECMA-402 defines a ``supportedLocalesOf()`` static method that is available
    on many of the classes provided in the specification. For example, see
    `Intl.Collator.supportedLocalesOf <https://tc39.es/ecma402/#sec-intl.collator.supportedlocalesof>`_.
    Each of these methods accepts an ``options`` object that specifies the
    locale matcher algorithm to use when evaluating supported locales. In this
    PHP implementation, :php:class:`Ecma\\Intl\\SupportedLocalesOptions` provides
    a type for this options object.

    .. php:attr:: localeMatcher: string | null, readonly

        The locale-matching algorithm to use when evaluating supported locales.

    .. php:method:: __construct([$localeMatcher = null])

        :param Stringable | string | null $localeMatcher: The locale-matching
            algorithm to use when evaluating supported locales. This may be one
            of the values ``"best fit"`` or ``"lookup"``. Other implementations
            may define additional values.

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
