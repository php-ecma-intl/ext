<?php

use Ecma\Test\TestCase;

uses(TestCase::class)->in('pest');

/**
 * @link https://unicode.org/reports/tr35/tr35.html#Unicode_locale_identifier Unicode Locale Identifier
 */
const TYPE_PRODUCTION_PATTERN = '/^[a-z0-9]{3,8}(-[a-z0-9]{3,8})*$/';

/**
 * Pattern that matches three-letter ISO 4217 currency codes
 *
 * @link https://tc39.es/ecma402/#sec-availablecanonicalcurrencies ECMA-402, section 6.4, AVailableCanonicalCurrencies()
 */
const CURRENCY_PATTERN = '/^[A-Z]{3}$/';

/**
 * Provides the digits of numbering systems with simple digit mappings,
 * as specified in ECMA-402, table 14.
 *
 * @link https://tc39.es/ecma402/#table-numbering-system-digits ECMA-402, table 14.
 */
const NUMBERING_SYSTEM_DIGITS = [
    'adlm' => '𞥐𞥑𞥒𞥓𞥔𞥕𞥖𞥗𞥘𞥙',
    'ahom' => '𑜰𑜱𑜲𑜳𑜴𑜵𑜶𑜷𑜸𑜹',
    'arab' => '٠١٢٣٤٥٦٧٨٩',
    'arabext' => '۰۱۲۳۴۵۶۷۸۹',
    'bali' => "\u{1B50}\u{1B51}\u{1B52}\u{1B53}\u{1B54}\u{1B55}\u{1B56}\u{1B57}\u{1B58}\u{1B59}",
    'beng' => '০১২৩৪৫৬৭৮৯',
    'bhks' => '𑱐𑱑𑱒𑱓𑱔𑱕𑱖𑱗𑱘𑱙',
    'brah' => '𑁦𑁧𑁨𑁩𑁪𑁫𑁬𑁭𑁮𑁯',
    'cakm' => '𑄶𑄷𑄸𑄹𑄺𑄻𑄼𑄽𑄾𑄿',
    'cham' => '꩐꩑꩒꩓꩔꩕꩖꩗꩘꩙',
    'deva' => '०१२३४५६७८९',
    'diak' => '𑥐𑥑𑥒𑥓𑥔𑥕𑥖𑥗𑥘𑥙',
    'fullwide' => '０１２３４５６７８９',
    'gong' => '𑶠𑶡𑶢𑶣𑶤𑶥𑶦𑶧𑶨𑶩',
    'gonm' => '𑵐𑵑𑵒𑵓𑵔𑵕𑵖𑵗𑵘𑵙',
    'gujr' => '૦૧૨૩૪૫૬૭૮૯',
    'guru' => '੦੧੨੩੪੫੬੭੮੯',
    'hanidec' => '〇一二三四五六七八九',
    'hmng' => '𖭐𖭑𖭒𖭓𖭔𖭕𖭖𖭗𖭘𖭙',
    'hmnp' => '𞅀𞅁𞅂𞅃𞅄𞅅𞅆𞅇𞅈𞅉',
    'java' => '꧐꧑꧒꧓꧔꧕꧖꧗꧘꧙',
    'kali' => '꤀꤁꤂꤃꤄꤅꤆꤇꤈꤉',
    'khmr' => '០១២៣៤៥៦៧៨៩',
    'knda' => '೦೧೨೩೪೫೬೭೮೯',
    'lana' => '᪀᪁᪂᪃᪄᪅᪆᪇᪈᪉',
    'lanatham' => '᪐᪑᪒᪓᪔᪕᪖᪗᪘᪙',
    'laoo' => '໐໑໒໓໔໕໖໗໘໙',
    'latn' => '0123456789',
    'lepc' => '᱀᱁᱂᱃᱄᱅᱆᱇᱈᱉',
    'limb' => "\u{1946}\u{1947}\u{1948}\u{1949}\u{194A}\u{194B}\u{194C}\u{194D}\u{194E}\u{194F}",
    'mathbold' => '𝟎𝟏𝟐𝟑𝟒𝟓𝟔𝟕𝟖𝟗',
    'mathdbl' => '𝟘𝟙𝟚𝟛𝟜𝟝𝟞𝟟𝟠𝟡',
    'mathmono' => '𝟶𝟷𝟸𝟹𝟺𝟻𝟼𝟽𝟾𝟿',
    'mathsanb' => '𝟬𝟭𝟮𝟯𝟰𝟱𝟲𝟳𝟴𝟵',
    'mathsans' => '𝟢𝟣𝟤𝟥𝟦𝟧𝟨𝟩𝟪𝟫',
    'mlym' => '൦൧൨൩൪൫൬൭൮൯',
    'modi' => '𑙐𑙑𑙒𑙓𑙔𑙕𑙖𑙗𑙘𑙙',
    'mong' => '᠐᠑᠒᠓᠔᠕᠖᠗᠘᠙',
    'mroo' => '𖩠𖩡𖩢𖩣𖩤𖩥𖩦𖩧𖩨𖩩',
    'mtei' => '꯰꯱꯲꯳꯴꯵꯶꯷꯸꯹',
    'mymr' => '၀၁၂၃၄၅၆၇၈၉',
    'mymrshan' => '႐႑႒႓႔႕႖႗႘႙',
    'mymrtlng' => '꧰꧱꧲꧳꧴꧵꧶꧷꧸꧹',
    'newa' => '𑑐𑑑𑑒𑑓𑑔𑑕𑑖𑑗𑑘𑑙',
    'nkoo' => '߀߁߂߃߄߅߆߇߈߉',
    'olck' => '᱐᱑᱒᱓᱔᱕᱖᱗᱘᱙',
    'orya' => '୦୧୨୩୪୫୬୭୮୯',
    'osma' => '𐒠𐒡𐒢𐒣𐒤𐒥𐒦𐒧𐒨𐒩',
    'rohg' => '𐴰𐴱𐴲𐴳𐴴𐴵𐴶𐴷𐴸𐴹',
    'saur' => '꣐꣑꣒꣓꣔꣕꣖꣗꣘꣙',
    'segment' => '🯰🯱🯲🯳🯴🯵🯶🯷🯸🯹',
    'shrd' => '𑇐𑇑𑇒𑇓𑇔𑇕𑇖𑇗𑇘𑇙',
    'sind' => '𑋰𑋱𑋲𑋳𑋴𑋵𑋶𑋷𑋸𑋹',
    'sinh' => '෦෧෨෩෪෫෬෭෮෯',
    'sora' => '𑃰𑃱𑃲𑃳𑃴𑃵𑃶𑃷𑃸𑃹',
    'sund' => '᮰᮱᮲᮳᮴᮵᮶᮷᮸᮹',
    'takr' => '𑛀𑛁𑛂𑛃𑛄𑛅𑛆𑛇𑛈𑛉',
    'talu' => '᧐᧑᧒᧓᧔᧕᧖᧗᧘᧙',
    'tamldec' => '௦௧௨௩௪௫௬௭௮௯',
    'tnsa' => "\u{16AC0}\u{16AC1}\u{16AC2}\u{16AC3}\u{16AC4}\u{16AC5}\u{16AC6}\u{16AC7}\u{16AC8}\u{16AC9}",
    'telu' => '౦౧౨౩౪౫౬౭౮౯',
    'thai' => '๐๑๒๓๔๕๖๗๘๙',
    'tibt' => '༠༡༢༣༤༥༦༧༨༩',
    'tirh' => '𑓐𑓑𑓒𑓓𑓔𑓕𑓖𑓗𑓘𑓙',
    'vaii' => '꘠꘡꘢꘣꘤꘥꘦꘧꘨꘩',
    'wara' => '𑣠𑣡𑣢𑣣𑣤𑣥𑣦𑣧𑣨𑣩',
    'wcho' => '𞋰𞋱𞋲𞋳𞋴𞋵𞋶𞋷𞋸𞋹',
];

/**
 * @link https://tc39.es/ecma402/#table-sanctioned-single-unit-identifiers
 */
const SANCTIONED_SINGLE_UNITS = [
    'acre',
    'bit',
    'byte',
    'celsius',
    'centimeter',
    'day',
    'degree',
    'fahrenheit',
    'fluid-ounce',
    'foot',
    'gallon',
    'gigabit',
    'gigabyte',
    'gram',
    'hectare',
    'hour',
    'inch',
    'kilobit',
    'kilobyte',
    'kilogram',
    'kilometer',
    'liter',
    'megabit',
    'megabyte',
    'meter',
    'microsecond',
    'mile',
    'mile-scandinavian',
    'milliliter',
    'millimeter',
    'millisecond',
    'minute',
    'month',
    'nanosecond',
    'ounce',
    'percent',
    'petabyte',
    'pound',
    'second',
    'stone',
    'terabit',
    'terabyte',
    'week',
    'yard',
    'year',
];

/**
 * Tests whether timeZone is a String value representing a structurally valid
 * and canonicalized time zone name, as defined in sections 6.5.1 and 6.5.2 of
 * the ECMAScript Internationalization API Specification.
 */
function isCanonicalizedStructurallyValidTimeZoneName(string $timeZone): bool
{
    /**
     * Regular expression defining IANA Time Zone names.
     *
     * Spec: IANA Time Zone Database, Theory file
     */
    $fileNameComponent = '(?:[A-Za-z_]|\.(?!\.?(?:/|$)))[A-Za-z.\-_]{0,13}';
    $fileName = $fileNameComponent . '(?:/' . $fileNameComponent . ')*';
    $etcName = '(?:Etc/)?GMT[+-]\d{1,2}';
    $systemVName = 'SystemV/[A-Z]{3}\d{1,2}(?:[A-Z]{3})?';
    $legacyName = $etcName . '|' . $systemVName . '|CST6CDT|EST5EDT|MST7MDT|PST8PDT|NZ';
    $zoneNamePattern = '#^(?:' . $fileName . '|' . $legacyName . ')$#';

    // 6.5.2 CanonicalizeTimeZoneName (timeZone), step 3
    if ($timeZone === 'UTC') {
        return true;
    }

    // 6.5.2 CanonicalizeTimeZoneName (timeZone), step 3
    if ($timeZone === 'Etc/UTC' || $timeZone === 'Etc/GMT' || $timeZone === 'GMT') {
        return false;
    }

    return (bool) preg_match($zoneNamePattern, $timeZone);
}

/**
 * Returns an array of strings for which IsStructurallyValidLanguageTag() returns false
 *
 * @link https://github.com/tc39/test262/blob/8ce9864511c1c83ba2d0b351da3390c9e33fd60e/harness/testIntl.js#L193 getInvalidLanguageTags()
 */
function getInvalidLanguageTags()
{
    $invalidLanguageTags = [
        '', // empty tag
        'i', // singleton alone
        'x', // private use without subtag
        'u', // extension singleton in first place
        '419', // region code in first place
        'u-nu-latn-cu-bob', // extension sequence without language
        'hans-cmn-cn', // "hans" could theoretically be a 4-letter language code,
                       // but those can't be followed by extlang codes.
        'cmn-hans-cn-u-u', // duplicate singleton
        'cmn-hans-cn-t-u-ca-u', // duplicate singleton
        'de-gregory-gregory', // duplicate variant
        '*', // language range
        'de-*', // language range
        '中文', // non-ASCII letters
        'en-ß', // non-ASCII letters
        'ıd', // non-ASCII letters
        'es-Latn-latn', // two scripts
        'pl-PL-pl', // two regions
        'u-ca-gregory', // extension in first place
        'de-1996-1996', // duplicate numeric variant
        'pt-u-ca-gregory-u-nu-latn', // duplicate singleton subtag

        // Invalid tags starting with: https://github.com/tc39/ecma402/pull/289
        'no-nyn', // regular grandfathered in BCP47, but invalid in UTS35
        'i-klingon', // irregular grandfathered in BCP47, but invalid in UTS35
        'zh-hak-CN', // language with extlang in BCP47, but invalid in UTS35
        'sgn-ils', // language with extlang in BCP47, but invalid in UTS35
        'x-foo', // privateuse-only in BCP47, but invalid in UTS35
        'x-en-US-12345', // more privateuse-only variants.
        'x-12345-12345-en-US',
        'x-en-US-12345-12345',
        'x-en-u-foo',
        'x-en-u-foo-u-bar',
        'x-u-foo',

        // underscores in different parts of the language tag
        'de_DE',
        'DE_de',
        'cmn_Hans',
        'cmn-hans_cn',
        'es_419',
        'es-419-u-nu-latn-cu_bob',
        'i_klingon',
        'cmn-hans-cn-t-ca-u-ca-x_t-u',
        'enochian_enochian',
        'de-gregory_u-ca-gregory',

        // "en\0", // null-terminator sequence
        ' en', // leading whitespace
        'en ', // trailing whitespace
        'it-IT-Latn', // country before script tag
        'de-u', // incomplete Unicode extension sequences
        'de-u-',
        'de-u-ca-',
        'de-u-ca-gregory-',
        'si-x', // incomplete private-use tags
        'x-',
        'x-y-',
    ];

    // make sure the data above is correct
    foreach ($invalidLanguageTags as $invalidTag) {
        assert(
            !isCanonicalizedStructurallyValidLanguageTag($invalidTag),
            "Test data \"$invalidTag\" is a canonicalized and structurally valid language tag.",
        );
    }

    return $invalidLanguageTags;
}

/**
 * Tests whether locale is a String value representing a structurally valid and
 * canonicalized BCP 47 language tag, as defined in sections 6.2.2 and 6.2.3 of
 * the ECMAScript Internationalization API Specification.
 *
 * @link https://github.com/tc39/test262/blob/aecd10eec8bbc95a88bf9bd96a96ed8774c8eaf9/harness/testIntl.js#L1597 isCanonicalizedStructurallyValidLanguageTag()
 */
function isCanonicalizedStructurallyValidLanguageTag(string $locale): bool
{
    /**
     * Regular expression defining Unicode BCP 47 Locale Identifiers.
     *
     * Spec: https://unicode.org/reports/tr35/#Unicode_locale_identifier
     */
    $alpha = '[a-z]';
    $digit = '[0-9]';
    $alphanum = '[a-z0-9]';
    $variant = '(' . $alphanum . '{5,8}|(?:' . $digit . $alphanum . '{3}))';
    $region = '(' . $alpha . '{2}|' . $digit . '{3})';
    $script = '(' . $alpha . '{4})';
    $language = '(' . $alpha . '{2,3}|' . $alpha . '{5,8})';
    $privateuse = '(x(-[a-z0-9]{1,8})+)';
    $singleton = '(' . $digit . '|[a-wy-z])';
    $attribute = '(' . $alphanum . '{3,8})';
    $keyword = '(' . $alphanum . $alpha . '(-' . $alphanum . '{3,8})*)';
    $unicodeLocaleExtensions = '(u((-' . $keyword . ')+|((-' . $attribute . ')+(-' . $keyword . ')*)))';
    $tlang = '(' . $language . '(-' . $script . ')?(-' . $region . ')?(-' . $variant . ')*)';
    $tfield = '(' . $alpha . $digit . '(-' . $alphanum . '{3,8})+)';
    $transformedExtensions = '(t((-' . $tlang . '(-' . $tfield . ')*)|(-' . $tfield . ')+))';
    $otherSingleton = '(' . $digit . '|[a-sv-wy-z])';
    $otherExtensions = '(' . $otherSingleton . '(-' . $alphanum . '{2,8})+)';
    $extension = '(' . $unicodeLocaleExtensions . '|' . $transformedExtensions . '|' . $otherExtensions . ')';
    $localeId = $language . '(-' . $script . ')?(-' . $region . ')?(-' . $variant . ')*(-' . $extension . ')*(-' . $privateuse . ')?';
    $languageTag = '^(' . $localeId . ')$';
    $languageTagRE = '/' . $languageTag . '/i';

    $duplicateSingleton = '-' . $singleton . "-(.*-)?\\1(?!" . $alphanum . ')';
    $duplicateSingletonRE = '/' . $duplicateSingleton . '/i';
    $duplicateVariant = '(' . $alphanum . '{2,8}-)+' . $variant . '-(' . $alphanum . "{2,8}-)*\\2(?!" . $alphanum . ')';
    $duplicateVariantRE = '/' . $duplicateVariant . '/i';

    $transformKeyRE = '/^' . $alpha . $digit . '$/i';

    /**
     * Verifies that the given string is a well-formed Unicode BCP 47 Locale Identifier
     * with no duplicate variant or singleton subtags.
     *
     * Spec: ECMAScript Internationalization API Specification, draft, 6.2.2.
     */
    $isStructurallyValidLanguageTag = function ($locale) use (
        $languageTagRE,
        $duplicateSingletonRE,
        $duplicateVariantRE
    ): bool {
        if (!preg_match($languageTagRE, $locale)) {
            return false;
        }

        $locale = explode('-x-', $locale)[0];

        return !preg_match($duplicateSingletonRE, $locale) && !preg_match($duplicateVariantRE, $locale);
    };

    /**
     * Mappings from complete tags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $tagMappings = [
        // property names must be in lower case; values in canonical form

        'art-lojban' => 'jbo',
        'cel-gaulish' => 'xtg',
        'zh-guoyu' => 'zh',
        'zh-hakka' => 'hak',
        'zh-xiang' => 'hsn',
    ];

    /**
     * Mappings from language subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $languageMappings = [
        // property names and values must be in canonical case

        'aam' => 'aas',
        'aar' => 'aa',
        'abk' => 'ab',
        'adp' => 'dz',
        'afr' => 'af',
        'aju' => 'jrb',
        'aka' => 'ak',
        'alb' => 'sq',
        'als' => 'sq',
        'amh' => 'am',
        'ara' => 'ar',
        'arb' => 'ar',
        'arg' => 'an',
        'arm' => 'hy',
        'asd' => 'snz',
        'asm' => 'as',
        'aue' => 'ktz',
        'ava' => 'av',
        'ave' => 'ae',
        'aym' => 'ay',
        'ayr' => 'ay',
        'ayx' => 'nun',
        'aze' => 'az',
        'azj' => 'az',
        'bak' => 'ba',
        'bam' => 'bm',
        'baq' => 'eu',
        'bcc' => 'bal',
        'bcl' => 'bik',
        'bel' => 'be',
        'ben' => 'bn',
        'bgm' => 'bcg',
        'bh' => 'bho',
        'bih' => 'bho',
        'bis' => 'bi',
        'bjd' => 'drl',
        'bod' => 'bo',
        'bos' => 'bs',
        'bre' => 'br',
        'bul' => 'bg',
        'bur' => 'my',
        'bxk' => 'luy',
        'bxr' => 'bua',
        'cat' => 'ca',
        'ccq' => 'rki',
        'ces' => 'cs',
        'cha' => 'ch',
        'che' => 'ce',
        'chi' => 'zh',
        'chu' => 'cu',
        'chv' => 'cv',
        'cjr' => 'mom',
        'cka' => 'cmr',
        'cld' => 'syr',
        'cmk' => 'xch',
        'cmn' => 'zh',
        'cor' => 'kw',
        'cos' => 'co',
        'coy' => 'pij',
        'cqu' => 'quh',
        'cre' => 'cr',
        'cwd' => 'cr',
        'cym' => 'cy',
        'cze' => 'cs',
        'dan' => 'da',
        'deu' => 'de',
        'dgo' => 'doi',
        'dhd' => 'mwr',
        'dik' => 'din',
        'diq' => 'zza',
        'dit' => 'dif',
        'div' => 'dv',
        'drh' => 'mn',
        'dut' => 'nl',
        'dzo' => 'dz',
        'ekk' => 'et',
        'ell' => 'el',
        'emk' => 'man',
        'eng' => 'en',
        'epo' => 'eo',
        'esk' => 'ik',
        'est' => 'et',
        'eus' => 'eu',
        'ewe' => 'ee',
        'fao' => 'fo',
        'fas' => 'fa',
        'fat' => 'ak',
        'fij' => 'fj',
        'fin' => 'fi',
        'fra' => 'fr',
        'fre' => 'fr',
        'fry' => 'fy',
        'fuc' => 'ff',
        'ful' => 'ff',
        'gav' => 'dev',
        'gaz' => 'om',
        'gbo' => 'grb',
        'geo' => 'ka',
        'ger' => 'de',
        'gfx' => 'vaj',
        'ggn' => 'gvr',
        'gla' => 'gd',
        'gle' => 'ga',
        'glg' => 'gl',
        'glv' => 'gv',
        'gno' => 'gon',
        'gre' => 'el',
        'grn' => 'gn',
        'gti' => 'nyc',
        'gug' => 'gn',
        'guj' => 'gu',
        'guv' => 'duz',
        'gya' => 'gba',
        'hat' => 'ht',
        'hau' => 'ha',
        'hdn' => 'hai',
        'hea' => 'hmn',
        'heb' => 'he',
        'her' => 'hz',
        'him' => 'srx',
        'hin' => 'hi',
        'hmo' => 'ho',
        'hrr' => 'jal',
        'hrv' => 'hr',
        'hun' => 'hu',
        'hye' => 'hy',
        'ibi' => 'opa',
        'ibo' => 'ig',
        'ice' => 'is',
        'ido' => 'io',
        'iii' => 'ii',
        'ike' => 'iu',
        'iku' => 'iu',
        'ile' => 'ie',
        'ilw' => 'gal',
        'in' => 'id',
        'ina' => 'ia',
        'ind' => 'id',
        'ipk' => 'ik',
        'isl' => 'is',
        'ita' => 'it',
        'iw' => 'he',
        'jav' => 'jv',
        'jeg' => 'oyb',
        'ji' => 'yi',
        'jpn' => 'ja',
        'jw' => 'jv',
        'kal' => 'kl',
        'kan' => 'kn',
        'kas' => 'ks',
        'kat' => 'ka',
        'kau' => 'kr',
        'kaz' => 'kk',
        'kgc' => 'tdf',
        'kgh' => 'kml',
        'khk' => 'mn',
        'khm' => 'km',
        'kik' => 'ki',
        'kin' => 'rw',
        'kir' => 'ky',
        'kmr' => 'ku',
        'knc' => 'kr',
        'kng' => 'kg',
        'knn' => 'kok',
        'koj' => 'kwv',
        'kom' => 'kv',
        'kon' => 'kg',
        'kor' => 'ko',
        'kpv' => 'kv',
        'krm' => 'bmf',
        'ktr' => 'dtp',
        'kua' => 'kj',
        'kur' => 'ku',
        'kvs' => 'gdj',
        'kwq' => 'yam',
        'kxe' => 'tvd',
        'kzj' => 'dtp',
        'kzt' => 'dtp',
        'lao' => 'lo',
        'lat' => 'la',
        'lav' => 'lv',
        'lbk' => 'bnc',
        'lii' => 'raq',
        'lim' => 'li',
        'lin' => 'ln',
        'lit' => 'lt',
        'llo' => 'ngt',
        'lmm' => 'rmx',
        'ltz' => 'lb',
        'lub' => 'lu',
        'lug' => 'lg',
        'lvs' => 'lv',
        'mac' => 'mk',
        'mah' => 'mh',
        'mal' => 'ml',
        'mao' => 'mi',
        'mar' => 'mr',
        'may' => 'ms',
        'meg' => 'cir',
        'mhr' => 'chm',
        'mkd' => 'mk',
        'mlg' => 'mg',
        'mlt' => 'mt',
        'mnk' => 'man',
        'mo' => 'ro',
        'mol' => 'ro',
        'mon' => 'mn',
        'mri' => 'mi',
        'msa' => 'ms',
        'mst' => 'mry',
        'mup' => 'raj',
        'mwj' => 'vaj',
        'mya' => 'my',
        'myd' => 'aog',
        'myt' => 'mry',
        'nad' => 'xny',
        'nau' => 'na',
        'nav' => 'nv',
        'nbl' => 'nr',
        'ncp' => 'kdz',
        'nde' => 'nd',
        'ndo' => 'ng',
        'nep' => 'ne',
        'nld' => 'nl',
        'nno' => 'nn',
        'nns' => 'nbr',
        'nnx' => 'ngv',
        'no' => 'nb',
        'nob' => 'nb',
        'nor' => 'nb',
        'npi' => 'ne',
        'nts' => 'pij',
        'nya' => 'ny',
        'oci' => 'oc',
        'ojg' => 'oj',
        'oji' => 'oj',
        'ori' => 'or',
        'orm' => 'om',
        'ory' => 'or',
        'oss' => 'os',
        'oun' => 'vaj',
        'pan' => 'pa',
        'pbu' => 'ps',
        'pcr' => 'adx',
        'per' => 'fa',
        'pes' => 'fa',
        'pli' => 'pi',
        'plt' => 'mg',
        'pmc' => 'huw',
        'pmu' => 'phr',
        'pnb' => 'lah',
        'pol' => 'pl',
        'por' => 'pt',
        'ppa' => 'bfy',
        'ppr' => 'lcq',
        'pry' => 'prt',
        'pus' => 'ps',
        'puz' => 'pub',
        'que' => 'qu',
        'quz' => 'qu',
        'rmy' => 'rom',
        'roh' => 'rm',
        'ron' => 'ro',
        'rum' => 'ro',
        'run' => 'rn',
        'rus' => 'ru',
        'sag' => 'sg',
        'san' => 'sa',
        'sca' => 'hle',
        'scc' => 'sr',
        'scr' => 'hr',
        'sin' => 'si',
        'skk' => 'oyb',
        'slk' => 'sk',
        'slo' => 'sk',
        'slv' => 'sl',
        'sme' => 'se',
        'smo' => 'sm',
        'sna' => 'sn',
        'snd' => 'sd',
        'som' => 'so',
        'sot' => 'st',
        'spa' => 'es',
        'spy' => 'kln',
        'sqi' => 'sq',
        'src' => 'sc',
        'srd' => 'sc',
        'srp' => 'sr',
        'ssw' => 'ss',
        'sun' => 'su',
        'swa' => 'sw',
        'swe' => 'sv',
        'swh' => 'sw',
        'tah' => 'ty',
        'tam' => 'ta',
        'tat' => 'tt',
        'tdu' => 'dtp',
        'tel' => 'te',
        'tgk' => 'tg',
        'tgl' => 'fil',
        'tha' => 'th',
        'thc' => 'tpo',
        'thx' => 'oyb',
        'tib' => 'bo',
        'tie' => 'ras',
        'tir' => 'ti',
        'tkk' => 'twm',
        'tl' => 'fil',
        'tlw' => 'weo',
        'tmp' => 'tyj',
        'tne' => 'kak',
        'ton' => 'to',
        'tsf' => 'taj',
        'tsn' => 'tn',
        'tso' => 'ts',
        'ttq' => 'tmh',
        'tuk' => 'tk',
        'tur' => 'tr',
        'tw' => 'ak',
        'twi' => 'ak',
        'uig' => 'ug',
        'ukr' => 'uk',
        'umu' => 'del',
        'uok' => 'ema',
        'urd' => 'ur',
        'uzb' => 'uz',
        'uzn' => 'uz',
        'ven' => 've',
        'vie' => 'vi',
        'vol' => 'vo',
        'wel' => 'cy',
        'wln' => 'wa',
        'wol' => 'wo',
        'xba' => 'cax',
        'xho' => 'xh',
        'xia' => 'acn',
        'xkh' => 'waw',
        'xpe' => 'kpe',
        'xsj' => 'suj',
        'xsl' => 'den',
        'ybd' => 'rki',
        'ydd' => 'yi',
        'yid' => 'yi',
        'yma' => 'lrr',
        'ymt' => 'mtm',
        'yor' => 'yo',
        'yos' => 'zom',
        'yuu' => 'yug',
        'zai' => 'zap',
        'zha' => 'za',
        'zho' => 'zh',
        'zsm' => 'ms',
        'zul' => 'zu',
        'zyb' => 'za',
    ];

    /**
     * Mappings from region subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $regionMappings = [
        // property names and values must be in canonical case

        '004' => 'AF',
        '008' => 'AL',
        '010' => 'AQ',
        '012' => 'DZ',
        '016' => 'AS',
        '020' => 'AD',
        '024' => 'AO',
        '028' => 'AG',
        '031' => 'AZ',
        '032' => 'AR',
        '036' => 'AU',
        '040' => 'AT',
        '044' => 'BS',
        '048' => 'BH',
        '050' => 'BD',
        '051' => 'AM',
        '052' => 'BB',
        '056' => 'BE',
        '060' => 'BM',
        '062' => '034',
        '064' => 'BT',
        '068' => 'BO',
        '070' => 'BA',
        '072' => 'BW',
        '074' => 'BV',
        '076' => 'BR',
        '084' => 'BZ',
        '086' => 'IO',
        '090' => 'SB',
        '092' => 'VG',
        '096' => 'BN',
        '100' => 'BG',
        '104' => 'MM',
        '108' => 'BI',
        '112' => 'BY',
        '116' => 'KH',
        '120' => 'CM',
        '124' => 'CA',
        '132' => 'CV',
        '136' => 'KY',
        '140' => 'CF',
        '144' => 'LK',
        '148' => 'TD',
        '152' => 'CL',
        '156' => 'CN',
        '158' => 'TW',
        '162' => 'CX',
        '166' => 'CC',
        '170' => 'CO',
        '174' => 'KM',
        '175' => 'YT',
        '178' => 'CG',
        '180' => 'CD',
        '184' => 'CK',
        '188' => 'CR',
        '191' => 'HR',
        '192' => 'CU',
        '196' => 'CY',
        '203' => 'CZ',
        '204' => 'BJ',
        '208' => 'DK',
        '212' => 'DM',
        '214' => 'DO',
        '218' => 'EC',
        '222' => 'SV',
        '226' => 'GQ',
        '230' => 'ET',
        '231' => 'ET',
        '232' => 'ER',
        '233' => 'EE',
        '234' => 'FO',
        '238' => 'FK',
        '239' => 'GS',
        '242' => 'FJ',
        '246' => 'FI',
        '248' => 'AX',
        '249' => 'FR',
        '250' => 'FR',
        '254' => 'GF',
        '258' => 'PF',
        '260' => 'TF',
        '262' => 'DJ',
        '266' => 'GA',
        '268' => 'GE',
        '270' => 'GM',
        '275' => 'PS',
        '276' => 'DE',
        '278' => 'DE',
        '280' => 'DE',
        '288' => 'GH',
        '292' => 'GI',
        '296' => 'KI',
        '300' => 'GR',
        '304' => 'GL',
        '308' => 'GD',
        '312' => 'GP',
        '316' => 'GU',
        '320' => 'GT',
        '324' => 'GN',
        '328' => 'GY',
        '332' => 'HT',
        '334' => 'HM',
        '336' => 'VA',
        '340' => 'HN',
        '344' => 'HK',
        '348' => 'HU',
        '352' => 'IS',
        '356' => 'IN',
        '360' => 'ID',
        '364' => 'IR',
        '368' => 'IQ',
        '372' => 'IE',
        '376' => 'IL',
        '380' => 'IT',
        '384' => 'CI',
        '388' => 'JM',
        '392' => 'JP',
        '398' => 'KZ',
        '400' => 'JO',
        '404' => 'KE',
        '408' => 'KP',
        '410' => 'KR',
        '414' => 'KW',
        '417' => 'KG',
        '418' => 'LA',
        '422' => 'LB',
        '426' => 'LS',
        '428' => 'LV',
        '430' => 'LR',
        '434' => 'LY',
        '438' => 'LI',
        '440' => 'LT',
        '442' => 'LU',
        '446' => 'MO',
        '450' => 'MG',
        '454' => 'MW',
        '458' => 'MY',
        '462' => 'MV',
        '466' => 'ML',
        '470' => 'MT',
        '474' => 'MQ',
        '478' => 'MR',
        '480' => 'MU',
        '484' => 'MX',
        '492' => 'MC',
        '496' => 'MN',
        '498' => 'MD',
        '499' => 'ME',
        '500' => 'MS',
        '504' => 'MA',
        '508' => 'MZ',
        '512' => 'OM',
        '516' => 'NA',
        '520' => 'NR',
        '524' => 'NP',
        '528' => 'NL',
        '531' => 'CW',
        '533' => 'AW',
        '534' => 'SX',
        '535' => 'BQ',
        '540' => 'NC',
        '548' => 'VU',
        '554' => 'NZ',
        '558' => 'NI',
        '562' => 'NE',
        '566' => 'NG',
        '570' => 'NU',
        '574' => 'NF',
        '578' => 'NO',
        '580' => 'MP',
        '581' => 'UM',
        '583' => 'FM',
        '584' => 'MH',
        '585' => 'PW',
        '586' => 'PK',
        '591' => 'PA',
        '598' => 'PG',
        '600' => 'PY',
        '604' => 'PE',
        '608' => 'PH',
        '612' => 'PN',
        '616' => 'PL',
        '620' => 'PT',
        '624' => 'GW',
        '626' => 'TL',
        '630' => 'PR',
        '634' => 'QA',
        '638' => 'RE',
        '642' => 'RO',
        '643' => 'RU',
        '646' => 'RW',
        '652' => 'BL',
        '654' => 'SH',
        '659' => 'KN',
        '660' => 'AI',
        '662' => 'LC',
        '663' => 'MF',
        '666' => 'PM',
        '670' => 'VC',
        '674' => 'SM',
        '678' => 'ST',
        '682' => 'SA',
        '686' => 'SN',
        '688' => 'RS',
        '690' => 'SC',
        '694' => 'SL',
        '702' => 'SG',
        '703' => 'SK',
        '704' => 'VN',
        '705' => 'SI',
        '706' => 'SO',
        '710' => 'ZA',
        '716' => 'ZW',
        '720' => 'YE',
        '724' => 'ES',
        '728' => 'SS',
        '729' => 'SD',
        '732' => 'EH',
        '736' => 'SD',
        '740' => 'SR',
        '744' => 'SJ',
        '748' => 'SZ',
        '752' => 'SE',
        '756' => 'CH',
        '760' => 'SY',
        '762' => 'TJ',
        '764' => 'TH',
        '768' => 'TG',
        '772' => 'TK',
        '776' => 'TO',
        '780' => 'TT',
        '784' => 'AE',
        '788' => 'TN',
        '792' => 'TR',
        '795' => 'TM',
        '796' => 'TC',
        '798' => 'TV',
        '800' => 'UG',
        '804' => 'UA',
        '807' => 'MK',
        '818' => 'EG',
        '826' => 'GB',
        '830' => 'JE',
        '831' => 'GG',
        '832' => 'JE',
        '833' => 'IM',
        '834' => 'TZ',
        '840' => 'US',
        '850' => 'VI',
        '854' => 'BF',
        '858' => 'UY',
        '860' => 'UZ',
        '862' => 'VE',
        '876' => 'WF',
        '882' => 'WS',
        '886' => 'YE',
        '887' => 'YE',
        '891' => 'RS',
        '894' => 'ZM',
        '958' => 'AA',
        '959' => 'QM',
        '960' => 'QN',
        '962' => 'QP',
        '963' => 'QQ',
        '964' => 'QR',
        '965' => 'QS',
        '966' => 'QT',
        '967' => 'EU',
        '968' => 'QV',
        '969' => 'QW',
        '970' => 'QX',
        '971' => 'QY',
        '972' => 'QZ',
        '973' => 'XA',
        '974' => 'XB',
        '975' => 'XC',
        '976' => 'XD',
        '977' => 'XE',
        '978' => 'XF',
        '979' => 'XG',
        '980' => 'XH',
        '981' => 'XI',
        '982' => 'XJ',
        '983' => 'XK',
        '984' => 'XL',
        '985' => 'XM',
        '986' => 'XN',
        '987' => 'XO',
        '988' => 'XP',
        '989' => 'XQ',
        '990' => 'XR',
        '991' => 'XS',
        '992' => 'XT',
        '993' => 'XU',
        '994' => 'XV',
        '995' => 'XW',
        '996' => 'XX',
        '997' => 'XY',
        '998' => 'XZ',
        '999' => 'ZZ',
        'BU' => 'MM',
        'CS' => 'RS',
        'CT' => 'KI',
        'DD' => 'DE',
        'DY' => 'BJ',
        'FQ' => 'AQ',
        'FX' => 'FR',
        'HV' => 'BF',
        'JT' => 'UM',
        'MI' => 'UM',
        'NH' => 'VU',
        'NQ' => 'AQ',
        'PU' => 'UM',
        'PZ' => 'PA',
        'QU' => 'EU',
        'RH' => 'ZW',
        'TP' => 'TL',
        'UK' => 'GB',
        'VD' => 'VN',
        'WK' => 'UM',
        'YD' => 'YE',
        'YU' => 'RS',
        'ZR' => 'CD',
    ];

    /**
     * Complex mappings from language subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $complexLanguageMappings = [
        // property names and values must be in canonical case

        'cnr' => ['language' => 'sr', 'region' => 'ME'],
        'drw' => ['language' => 'fa', 'region' => 'AF'],
        'hbs' => ['language' => 'sr', 'script' => 'Latn'],
        'prs' => ['language' => 'fa', 'region' => 'AF'],
        'sh' => ['language' => 'sr', 'script' => 'Latn'],
        'swc' => ['language' => 'sw', 'region' => 'CD'],
        'tnf' => ['language' => 'fa', 'region' => 'AF'],
    ];

    /**
     * Complex mappings from region subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $complexRegionMappings = [
        // property names and values must be in canonical case

        '172' => [
            'default' => 'RU',
            'ab' => 'GE',
            'az' => 'AZ',
            'be' => 'BY',
            'crh' => 'UA',
            'gag' => 'MD',
            'got' => 'UA',
            'hy' => 'AM',
            'ji' => 'UA',
            'ka' => 'GE',
            'kaa' => 'UZ',
            'kk' => 'KZ',
            'ku-Yezi' => 'GE',
            'ky' => 'KG',
            'os' => 'GE',
            'rue' => 'UA',
            'sog' => 'UZ',
            'tg' => 'TJ',
            'tk' => 'TM',
            'tkr' => 'AZ',
            'tly' => 'AZ',
            'ttt' => 'AZ',
            'ug-Cyrl' => 'KZ',
            'uk' => 'UA',
            'und-Armn' => 'AM',
            'und-Chrs' => 'UZ',
            'und-Geor' => 'GE',
            'und-Goth' => 'UA',
            'und-Sogd' => 'UZ',
            'und-Sogo' => 'UZ',
            'und-Yezi' => 'GE',
            'uz' => 'UZ',
            'xco' => 'UZ',
            'xmf' => 'GE',
        ],
        '200' => [
            'default' => 'CZ',
            'sk' => 'SK',
        ],
        '530' => [
            'default' => 'CW',
            'vic' => 'SX',
        ],
        '532' => [
            'default' => 'CW',
            'vic' => 'SX',
        ],
        '536' => [
            'default' => 'SA',
            'akk' => 'IQ',
            'ckb' => 'IQ',
            'ku-Arab' => 'IQ',
            'mis' => 'IQ',
            'syr' => 'IQ',
            'und-Hatr' => 'IQ',
            'und-Syrc' => 'IQ',
            'und-Xsux' => 'IQ',
        ],
        '582' => [
            'default' => 'FM',
            'mh' => 'MH',
            'pau' => 'PW',
        ],
        '810' => [
            'default' => 'RU',
            'ab' => 'GE',
            'az' => 'AZ',
            'be' => 'BY',
            'crh' => 'UA',
            'et' => 'EE',
            'gag' => 'MD',
            'got' => 'UA',
            'hy' => 'AM',
            'ji' => 'UA',
            'ka' => 'GE',
            'kaa' => 'UZ',
            'kk' => 'KZ',
            'ku-Yezi' => 'GE',
            'ky' => 'KG',
            'lt' => 'LT',
            'ltg' => 'LV',
            'lv' => 'LV',
            'os' => 'GE',
            'rue' => 'UA',
            'sgs' => 'LT',
            'sog' => 'UZ',
            'tg' => 'TJ',
            'tk' => 'TM',
            'tkr' => 'AZ',
            'tly' => 'AZ',
            'ttt' => 'AZ',
            'ug-Cyrl' => 'KZ',
            'uk' => 'UA',
            'und-Armn' => 'AM',
            'und-Chrs' => 'UZ',
            'und-Geor' => 'GE',
            'und-Goth' => 'UA',
            'und-Sogd' => 'UZ',
            'und-Sogo' => 'UZ',
            'und-Yezi' => 'GE',
            'uz' => 'UZ',
            'vro' => 'EE',
            'xco' => 'UZ',
            'xmf' => 'GE',
        ],
        '890' => [
            'default' => 'RS',
            'bs' => 'BA',
            'hr' => 'HR',
            'mk' => 'MK',
            'sl' => 'SI',
        ],
        'AN' => [
            'default' => 'CW',
            'vic' => 'SX',
        ],
        'NT' => [
            'default' => 'SA',
            'akk' => 'IQ',
            'ckb' => 'IQ',
            'ku-Arab' => 'IQ',
            'mis' => 'IQ',
            'syr' => 'IQ',
            'und-Hatr' => 'IQ',
            'und-Syrc' => 'IQ',
            'und-Xsux' => 'IQ',
        ],
        'PC' => [
            'default' => 'FM',
            'mh' => 'MH',
            'pau' => 'PW',
        ],
        'SU' => [
            'default' => 'RU',
            'ab' => 'GE',
            'az' => 'AZ',
            'be' => 'BY',
            'crh' => 'UA',
            'et' => 'EE',
            'gag' => 'MD',
            'got' => 'UA',
            'hy' => 'AM',
            'ji' => 'UA',
            'ka' => 'GE',
            'kaa' => 'UZ',
            'kk' => 'KZ',
            'ku-Yezi' => 'GE',
            'ky' => 'KG',
            'lt' => 'LT',
            'ltg' => 'LV',
            'lv' => 'LV',
            'os' => 'GE',
            'rue' => 'UA',
            'sgs' => 'LT',
            'sog' => 'UZ',
            'tg' => 'TJ',
            'tk' => 'TM',
            'tkr' => 'AZ',
            'tly' => 'AZ',
            'ttt' => 'AZ',
            'ug-Cyrl' => 'KZ',
            'uk' => 'UA',
            'und-Armn' => 'AM',
            'und-Chrs' => 'UZ',
            'und-Geor' => 'GE',
            'und-Goth' => 'UA',
            'und-Sogd' => 'UZ',
            'und-Sogo' => 'UZ',
            'und-Yezi' => 'GE',
            'uz' => 'UZ',
            'vro' => 'EE',
            'xco' => 'UZ',
            'xmf' => 'GE',
        ],
    ];

    /**
     * Mappings from variant subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $variantMappings = [
        // property names and values must be in canonical case

        'aaland' => ['type' => 'region', 'replacement' => 'AX'],
        'arevela' => ['type' => 'language', 'replacement' => 'hy'],
        'arevmda' => ['type' => 'language', 'replacement' => 'hyw'],
        'heploc' => ['type' => 'variant', 'replacement' => 'alalc97'],
        'polytoni' => ['type' => 'variant', 'replacement' => 'polyton'],
    ];

    /**
     * Mappings from Unicode extension subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $unicodeMappings = [
        // property names and values must be in canonical case

        'ca' => [
            'ethiopic-amete-alem' => 'ethioaa',
            'islamicc' => 'islamic-civil',
        ],
        'kb' => [
            'yes' => 'true',
        ],
        'kc' => [
            'yes' => 'true',
        ],
        'kh' => [
            'yes' => 'true',
        ],
        'kk' => [
            'yes' => 'true',
        ],
        'kn' => [
            'yes' => 'true',
        ],
        'ks' => [
            'primary' => 'level1',
            'tertiary' => 'level3',
        ],
        'ms' => [
            'imperial' => 'uksystem',
        ],
        'rg' => [
            'cn11' => 'cnbj',
            'cn12' => 'cntj',
            'cn13' => 'cnhe',
            'cn14' => 'cnsx',
            'cn15' => 'cnmn',
            'cn21' => 'cnln',
            'cn22' => 'cnjl',
            'cn23' => 'cnhl',
            'cn31' => 'cnsh',
            'cn32' => 'cnjs',
            'cn33' => 'cnzj',
            'cn34' => 'cnah',
            'cn35' => 'cnfj',
            'cn36' => 'cnjx',
            'cn37' => 'cnsd',
            'cn41' => 'cnha',
            'cn42' => 'cnhb',
            'cn43' => 'cnhn',
            'cn44' => 'cngd',
            'cn45' => 'cngx',
            'cn46' => 'cnhi',
            'cn50' => 'cncq',
            'cn51' => 'cnsc',
            'cn52' => 'cngz',
            'cn53' => 'cnyn',
            'cn54' => 'cnxz',
            'cn61' => 'cnsn',
            'cn62' => 'cngs',
            'cn63' => 'cnqh',
            'cn64' => 'cnnx',
            'cn65' => 'cnxj',
            'cz10a' => 'cz110',
            'cz10b' => 'cz111',
            'cz10c' => 'cz112',
            'cz10d' => 'cz113',
            'cz10e' => 'cz114',
            'cz10f' => 'cz115',
            'cz611' => 'cz663',
            'cz612' => 'cz632',
            'cz613' => 'cz633',
            'cz614' => 'cz634',
            'cz615' => 'cz635',
            'cz621' => 'cz641',
            'cz622' => 'cz642',
            'cz623' => 'cz643',
            'cz624' => 'cz644',
            'cz626' => 'cz646',
            'cz627' => 'cz647',
            'czjc' => 'cz31',
            'czjm' => 'cz64',
            'czka' => 'cz41',
            'czkr' => 'cz52',
            'czli' => 'cz51',
            'czmo' => 'cz80',
            'czol' => 'cz71',
            'czpa' => 'cz53',
            'czpl' => 'cz32',
            'czpr' => 'cz10',
            'czst' => 'cz20',
            'czus' => 'cz42',
            'czvy' => 'cz63',
            'czzl' => 'cz72',
            'fra' => 'frges',
            'frb' => 'frnaq',
            'frc' => 'frara',
            'frd' => 'frbfc',
            'fre' => 'frbre',
            'frf' => 'frcvl',
            'frg' => 'frges',
            'frh' => 'frcor',
            'fri' => 'frbfc',
            'frj' => 'fridf',
            'frk' => 'frocc',
            'frl' => 'frnaq',
            'frm' => 'frges',
            'frn' => 'frocc',
            'fro' => 'frhdf',
            'frp' => 'frnor',
            'frq' => 'frnor',
            'frr' => 'frpdl',
            'frs' => 'frhdf',
            'frt' => 'frnaq',
            'fru' => 'frpac',
            'frv' => 'frara',
            'laxn' => 'laxs',
            'lud' => 'lucl',
            'lug' => 'luec',
            'lul' => 'luca',
            'mrnkc' => 'mr13',
            'no23' => 'no50',
            'nzn' => 'nzauk',
            'nzs' => 'nzcan',
            'omba' => 'ombj',
            'omsh' => 'omsj',
            'plds' => 'pl02',
            'plkp' => 'pl04',
            'pllb' => 'pl08',
            'plld' => 'pl10',
            'pllu' => 'pl06',
            'plma' => 'pl12',
            'plmz' => 'pl14',
            'plop' => 'pl16',
            'plpd' => 'pl20',
            'plpk' => 'pl18',
            'plpm' => 'pl22',
            'plsk' => 'pl26',
            'plsl' => 'pl24',
            'plwn' => 'pl28',
            'plwp' => 'pl30',
            'plzp' => 'pl32',
            'tteto' => 'tttob',
            'ttrcm' => 'ttmrc',
            'ttwto' => 'tttob',
            'twkhq' => 'twkhh',
            'twtnq' => 'twtnn',
            'twtpq' => 'twnwt',
            'twtxq' => 'twtxg',
        ],
        'sd' => [
            'cn11' => 'cnbj',
            'cn12' => 'cntj',
            'cn13' => 'cnhe',
            'cn14' => 'cnsx',
            'cn15' => 'cnmn',
            'cn21' => 'cnln',
            'cn22' => 'cnjl',
            'cn23' => 'cnhl',
            'cn31' => 'cnsh',
            'cn32' => 'cnjs',
            'cn33' => 'cnzj',
            'cn34' => 'cnah',
            'cn35' => 'cnfj',
            'cn36' => 'cnjx',
            'cn37' => 'cnsd',
            'cn41' => 'cnha',
            'cn42' => 'cnhb',
            'cn43' => 'cnhn',
            'cn44' => 'cngd',
            'cn45' => 'cngx',
            'cn46' => 'cnhi',
            'cn50' => 'cncq',
            'cn51' => 'cnsc',
            'cn52' => 'cngz',
            'cn53' => 'cnyn',
            'cn54' => 'cnxz',
            'cn61' => 'cnsn',
            'cn62' => 'cngs',
            'cn63' => 'cnqh',
            'cn64' => 'cnnx',
            'cn65' => 'cnxj',
            'cz10a' => 'cz110',
            'cz10b' => 'cz111',
            'cz10c' => 'cz112',
            'cz10d' => 'cz113',
            'cz10e' => 'cz114',
            'cz10f' => 'cz115',
            'cz611' => 'cz663',
            'cz612' => 'cz632',
            'cz613' => 'cz633',
            'cz614' => 'cz634',
            'cz615' => 'cz635',
            'cz621' => 'cz641',
            'cz622' => 'cz642',
            'cz623' => 'cz643',
            'cz624' => 'cz644',
            'cz626' => 'cz646',
            'cz627' => 'cz647',
            'czjc' => 'cz31',
            'czjm' => 'cz64',
            'czka' => 'cz41',
            'czkr' => 'cz52',
            'czli' => 'cz51',
            'czmo' => 'cz80',
            'czol' => 'cz71',
            'czpa' => 'cz53',
            'czpl' => 'cz32',
            'czpr' => 'cz10',
            'czst' => 'cz20',
            'czus' => 'cz42',
            'czvy' => 'cz63',
            'czzl' => 'cz72',
            'fra' => 'frges',
            'frb' => 'frnaq',
            'frc' => 'frara',
            'frd' => 'frbfc',
            'fre' => 'frbre',
            'frf' => 'frcvl',
            'frg' => 'frges',
            'frh' => 'frcor',
            'fri' => 'frbfc',
            'frj' => 'fridf',
            'frk' => 'frocc',
            'frl' => 'frnaq',
            'frm' => 'frges',
            'frn' => 'frocc',
            'fro' => 'frhdf',
            'frp' => 'frnor',
            'frq' => 'frnor',
            'frr' => 'frpdl',
            'frs' => 'frhdf',
            'frt' => 'frnaq',
            'fru' => 'frpac',
            'frv' => 'frara',
            'laxn' => 'laxs',
            'lud' => 'lucl',
            'lug' => 'luec',
            'lul' => 'luca',
            'mrnkc' => 'mr13',
            'no23' => 'no50',
            'nzn' => 'nzauk',
            'nzs' => 'nzcan',
            'omba' => 'ombj',
            'omsh' => 'omsj',
            'plds' => 'pl02',
            'plkp' => 'pl04',
            'pllb' => 'pl08',
            'plld' => 'pl10',
            'pllu' => 'pl06',
            'plma' => 'pl12',
            'plmz' => 'pl14',
            'plop' => 'pl16',
            'plpd' => 'pl20',
            'plpk' => 'pl18',
            'plpm' => 'pl22',
            'plsk' => 'pl26',
            'plsl' => 'pl24',
            'plwn' => 'pl28',
            'plwp' => 'pl30',
            'plzp' => 'pl32',
            'tteto' => 'tttob',
            'ttrcm' => 'ttmrc',
            'ttwto' => 'tttob',
            'twkhq' => 'twkhh',
            'twtnq' => 'twtnn',
            'twtpq' => 'twnwt',
            'twtxq' => 'twtxg',
        ],
        'tz' => [
            'aqams' => 'nzakl',
            'cnckg' => 'cnsha',
            'cnhrb' => 'cnsha',
            'cnkhg' => 'cnurc',
            'cuba' => 'cuhav',
            'egypt' => 'egcai',
            'eire' => 'iedub',
            'est' => 'utcw05',
            'gmt0' => 'gmt',
            'hongkong' => 'hkhkg',
            'hst' => 'utcw10',
            'iceland' => 'isrey',
            'iran' => 'irthr',
            'israel' => 'jeruslm',
            'jamaica' => 'jmkin',
            'japan' => 'jptyo',
            'libya' => 'lytip',
            'mst' => 'utcw07',
            'navajo' => 'usden',
            'poland' => 'plwaw',
            'portugal' => 'ptlis',
            'prc' => 'cnsha',
            'roc' => 'twtpe',
            'rok' => 'krsel',
            'turkey' => 'trist',
            'uct' => 'utc',
            'usnavajo' => 'usden',
            'zulu' => 'utc',
        ],
    ];

    /**
     * Mappings from Unicode extension subtags to preferred values.
     *
     * Spec: http://unicode.org/reports/tr35/#Identifiers
     * Version: CLDR, version 36.1
     */
    $transformMappings = [
        // property names and values must be in canonical case

        'd0' => [
            'name' => 'charname',
        ],
        'm0' => [
            'names' => 'prprname',
        ],
    ];

    /**
     * Canonicalizes the given well-formed BCP 47 language tag, including regularized case of subtags.
     *
     * Spec: ECMAScript Internationalization API Specification, draft, 6.2.3.
     * Spec: RFC 5646, section 4.5.
     */
    $canonicalizeLanguageTag = function (string $locale) use (
        $tagMappings,
        $languageMappings,
        $complexLanguageMappings,
        $regionMappings,
        $complexRegionMappings,
        $variantMappings,
        $unicodeMappings,
        $transformKeyRE,
        $transformMappings,
        &$canonicalizeLanguageTag,
    ): string {
        // start with lower case for easier processing, and because most subtags will need to be lower case anyway
        $locale = strtolower($locale);

        // handle mappings for complete tags
        if (isset($tagMappings[$locale])) {
            return $tagMappings[$locale];
        }

        $subtags = explode('-', $locale);
        $i = 0;

        // handle standard part: all subtags before first variant or singleton subtag
        $language = null;
        $script = null;
        $region = null;
        while ($i < count($subtags)) {
            $subtag = $subtags[$i];
            if ($i === 0) {
                $language = $subtag;
            } elseif (strlen($subtag) === 2 || strlen($subtag) === 3) {
                $region = strtoupper($subtag);
            } elseif (strlen($subtag) === 4 && !('0' <= $subtag[0] && $subtag[0] <= '9')) {
                $script = strtoupper($subtag[0]) . strtolower(substr($subtag, 1));
            } else {
                break;
            }
            $i++;
        }

        if (isset($languageMappings[$language])) {
            $language = $languageMappings[$language];
        } elseif (isset($complexLanguageMappings[$language])) {
            $mapping = $complexLanguageMappings[$language];

            $language = $mapping['language'];
            if ($script === null && isset($mapping['script'])) {
                $script = $mapping['script'];
            }
            if ($region === null && isset($mapping['region'])) {
                $region = $mapping['region'];
            }
        }

        if ($region !== null) {
            if (isset($regionMappings[$region])) {
                $region = $regionMappings[$region];
            } elseif (isset($complexRegionMappings[$region])) {
                $mapping = $complexRegionMappings[$region];

                $mappingKey = $language;
                if ($script !== null) {
                    $mappingKey .= '-' . $script;
                }

                $region = $mapping[$mappingKey] ?? $mapping['default'];
            }
        }

        // handle variants
        $variants = [];
        while ($i < count($subtags) && strlen($subtags[$i]) > 1) {
            $variant = $subtags[$i];

            if (isset($variantMappings[$variant])) {
                $mapping = $variantMappings[$variant];
                switch ($mapping['type']) {
                    case 'language':
                        $language = $mapping['replacement'];

                        break;
                    case 'region':
                        $region = $mapping['replacement'];

                        break;
                    case 'variant':
                        $variants[] = $mapping['replacement'];

                        break;
                    default:
                        throw new RuntimeException('illegal variant mapping type');
                }
            } else {
                $variants[] = $variant;
            }

            $i += 1;
        }
        sort($variants);

        // handle extensions
        $extensions = [];
        while ($i < count($subtags) && $subtags[$i] !== 'x') {
            $extensionStart = $i;
            $i++;
            while ($i < count($subtags) && strlen($subtags[$i]) > 1) {
                $i++;
            }

            $extension = null;
            $extensionKey = $subtags[$extensionStart];
            if ($extensionKey === 'u') {
                $j = $extensionStart + 1;

                // skip over leading attributes
                while ($j < $i && strlen($subtags[$j]) > 2) {
                    $j++;
                }

                $extension = implode('-', array_slice($subtags, $extensionStart, ($j - $extensionStart)));

                while ($j < $i) {
                    $keyStart = $j;
                    $j++;

                    while ($j < $i && strlen($subtags[$j]) > 2) {
                        $j++;
                    }

                    $key = $subtags[$keyStart];
                    $value = implode('-', array_slice($subtags, $keyStart + 1, ($j - $keyStart - 1)));

                    if (isset($unicodeMappings[$key])) {
                        $mapping = $unicodeMappings[$key];
                        if (isset($mapping[$value])) {
                            $value = $mapping[$value];
                        }
                    }

                    $extension .= '-' . $key;
                    if ($value !== '' && $value !== 'true') {
                        $extension .= '-' . $value;
                    }
                }
            } elseif ($extensionKey === 't') {
                $j = $extensionStart + 1;

                while ($j < $i && !preg_match($transformKeyRE, $subtags[$j])) {
                    $j++;
                }

                $extension = 't';

                $transformLanguage = implode('-', array_slice($subtags, $extensionStart + 1, ($j - $extensionStart - 1)));
                if ($transformLanguage !== '') {
                    $extension .= '-' . strtolower($canonicalizeLanguageTag($transformLanguage));
                }

                while ($j < $i) {
                    $keyStart = $j;
                    $j++;

                    while ($j < $i && strlen($subtags[$j]) > 2) {
                        $j++;
                    }

                    $key = $subtags[$keyStart];
                    $value = implode('-', array_slice($subtags, $keyStart + 1, ($j - $keyStart - 1)));

                    if (isset($transformMappings[$key])) {
                        $mapping = $transformMappings[$key];
                        if (isset($mapping[$value])) {
                            $value = $mapping[$value];
                        }
                    }

                    $extension .= '-' . $key . '-' . $value;
                }
            } else {
                $extension = implode('-', array_slice($subtags, $extensionStart, ($i - $extensionStart)));
            }

            $extensions[] = $extension;
        }
        sort($extensions);

        // handle private use
        $privateUse = null;
        if ($i < count($subtags)) {
            $privateUse = implode('-', array_slice($subtags, $i));
        }

        // put everything back together
        $canonical = $language;
        if ($script !== null) {
            $canonical .= '-' . $script;
        }
        if ($region !== null) {
            $canonical .= '-' . $region;
        }
        if (count($variants) > 0) {
            $canonical .= '-' . implode('-', $variants);
        }
        if (count($extensions) > 0) {
            $canonical .= '-' . implode('-', $extensions);
        }
        if ($privateUse !== null) {
            if (strlen($canonical) > 0) {
                $canonical .= '-' . $privateUse;
            } else {
                $canonical = $privateUse;
            }
        }

        return $canonical;
    };

    return $isStructurallyValidLanguageTag($locale) && $canonicalizeLanguageTag($locale) === $locale;
}
