#ifndef GUARD_EVIPP_STRING_UTF32_DETAIL_TRAITS_IMPL_HPP_INCLUDED
#define GUARD_EVIPP_STRING_UTF32_DETAIL_TRAITS_IMPL_HPP_INCLUDED

#include <evipp/string/utf8/char_type.hpp>
#include <evipp/string/utf16/char_type.hpp>
#include <evipp/string/utf32/detail/traits.hpp>
#include <evipp/algorithm/append.hpp>

#include <utf8.h>

namespace evipp {
namespace string {
namespace utf32 {
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
	typename u16bit_iterator
>
result_iterator
utf16to32(
	u16bit_iterator start,
	u16bit_iterator end,
	result_iterator result )
{
	while( start != end )
	{
		utf32::char_type cp = ::utf8::internal::mask16(*start++);
		if( ::utf8::internal::is_lead_surrogate(cp ) )
		{
			if( start != end )
			{
				utf32::char_type trail_surrogate = ::utf8::internal::mask16(*start++);
				if( ::utf8::internal::is_trail_surrogate( trail_surrogate ) )
				{
					cp = (cp << 10) + trail_surrogate + ::utf8::internal::SURROGATE_OFFSET;					
				}
				else
				{
					throw ::utf8::invalid_utf16( static_cast< ::utf8::uint16_t >(trail_surrogate) );
				}				
			}
			else
			{
					throw ::utf8::invalid_utf16( static_cast< ::utf8::uint16_t >(cp) );
			}
		}
		else if( ::utf8::internal::is_trail_surrogate( cp ) )
		{
			throw ::utf8::invalid_utf16( static_cast< ::utf8::uint16_t >(cp) );
		}

		*result++ = cp;
	}
	return result;
}

template<
	typename TargetContainer 
>
TargetContainer
to_utf32(
	utf16::char_type const * begin,
	utf16::char_type const * end )
{
	TargetContainer container;

	utf16to32(
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
to_utf32(
	utf8::char_type const * begin,
	utf8::char_type const * end )
{
	TargetContainer container;

	::utf8::utf8to32(
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
		to_utf32(
			&source[0],
			&source[0] + source.size() ) );
}

}}}}

#endif //GUARD_EVIPP_STRING_UTF32_DETAIL_TRAITS_IMPL_HPP_INCLUDED

