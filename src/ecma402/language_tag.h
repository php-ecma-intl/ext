/*
   +----------------------------------------------------------------------+
   | ecma_intl extension for PHP                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Ben Ramsey <ben@benramsey.com>                         |
   | This source file is subject to the MIT license that is bundled with  |
   | this package in the file LICENSE, and is available at the following  |
   | web address: https://opensource.org/license/mit/                     |
   +----------------------------------------------------------------------+
*/

#ifndef ECMA_INTL_ECMA402_LANGUAGE_TAG_H
#define ECMA_INTL_ECMA402_LANGUAGE_TAG_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

/**
 * Returns true if tag is a structurally valid language tag, according to
 * ECMA-402.
 *
 * @link https://tc39.es/ecma402/#sec-isstructurallyvalidlanguagetag
 */
bool ecma402_isStructurallyValidLanguageTag(const char *tag);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace ecma402 {

/**
 * Returns true if the string is a valid Unicode language subtag.
 *
 * <pre><code>
 * unicode_language_subtag = alpha{2,3} | alpha{5,8} ;
 * </code></pre>
 */
bool isUnicodeLanguageSubtag(const std::string &string);

/**
 * Returns true if the string is a valid Unicode region subtag.
 *
 * <pre><code>
 * unicode_region_subtag = (alpha{2} | digit{3}) ;
 * </code></pre>
 */
bool isUnicodeRegionSubtag(const std::string &string);

/**
 * Returns true if the string is a valid Unicode script subtag.
 *
 * <pre><code>
 * unicode_script_subtag = alpha{4} ;
 * </code></pre>
 */
bool isUnicodeScriptSubtag(const std::string &string);

/**
 * Returns true if the string is a valid Unicode variant subtag.
 *
 * <pre><code>
 * unicode_variant_subtag = (alphanum{5,8} | digit alphanum{3}) ;
 * </code></pre>
 */
bool isUnicodeVariantSubtag(const std::string &string);

/**
 * A parser to check validity of language tags.
 *
 * <pre><code>
 * (* TR35 defines sep as [-_] but ECMA-402 uses only the hyphen. *)
 * sep = "-" ;
 * digit = [0-9] ;
 * alpha = [A-Z a-z] ;
 * alphanum = [0-9 A-Z a-z] ;
 * </code></pre>
 */
class LanguageTagParser {
public:
  LanguageTagParser(const std::string &tag);

  /**
   * Returns true if the parser has reached the end of the string.
   */
  bool isEos();

  /**
   * Advances the parser and returns true if it encounters another tag segment.
   */
  bool next();

  /**
   * Parses the language tag, returning true if it is a valid Unicode language
   * ID.
   *
   * <pre><code>
   * (* TR35 defines unicode_language_id as optionally being "root", a special
   *    unicode_language_subtag. It also allows for starting with a
   *    unicode_script_subtag, but this is not supported in ECMA-402, so this
   *    EBNF is slightly different from TR35. *)
   * unicode_language_id = unicode_language_subtag
   *                       (sep unicode_script_subtag)?
   *                       (sep unicode_region_subtag)?
   *                       (sep unicode_variant_subtag)* ;
   * </code></pre>
   */
  bool parseUnicodeLanguageId();

  /**
   * Parses the language tag, returning true if it is a valid Unicode locale ID.
   *
   * <pre><code>
   * unicode_locale_id = unicode_language_id
   *                     extensions*
   *                     pu_extensions? ;
   * </code></pre>
   */
  bool parseUnicodeLocaleId();

private:
  /**
   * <pre><code>
   * extensions = unicode_locale_extensions
   *            | transformed_extensions
   *            | other_extensions ;
   * </code></pre>
   */
  bool parseExtensionsAndPUExtensions();

  /**
   * <pre><code>
   * unicode_locale_extensions = sep [uU] ((sep keyword)+
   *                             | (sep attribute)+ (sep keyword)*) ;
   *
   * keyword = key (sep type)? ;
   * key = alphanum alpha ;
   * type = alphanum{3,8} (sep alphanum{3,8})* ;
   * attribute = alphanum{3,8} ;
   * </code></pre>
   */
  bool parseUnicodeExtensionAfterPrefix();

  /**
   * <pre><code>
   * transformed_extensions = sep [tT]
   *                          ((sep tlang (sep tfield)*) | (sep tfield)+) ;
   *
   * tlang = unicode_language_id
   * tfield = tkey tvalue;
   * tkey = alpha digit ;
   * tvalue = (sep alphanum{3,8})+ ;
   * </code></pre>
   */
  bool parseTransformedExtensionAfterPrefix();

  /**
   * <pre><code>
   * other_extensions = sep [alphanum-[tTuUxX]] (sep alphanum{2,8})+ ;
   * </code></pre>
   */
  bool parseOtherExtensionAfterPrefix();

  /**
   * <pre><code>
   * pu_extensions = sep [xX] (sep alphanum{1,8})+ ;
   * </code></pre>
   */
  bool parsePUExtensionAfterPrefix();

  std::string currentPart;
  std::vector<std::string>::iterator partsCursor;
  std::string tag;
  std::vector<std::string> tagParts;
};

} // namespace ecma402

#endif

#endif /* ECMA_INTL_ECMA402_LANGUAGE_TAG_H */
