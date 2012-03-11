#include "../evipp_test.hpp"
#include <evipp/string/type.hpp>
#include <evipp/string/size.hpp>

struct string_data {
	evipp::string::type str;
};

EVIPP_TEST_GROUP_DEF(string_data, "evipp::string")

	EVIPP_TEST_DEF(1)
{
	ensure( "size( empty_string ) == 0", evipp::string::size( str ) == 0 );
}

EVIPP_TEST_DEF(2)
{
	str = EVIPP_TEXT("test text");
	ensure( "size( str ) == 9 where str = 'test text'", evipp::string::size(str) == 9 );
}

EVIPP_TEST_DEF(3)
{
	str = evipp::string::type( EVIPP_TEXT("") );
	ensure( "empty after assigning evipp::string(\"\")", str.empty() );
}

EVIPP_TEST_GROUP_END

