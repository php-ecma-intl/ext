#include "../test.h"

#include "src/ecma402/language_tag.h"

#define TEST_SUITE ecma402LanguageTag

// NOLINTBEGIN(cert-err58-cpp, misc-const-correctness,
//             misc-use-anonymous-namespace)

using string = std::basic_string<char, std::char_traits<char>, criterion::allocator<char>>;

ParameterizedTestParameters(TEST_SUITE, isStructurallyValidLanguageTagReturnsTrue)
{
	static criterion::parameters<string> tests;

	// Tags with variants that should return true
	tests.emplace_back("aa-SAAHO");
	tests.emplace_back("de-DE-POSIX");
	tests.emplace_back("el-POLYTONI");
	tests.emplace_back("en-GB-POSIX");
	tests.emplace_back("en-POSIX");
	tests.emplace_back("en-US-POSIX");
	tests.emplace_back("en-US-POSIX-u-kn-true");
	tests.emplace_back("en-US-POSIX-u-kn-va-posix");
	tests.emplace_back("no-BOKMAL");
	tests.emplace_back("no-NYNORSK");
	tests.emplace_back("ru-POSIX");
	tests.emplace_back("sv-AALAND");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isStructurallyValidLanguageTagReturnsTrue)
{
	cr_expect(eq(i8, ecma402_isStructurallyValidLanguageTag((*test).c_str()), 1),
	          "Expected \"%s\" to be structurally valid language tag, but it is invalid", (*test).c_str());
}

ParameterizedTestParameters(TEST_SUITE, isStructurallyValidLanguageTagReturnsFalse)
{
	static criterion::parameters<string> tests;

	// Invalid language tags taken from Test262
	// https://github.com/tc39/test262/blob/20e442011cbfca6c8ceb468da99894b9f17df65b/harness/testIntl.js#L193C36-L193C36

	tests.emplace_back("");                 // empty tag
	tests.emplace_back("i");                // singleton alone
	tests.emplace_back("x");                // private use without subtag
	tests.emplace_back("u");                // extension singleton in first place
	tests.emplace_back("419");              // region code in first place
	tests.emplace_back("u-nu-latn-cu-bob"); // extension sequence without language
	// "hans" could theoretically be a 4-letter language code, but those can't be
	// followed by extlang codes.
	tests.emplace_back("hans-cmn-cn");
	tests.emplace_back("cmn-hans-cn-u-u");           // duplicate singleton
	tests.emplace_back("cmn-hans-cn-t-u-ca-u");      // duplicate singleton
	tests.emplace_back("de-gregory-gregory");        // duplicate variant
	tests.emplace_back("*");                         // language range
	tests.emplace_back("de-*");                      // language range
	tests.emplace_back("中文");                      // non-ASCII letters
	tests.emplace_back("en-ß");                      // non-ASCII letters
	tests.emplace_back("ıd");                        // non-ASCII letters
	tests.emplace_back("es-Latn-latn");              // two scripts
	tests.emplace_back("pl-PL-pl");                  // two regions
	tests.emplace_back("u-ca-gregory");              // extension in first place
	tests.emplace_back("de-1996-1996");              // duplicate numeric variant
	tests.emplace_back("pt-u-ca-gregory-u-nu-latn"); // duplicate singleton subtag

	// Invalid tags starting with: https://github.com/tc39/ecma402/pull/289

	// regular grandfathered in BCP47, but invalid in UTS35
	tests.emplace_back("no-nyn");
	// irregular grandfathered in BCP47, but invalid in UTS35
	tests.emplace_back("i-klingon");
	// language with extlang in BCP47, but invalid in UTS35
	tests.emplace_back("zh-hak-CN");
	// language with extlang in BCP47, but invalid in UTS35
	tests.emplace_back("sgn-ils");

	tests.emplace_back("x-foo");         // privateuse-only in BCP47, but invalid in UTS35
	tests.emplace_back("x-en-US-12345"); // more privateuse-only variants.
	tests.emplace_back("x-12345-12345-en-US");
	tests.emplace_back("x-en-US-12345-12345");
	tests.emplace_back("x-en-u-foo");
	tests.emplace_back("x-en-u-foo-u-bar");
	tests.emplace_back("x-u-foo");

	// underscores in different parts of the language tag
	tests.emplace_back("de_DE");
	tests.emplace_back("DE_de");
	tests.emplace_back("cmn_Hans");
	tests.emplace_back("cmn-hans_cn");
	tests.emplace_back("es_419");
	tests.emplace_back("es-419-u-nu-latn-cu_bob");
	tests.emplace_back("i_klingon");
	tests.emplace_back("cmn-hans-cn-t-ca-u-ca-x_t-u");
	tests.emplace_back("enochian_enochian");
	tests.emplace_back("de-gregory_u-ca-gregory");

	tests.emplace_back(" en");        // leading whitespace
	tests.emplace_back("en ");        // trailing whitespace
	tests.emplace_back("it-IT-Latn"); // country before script tag
	tests.emplace_back("de-u");       // incomplete Unicode extension sequences
	tests.emplace_back("de-u-");
	tests.emplace_back("de-u-ca-");
	tests.emplace_back("de-u-ca-gregory-");
	tests.emplace_back("si-x"); // incomplete private-use tags
	tests.emplace_back("x-");
	tests.emplace_back("x-y-");

	tests.emplace_back("ab-");
	tests.emplace_back("ab-abcde-fghij-");
	tests.emplace_back("-ab");
	tests.emplace_back("de-*");
	tests.emplace_back("de-abcde-fghij-*");
	tests.emplace_back("de-abcde-fghij-*-u-aa-klmno");
	tests.emplace_back("de-abcde-fghij-u-");
	tests.emplace_back("de-abcde-fghij-u-*");
	tests.emplace_back("de-abcde-fghij-u-aa-klmno-");
	tests.emplace_back("de-abcde-fghij-u-aa-klmno-*");
	tests.emplace_back("de-abcde-fghij-t-");
	tests.emplace_back("de-abcde-fghij-t-*");
	tests.emplace_back("de-abcde-fghij-t-aa-klmno-a1-abc-");
	tests.emplace_back("de-abcde-fghij-t-aa-klmno-a1-abc-*");
	tests.emplace_back("de-abcde-fghij-x-abcdef-");
	tests.emplace_back("de-abcde-fghij-x-abcdef-*");
	tests.emplace_back("de-abcde-fghij-a-");
	tests.emplace_back("de-abcde-fghij-a-*");
	tests.emplace_back("de-abcde-fghij-a-ab-");
	tests.emplace_back("de-abcde-fghij-a-ab-*");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isStructurallyValidLanguageTagReturnsFalse)
{
	cr_expect(eq(i8, ecma402_isStructurallyValidLanguageTag((*test).c_str()), 0),
	          "Expected \"%s\" to be invalid language tag, but it is valid", (*test).c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeLanguageSubtagReturnsTrue)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("ab");
	tests.emplace_back("abc");
	tests.emplace_back("abcde");
	tests.emplace_back("abcdef");
	tests.emplace_back("abcdefg");
	tests.emplace_back("abcdefgh");
	tests.emplace_back("AB");
	tests.emplace_back("ABC");
	tests.emplace_back("ABCDE");
	tests.emplace_back("ABCDEF");
	tests.emplace_back("ABCDEFG");
	tests.emplace_back("ABCDEFGH");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeLanguageSubtagReturnsTrue)
{
	cr_expect(eq(i8, ecma402::isUnicodeLanguageSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeLanguageSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeLanguageSubtagReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("a");
	tests.emplace_back("abcd");
	tests.emplace_back("abcdefghi");
	tests.emplace_back("abc-def");
	tests.emplace_back("123");
	tests.emplace_back("abc1def");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeLanguageSubtagReturnsFalse)
{
	cr_expect(eq(i8, ecma402::isUnicodeLanguageSubtag(test->c_str()), false),
	          "Expected false for \"%s\"; received true", test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeLanguageSubtag(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeScriptSubtagReturnsTrue)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("abcd");
	tests.emplace_back("aaaa");
	tests.emplace_back("zzzz");
	tests.emplace_back("ABCD");
	tests.emplace_back("AAAA");
	tests.emplace_back("ZZZZ");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeScriptSubtagReturnsTrue)
{
	cr_expect(eq(i8, ecma402::isUnicodeScriptSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeScriptSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeScriptSubtagReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("abc");
	tests.emplace_back("abcde");
	tests.emplace_back("ab-d");
	tests.emplace_back("a12d");
	tests.emplace_back("a.cd");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeScriptSubtagReturnsFalse)
{
	cr_expect(eq(i8, ecma402::isUnicodeScriptSubtag(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeScriptSubtag(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeRegionSubtagReturnsTrue)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("ab");
	tests.emplace_back("aa");
	tests.emplace_back("zz");
	tests.emplace_back("AB");
	tests.emplace_back("AA");
	tests.emplace_back("ZZ");
	tests.emplace_back("aB");
	tests.emplace_back("Ab");
	tests.emplace_back("123");
	tests.emplace_back("456");
	tests.emplace_back("789");
	tests.emplace_back("012");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeRegionSubtagReturnsTrue)
{
	cr_expect(eq(i8, ecma402::isUnicodeRegionSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeRegionSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeRegionSubtagReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("a");
	tests.emplace_back("a_");
	tests.emplace_back("a-");
	tests.emplace_back("_a");
	tests.emplace_back("-a");
	tests.emplace_back("abc");
	tests.emplace_back("abcd");
	tests.emplace_back("1");
	tests.emplace_back("12");
	tests.emplace_back("12_");
	tests.emplace_back("12-");
	tests.emplace_back("_12");
	tests.emplace_back("-12");
	tests.emplace_back("1234");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeRegionSubtagReturnsFalse)
{
	cr_expect(eq(i8, ecma402::isUnicodeRegionSubtag(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeRegionSubtag(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeVariantSubtagReturnsTrue)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("abcde");
	tests.emplace_back("abcdefgh");
	tests.emplace_back("12345");
	tests.emplace_back("12345678");
	tests.emplace_back("a1b2c");
	tests.emplace_back("a1b2c3d4");
	tests.emplace_back("1abc");
	tests.emplace_back("1234");
	tests.emplace_back("123a");
	tests.emplace_back("POSIX");
	tests.emplace_back("AALAND");
	tests.emplace_back("BOKMAL");
	tests.emplace_back("NYNORSK");
	tests.emplace_back("POLYTONI");
	tests.emplace_back("SAAHO");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeVariantSubtagReturnsTrue)
{
	cr_expect(eq(i8, ecma402::isUnicodeVariantSubtag(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeVariantSubtagReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("abcd");
	tests.emplace_back("abcdefghi");
	tests.emplace_back("123");
	tests.emplace_back("123456789");
	tests.emplace_back("a1b2");
	tests.emplace_back("a1b2c3d4e");
	tests.emplace_back("ab-cd");
	tests.emplace_back("abc-defg");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeVariantSubtagReturnsFalse)
{
	cr_expect(eq(i8, ecma402::isUnicodeVariantSubtag(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
}

Test(TEST_SUITE, LanguageTagParserSplitsTagAndTraversesParts)
{
	const std::string tag = "foo-bar-baz";
	ecma402::LanguageTagParser parser(tag);

	// "foo"
	cr_expect(eq(i8, parser.isEos(), false));
	cr_expect(eq(i8, parser.next(), true));

	// "bar"
	cr_expect(eq(i8, parser.isEos(), false));
	cr_expect(eq(i8, parser.next(), true));

	// "baz"
	cr_expect(eq(i8, parser.isEos(), false));
	cr_expect(eq(i8, parser.next(), false));

	// end
	cr_expect(eq(i8, parser.isEos(), true));
	cr_expect(eq(i8, parser.next(), false));
	cr_expect(eq(i8, parser.isEos(), true));
}

ParameterizedTestParameters(TEST_SUITE, parseUnicodeLanguageIdReturnsTrue)
{
	static criterion::parameters<string> tests;

	// isUnicodeLanguageSubtag && !next
	tests.emplace_back("ab");
	tests.emplace_back("abc");
	tests.emplace_back("abcde");
	tests.emplace_back("abcdef");
	tests.emplace_back("abcdefg");
	tests.emplace_back("abcdefgh");
	tests.emplace_back("AB");
	tests.emplace_back("ABC");
	tests.emplace_back("ABCDE");
	tests.emplace_back("ABCDEF");
	tests.emplace_back("ABCDEFG");
	tests.emplace_back("ABCDEFGH");

	// isUnicodeLanguageSubtag && isUnicodeScriptSubtag && !next
	tests.emplace_back("ab-abcd");
	tests.emplace_back("abc-aaaa");
	tests.emplace_back("abcde-zzzz");
	tests.emplace_back("abcdef-ABCD");
	tests.emplace_back("abcdefg-AAAA");
	tests.emplace_back("abcdefgh-ZZZZ");

	// isUnicodeLanguageSubtag && isUnicodeScriptSubtag && isUnicodeRegionSubtag
	//   && !next
	tests.emplace_back("ab-abcd-ab");
	tests.emplace_back("abc-aaaa-aa");
	tests.emplace_back("abcde-zzzz-zz");
	tests.emplace_back("abcdef-ABCD-AB");
	tests.emplace_back("abcdefg-AAAA-AA");
	tests.emplace_back("abcdefgh-ZZZZ-ZZ");

	// isUnicodeLanguageSubtag && !isUnicodeScriptSubtag && isUnicodeRegionSubtag
	//   && !next
	tests.emplace_back("ab-aB");
	tests.emplace_back("abc-Ab");
	tests.emplace_back("abcde-123");
	tests.emplace_back("abcdef-456");
	tests.emplace_back("abcdefg-789");
	tests.emplace_back("abcdefgh-012");

	// isUnicodeLanguageSubtag && [!]isUnicodeScriptSubtag &&
	//   [!]isUnicodeRegionSubtag && isUnicodeVariantSubtag
	//   [ && isUnicodeVariantSubtag ... ] && !next
	tests.emplace_back("ab-abcd-ab-abcde");
	tests.emplace_back("ab-abcde");
	tests.emplace_back("abc-aaaa-aa-abcdefgh");
	tests.emplace_back("abcde-zzzz-zz-12345-abcde");
	tests.emplace_back("abcdef-ABCD-AB-12345678");
	tests.emplace_back("abcdef-AB-12345678");
	tests.emplace_back("abcdefg-AAAA-AA-a1b2c");
	tests.emplace_back("abcdefgh-ZZZZ-ZZ-a1b2c3d4");
	tests.emplace_back("ab-abcd-ab-1abc-abcdefgh-a1b2c");
	tests.emplace_back("ab-ab-1abc-abcdefgh-a1b2c");
	tests.emplace_back("ab-abcd-1abc-abcdefgh-a1b2c");
	tests.emplace_back("abc-aaaa-aa-1234");
	tests.emplace_back("abcde-zzzz-zz-123a");

	// Tags with variants that should return true
	tests.emplace_back("aa-SAAHO");
	tests.emplace_back("de-DE-POSIX");
	tests.emplace_back("el-POLYTONI");
	tests.emplace_back("en-GB-POSIX");
	tests.emplace_back("en-POSIX");
	tests.emplace_back("en-US-POSIX");
	tests.emplace_back("en-US-POSIX-u-kn-true");
	tests.emplace_back("en-US-POSIX-u-kn-va-posix");
	tests.emplace_back("no-BOKMAL");
	tests.emplace_back("no-NYNORSK");
	tests.emplace_back("ru-POSIX");
	tests.emplace_back("sv-AALAND");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, parseUnicodeLanguageIdReturnsTrue)
{
	ecma402::LanguageTagParser parser(test->c_str());
	cr_expect(eq(i8, parser.parseUnicodeLanguageId(), true), "Expected true for \"%s\"; received false", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, parseUnicodeLanguageIdReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("a");
	tests.emplace_back("abcd");
	tests.emplace_back("abcdefghi");
	tests.emplace_back("ab-abcd-ab-abcde-abcde");
	tests.emplace_back("ab-abcde-abcde");
	tests.emplace_back("abc-aaaa-aa-abcdefgh-abcdefgh");
	tests.emplace_back("abcde-zzzz-zz-12345-abcde-12345");
	tests.emplace_back("abcdef-ABCD-AB-12345678-12345678");
	tests.emplace_back("abcdef-AB-12345678-12345678");
	tests.emplace_back("abcdefg-AAAA-AA-a1b2c-a1b2c");
	tests.emplace_back("abcdefgh-ZZZZ-ZZ-a1b2c3d4-a1b2c3d4");
	tests.emplace_back("ab-abcd-ab-1abc-abcdefgh-a1b2c-abcdefgh");
	tests.emplace_back("ab-ab-1abc-abcdefgh-a1b2c-abcdefgh");
	tests.emplace_back("ab-abcd-1abc-abcdefgh-a1b2c-abcdefgh");
	tests.emplace_back("abc-aaaa-aa-1234-1234");
	tests.emplace_back("abcde-zzzz-zz-123a-123a");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, parseUnicodeLanguageIdReturnsFalse)
{
	ecma402::LanguageTagParser parser(test->c_str());
	cr_expect(eq(i8, parser.parseUnicodeLanguageId(), false), "Expected false for \"%s\"; received true",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, parseUnicodeLocaleIdReturnsTrue)
{
	static criterion::parameters<string> tests;

	// Tests that structurally valid language tags are accepted, from Test262.
	// https://github.com/tc39/test262/blob/20e442011cbfca6c8ceb468da99894b9f17df65b/test/intl402/language-tags-valid.js#L11

	tests.emplace_back("de");          // ISO 639 language code
	tests.emplace_back("de-DE");       // + ISO 3166-1 country code
	tests.emplace_back("DE-de");       // tags are case-insensitive
	tests.emplace_back("cmn");         // ISO 639 language code
	tests.emplace_back("cmn-Hans");    // + script code
	tests.emplace_back("CMN-hANS");    // tags are case-insensitive
	tests.emplace_back("cmn-hans-cn"); // + ISO 3166-1 country code
	tests.emplace_back("es-419");      // + UN M.49 region code

	// + Unicode locale extension sequence
	tests.emplace_back("es-419-u-nu-latn-cu-bob");

	// singleton subtags can also be used as private use subtags
	tests.emplace_back("cmn-hans-cn-t-ca-u-ca-x-t-u");

	// variant and extension subtags may be the same
	tests.emplace_back("de-gregory-u-ca-gregory");

	// variant subtags can also be used as private use subtags
	tests.emplace_back("aa-a-foo-x-a-foo-bar");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, parseUnicodeLocaleIdReturnsTrue)
{
	ecma402::LanguageTagParser parser(test->c_str());
	cr_expect(eq(i8, parser.parseUnicodeLocaleId(), true), "Expected true for \"%s\"; received false", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, parseUnicodeLocaleIdReturnsFalse)
{
	static criterion::parameters<string> tests;

	// Invalid language tags taken from Test262
	// https://github.com/tc39/test262/blob/20e442011cbfca6c8ceb468da99894b9f17df65b/harness/testIntl.js#L193C36-L193C36

	tests.emplace_back("");                 // empty tag
	tests.emplace_back("i");                // singleton alone
	tests.emplace_back("x");                // private use without subtag
	tests.emplace_back("u");                // extension singleton in first place
	tests.emplace_back("419");              // region code in first place
	tests.emplace_back("u-nu-latn-cu-bob"); // extension sequence without language
	// "hans" could theoretically be a 4-letter language code, but those can't be
	// followed by extlang codes.
	tests.emplace_back("hans-cmn-cn");
	tests.emplace_back("cmn-hans-cn-u-u");           // duplicate singleton
	tests.emplace_back("cmn-hans-cn-t-u-ca-u");      // duplicate singleton
	tests.emplace_back("de-gregory-gregory");        // duplicate variant
	tests.emplace_back("*");                         // language range
	tests.emplace_back("de-*");                      // language range
	tests.emplace_back("中文");                      // non-ASCII letters
	tests.emplace_back("en-ß");                      // non-ASCII letters
	tests.emplace_back("ıd");                        // non-ASCII letters
	tests.emplace_back("es-Latn-latn");              // two scripts
	tests.emplace_back("pl-PL-pl");                  // two regions
	tests.emplace_back("u-ca-gregory");              // extension in first place
	tests.emplace_back("de-1996-1996");              // duplicate numeric variant
	tests.emplace_back("pt-u-ca-gregory-u-nu-latn"); // duplicate singleton subtag

	// Invalid tags starting with: https://github.com/tc39/ecma402/pull/289

	// regular grandfathered in BCP47, but invalid in UTS35
	tests.emplace_back("no-nyn");
	// irregular grandfathered in BCP47, but invalid in UTS35
	tests.emplace_back("i-klingon");
	// language with extlang in BCP47, but invalid in UTS35
	tests.emplace_back("zh-hak-CN");
	// language with extlang in BCP47, but invalid in UTS35
	tests.emplace_back("sgn-ils");

	tests.emplace_back("x-foo");         // privateuse-only in BCP47, but invalid in UTS35
	tests.emplace_back("x-en-US-12345"); // more privateuse-only variants.
	tests.emplace_back("x-12345-12345-en-US");
	tests.emplace_back("x-en-US-12345-12345");
	tests.emplace_back("x-en-u-foo");
	tests.emplace_back("x-en-u-foo-u-bar");
	tests.emplace_back("x-u-foo");

	// underscores in different parts of the language tag
	tests.emplace_back("de_DE");
	tests.emplace_back("DE_de");
	tests.emplace_back("cmn_Hans");
	tests.emplace_back("cmn-hans_cn");
	tests.emplace_back("es_419");
	tests.emplace_back("es-419-u-nu-latn-cu_bob");
	tests.emplace_back("i_klingon");
	tests.emplace_back("cmn-hans-cn-t-ca-u-ca-x_t-u");
	tests.emplace_back("enochian_enochian");
	tests.emplace_back("de-gregory_u-ca-gregory");

	tests.emplace_back(" en");        // leading whitespace
	tests.emplace_back("en ");        // trailing whitespace
	tests.emplace_back("it-IT-Latn"); // country before script tag
	tests.emplace_back("de-u");       // incomplete Unicode extension sequences
	tests.emplace_back("de-u-");
	tests.emplace_back("de-u-ca-");
	tests.emplace_back("de-u-ca-gregory-");
	tests.emplace_back("si-x"); // incomplete private-use tags
	tests.emplace_back("x-");
	tests.emplace_back("x-y-");

	tests.emplace_back("ab-");
	tests.emplace_back("ab-abcde-fghij-");
	tests.emplace_back("-ab");
	tests.emplace_back("de-*");
	tests.emplace_back("de-abcde-fghij-*");
	tests.emplace_back("de-abcde-fghij-*-u-aa-klmno");
	tests.emplace_back("de-abcde-fghij-u-");
	tests.emplace_back("de-abcde-fghij-u-*");
	tests.emplace_back("de-abcde-fghij-u-aa-klmno-");
	tests.emplace_back("de-abcde-fghij-u-aa-klmno-*");
	tests.emplace_back("de-abcde-fghij-t-");
	tests.emplace_back("de-abcde-fghij-t-*");
	tests.emplace_back("de-abcde-fghij-t-aa-klmno-a1-abc-");
	tests.emplace_back("de-abcde-fghij-t-aa-klmno-a1-abc-*");
	tests.emplace_back("de-abcde-fghij-x-abcdef-");
	tests.emplace_back("de-abcde-fghij-x-abcdef-*");
	tests.emplace_back("de-abcde-fghij-a-");
	tests.emplace_back("de-abcde-fghij-a-*");
	tests.emplace_back("de-abcde-fghij-a-ab-");
	tests.emplace_back("de-abcde-fghij-a-ab-*");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, parseUnicodeLocaleIdReturnsFalse)
{
	ecma402::LanguageTagParser parser(test->c_str());
	cr_expect(eq(i8, parser.parseUnicodeLocaleId(), false), "Expected false for \"%s\"; received true", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeLocaleIdentifierTypeReturnsTrue)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("abc");
	tests.emplace_back("abcd");
	tests.emplace_back("abcde");
	tests.emplace_back("abcdef");
	tests.emplace_back("abcdefg");
	tests.emplace_back("abcdefgh");
	tests.emplace_back("123");
	tests.emplace_back("1234");
	tests.emplace_back("12345");
	tests.emplace_back("123456");
	tests.emplace_back("1234567");
	tests.emplace_back("12345678");
	tests.emplace_back("abcd1234");
	tests.emplace_back("abc-123");
	tests.emplace_back("abcd1234-abcd1234");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeLocaleIdentifierTypeReturnsTrue)
{
	cr_expect(eq(i8, ecma402_isUnicodeLocaleIdentifierType(test->c_str()), true),
	          "Expected true for \"%s\"; received false", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeLocaleIdentifierTypeReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("ab");
	tests.emplace_back("abcdefghi");
	tests.emplace_back("12");
	tests.emplace_back("123456789");
	tests.emplace_back("abcd12345");
	tests.emplace_back("ab-123");
	tests.emplace_back("abcd12345-123");
	tests.emplace_back("abc-12");
	tests.emplace_back("abc-abcd12345");
	tests.emplace_back("abc_123");
	tests.emplace_back("abc-");
	tests.emplace_back("-def");
	tests.emplace_back("-123-");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeLocaleIdentifierTypeReturnsFalse)
{
	cr_expect(eq(i8, ecma402_isUnicodeLocaleIdentifierType(test->c_str()), false),
	          "Expected false for \"%s\"; received true", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeCurrencyTypeReturnsTrue)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("abc");
	tests.emplace_back("ABC");
	tests.emplace_back("XXX");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeCurrencyTypeReturnsTrue)
{
	cr_expect(eq(i8, ecma402::isUnicodeCurrencyType(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeCurrencyType(test->c_str()), true), "Expected true for \"%s\"; received false",
	          test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isUnicodeCurrencyTypeReturnsFalse)
{
	static criterion::parameters<string> tests;

	tests.emplace_back("a");
	tests.emplace_back("abcd");
	tests.emplace_back("abcdefghi");
	tests.emplace_back("abc-def");
	tests.emplace_back("123");
	tests.emplace_back("abc1def");

	return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isUnicodeCurrencyTypeReturnsFalse)
{
	cr_expect(eq(i8, ecma402::isUnicodeCurrencyType(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
	cr_expect(eq(i8, ecma402_isUnicodeCurrencyType(test->c_str()), false), "Expected false for \"%s\"; received true",
	          test->c_str());
}

// NOLINTEND(cert-err58-cpp, misc-const-correctness,
//           misc-use-anonymous-namespace)
