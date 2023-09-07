<?php

/**
 * Copyright (c) php-ecma-intl contributors.
 *
 * This source file is subject to the BSD-3-Clause license that is bundled with
 * this package in the file LICENSE and is available at the following web
 * address: https://opensource.org/license/bsd-3-clause/
 *
 * This source file may utilize copyrighted material from third-party open
 * source projects, the use of which is acknowledged in the NOTICE file bundled
 * with this package.
 *
 * @generate-class-entries
 */

namespace Ecma\Intl\Locale
{
    /**
     * TextInfo represents typesetting information for the locale.
     *
     * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getTextInfo Intl Locale Info Proposal: getTextInfo()
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getTextInfo MDN: Intl.Locale.prototype.getTextInfo()
     * @link https://www.unicode.org/reports/tr35/tr35-general.html#Layout_Elements UTS 35: Layout Elements
     *
     * @strict-properties
     */
    readonly class TextInfo implements \JsonSerializable
    {
        /**
         * The character direction of the locale.
         */
        public readonly CharacterDirection $direction;

        /**
         * TextInfo represents typesetting information for the locale.
         *
         * @link https://tc39.es/proposal-intl-locale-info/#sec-Intl.Locale.prototype.getTextInfo Intl Locale Info Proposal: getTextInfo()
         * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getTextInfo MDN: Intl.Locale.prototype.getTextInfo()
         * @link https://www.unicode.org/reports/tr35/tr35-general.html#Layout_Elements UTS 35: Layout Elements
         *
         * @param CharacterDirection $direction The character direction of the locale.
         */
        public function __construct(CharacterDirection $direction)
        {
        }

        /**
         * Returns an object of TextInfo properties and their values, suitable
         * for serializing to JSON.
         *
         * @return object
         */
        public function jsonSerialize(): object
        {
        }
    }
}
