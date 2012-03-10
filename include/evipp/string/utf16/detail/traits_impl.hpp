#ifndef GUARD_EVIPP_STRING_UTF16_DETAIL_TRAITS_IMPL_HPP_INCLUDED
#define GUARD_EVIPP_STRING_UTF16_DETAIL_TRAITS_IMPL_HPP_INCLUDED

#include <evipp/string/utf16/detail/traits.hpp>
#include <evipp/string/utf8/char_type.hpp>
#include <evipp/string/utf32/char_type.hpp>
#include <evipp/algorithm/append.hpp>

#include <utf8.h>

namespace evipp {
namespace string {
namespace utf16 {
namespace detail {

template< 
	typename Container
>
Container
traits::combine(
	Container const & lhs,
	Container const & rhs )
{
	Container result((lhs));
	result.pop_back();

	evipp::algorithm::append(
		result,
		rhs );

	return std::move( result );
}

template< 
	typename result_iterator,
	typename u32bit_iterator
>
result_iterator
utf32to16(
	u32bit_iterator start,
	u32bit_iterator end,
	result_iterator result )
{
	while( start != end )
	{
		utf32::char_type cp = *start;
		if (cp > 0xffff) 
		{ //make a surrogate pair
			*result++ = static_cast<utf16::char_type>((cp >> 10)   + ::utf8::internal::LEAD_OFFSET);
			*result++ = static_cast<utf16::char_type>((cp & 0x3ff) + ::utf8::internal::TRAIL_SURROGATE_MIN);
		}
        else
		{
			*result++ = static_cast<utf16::char_type>(cp);
		}		
	}
	return result;
}

template<
	typename TargetContainer 
>
TargetContainer
to_utf16(
	utf32::char_type const * begin,
	utf32::char_type const * end )
{
	TargetContainer container;

	utf32to16(
		begin,
		end,
		std::back_inserter(
			container ));

	return std::move( container );
}

template<
	typename TargetContainer 
>
TargetContainer
to_utf16(
	utf8::char_type const * begin,
	utf8::char_type const * end )
{
	TargetContainer container;

	::utf8::utf8to16(
		begin,
		end,
		std::back_inserter(
			container ));

	return std::move( container );
}

template<
	typename TargetContainer,
	typename SourceContainer
>
TargetContainer
traits::convert(
	SourceContainer const & source )
{
	return std::move(
		to_utf16(
			&source[0],
			&source[0] + source.size() ) );
}

}}}}

#endif //GUARD_EVIPP_STRING_UTF16_DETAIL_TRAITS_IMPL_HPP_INCLUDED

