#include "../evipp_test.hpp"
#include <evipp/string/utf8/type.hpp>
#include <evipp/string/utf8/type_impl.hpp>

struct utf8_string_data {
	evipp::string::utf8::type str;
};

EVIPP_TEST_GROUP_DEF(utf8_string_data, "evipp::string::utf8")

EVIPP_TEST_DEF(1)
{
	ensure( "str.size() == 0", str.size() == 0 );
	ensure( "str.empty() == true", str.size() == 0 );
}

EVIPP_TEST_DEF(2)
{
	str = evipp::string::utf8::type("test text");
	ensure( "str.size() == 9 where str = 'test text'", str.size() == 9 );
}

EVIPP_TEST_DEF(3)
{
	str = evipp::string::utf8::type("");
	ensure( "empty after assigning evipp::string(\"\")", str.empty() );
}

EVIPP_TEST_DEF(4)
{
	str = "test text";
	ensure( "str.size() == 9 where str = 'test text'", str.size() == 9 );
}

EVIPP_TEST_GROUP_END

