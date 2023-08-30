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
     * The character direction of a locale
     *
     * @link https://tc39.es/proposal-intl-locale-info/#sec-character-direction-of-locale Intl Locale Info Proposal: CharacterDirectionOfLocale
     * @link https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale/getTextInfo MDN: Intl.Locale.prototype.getTextInfo()
     */
    enum CharacterDirection: string
    {
        case LeftToRight = 'ltr';
        case RightToLeft = 'rtl';
    }
}
