#include "../evipp_test.hpp"
#include <evipp/string/type.hpp>
#include <evipp/string/size.hpp>

struct string_data {
};

EVIPP_TEST_GROUP_DEF(string_data, "evipp::string")

EVIPP_TEST_DEF(1)
{
	ensure( "size( empty_string ) == 0", evipp::string::size( evipp::string::type() ) == 0 );
}

EVIPP_TEST_DEF(2)
{
	
}

EVIPP_TEST_GROUP_END

