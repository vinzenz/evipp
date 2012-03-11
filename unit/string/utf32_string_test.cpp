#include "../evipp_test.hpp"
#include <evipp/string/utf32/type.hpp>
#include <evipp/string/utf32/type_impl.hpp>

struct utf32_string_data {
	evipp::string::utf32::type str;
};

EVIPP_TEST_GROUP_DEF(utf32_string_data, "evipp::string::utf32")

EVIPP_TEST_DEF(1)
{
	ensure( "str.size() == 0", str.size() == 0 );
	ensure( "str.empty() == true", str.size() == 0 );
}

EVIPP_TEST_DEF(2)
{
#if defined(EVIPP_HAVE_UTF32_LITERALS)
	str = evipp::string::utf32::type(U"test text");
	ensure( "str.size() == 9 where str = 'test text'", str.size() == 9 );
#else
	ensure( "Compiler does not support utf32 literals", false );
#endif
}

EVIPP_TEST_DEF(3)
{
#if defined(EVIPP_HAVE_UTF32_LITERALS)
	str = evipp::string::utf32::type(U"");
	ensure( "empty after assigning evipp::string(\"\")", str.empty() );
#else
	ensure( "Compiler does not support utf32 literals", false );
#endif
}

EVIPP_TEST_DEF(4)
{
#if defined(EVIPP_HAVE_UTF32_LITERALS)
	str = U"test text";
	ensure( "str.size() == 9 where str = 'test text'", str.size() == 9 );
#else
	ensure( "Compiler does not support utf32 literals", false );
#endif
}

EVIPP_TEST_GROUP_END

