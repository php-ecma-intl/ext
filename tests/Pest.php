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
