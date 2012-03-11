#include "../evipp_test.hpp"
#include <evipp/string/utf16/type.hpp>
#include <evipp/string/utf16/type_impl.hpp>

struct utf16_string_data {
	evipp::string::utf16::type str;
};

EVIPP_TEST_GROUP_DEF(utf16_string_data, "evipp::string::utf16")

EVIPP_TEST_DEF(1)
{
	ensure( "str.size() == 0", str.size() == 0 );
	ensure( "str.empty() == true", str.size() == 0 );
}

EVIPP_TEST_DEF(2)
{
	str = evipp::string::utf16::type( EVIPP_UTF16("test text") );
	ensure( "str.size() == 9 where str = 'test text'", str.size() == 9 );
}

EVIPP_TEST_DEF(3)
{
	str = evipp::string::utf16::type( EVIPP_UTF16("") );
	ensure( "empty after assigning evipp::string(\"\")", str.empty() );
}

EVIPP_TEST_DEF(4)
{
	str = EVIPP_UTF16("test text");
	ensure( "str.size() == 9 where str = 'test text'", str.size() == 9 );
}

EVIPP_TEST_GROUP_END

