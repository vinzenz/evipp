#include <evipp/string/detail/utf8_to_utf32.hpp>
#include "../../../../utils/libs/utf8/source/utf8.h"

namespace evipp {
namespace string {
namespace detail {

utf8_to_utf32::utf8_to_utf32( 
	utf8_constpointer begin, 
	utf8_constpointer end )
: begin_( begin )
, current_( begin )
, end_( end )
{}

bool
utf8_to_utf32::end() const
{
	return current_ >= end_;
}

utf8_to_utf32::utf32_t
utf8_to_utf32::next()
{
	return ::utf8::next( current_, end_ );
}

utf8_to_utf32::size_type 
utf8_to_utf32::character_count( 
		utf8_constpointer value, 
		size_type element_count )
{
	return static_cast<size_type>(
		::utf8::distance( value, value + element_count )
	);
}


}}}
