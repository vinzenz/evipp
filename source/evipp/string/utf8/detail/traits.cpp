#include <evipp/string/utf8/detail/traits.hpp>

#include <cstring>
#include <cassert>

namespace evipp {
namespace string {
namespace utf8 {
namespace detail {

traits::size_type
traits::len(
	const_pointer value )
{
	size_type count = 0;
	for(; value && *value; ++value, ++count )
	{
		//empty
	}
	return count;
}

traits::size_type
traits::character_count(
	const_pointer value,
	size_type element_count )
{
	//TODO: implement character counting for UTF-8
	return element_count;
}

int
traits::compare(
	const_pointer lhs,
	size_type lhs_element_count,
	const_pointer rhs,
	size_type rhs_element_count )
{
	if( 
			lhs_element_count 
		> 	rhs_element_count ) 
	{
		return -1;
	}

	if( 
			lhs_element_count 
		< 	rhs_element_count ) 
	{
		return 1;
	}
	
	//Precondition: lhs_element_count == rhs_element_count
	assert( lhs_element_count == rhs_element_count );

	//TODO: implement utf8 string comparison
	return std::memcmp( lhs, rhs, rhs_element_count );
}

}}}}

