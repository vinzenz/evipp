#ifndef GUARD_EVIPP_STRING_UCS2_DETAIL_TRAITS_IMPL_HPP_INCLUDED
#define GUARD_EVIPP_STRING_UCS2_DETAIL_TRAITS_IMPL_HPP_INCLUDED

#include <evipp/string/ucs2/detail/traits.hpp>
#include <evipp/string/utf8/char_type.hpp>
#include <evipp/string/utf32/char_type.hpp>
#include <evipp/algorithm/append.hpp>

#include <utf8.h>

namespace evipp {
namespace string {
namespace ucs2 {
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
utf32_to_ucs2(
	u32bit_iterator start,
	u32bit_iterator end,
	result_iterator result )
{
	while( start != end )
	{
		utf32::char_type cp = *start;
		if (cp > 0xffff) 
		{ 	// UCS2 does not support surrogates -> Replacing by ??
			*result++ = static_cast<ucs2::char_type>('?');
			*result++ = static_cast<ucs2::char_type>('?');
		}
        else
		{
			*result++ = static_cast<ucs2::char_type>(cp);
		}		
	}
	return result;
}

template<
	typename TargetContainer 
>
TargetContainer
to_ucs2(
	utf32::char_type const * begin,
	utf32::char_type const * end )
{
	TargetContainer container;

	utf32_to_ucs2(
		begin,
		end,
		std::back_inserter(
			container ));

	return std::move( container );
}

template< 
	typename result_iterator,
	typename u8bit_iterator
>
result_iterator
utf8_to_ucs2(
	u8bit_iterator start,
	u8bit_iterator end,
	result_iterator result )
{
	while( start != end )
	{
		utf32::char_type cp = ::utf8::next( start, end );
		if( cp > 0xffff )
		{ 	// UCS2 does not support surrogates -> Replacing by ??
			*result++ = static_cast<ucs2::char_type>('?');
			*result++ = static_cast<ucs2::char_type>('?');
		}
		else
		{
			*result++ = static_cast<ucs2::char_type>(cp);
		}
	}
	return result;
}


template<
	typename TargetContainer 
>
TargetContainer
to_ucs2(
	utf8::char_type const * begin,
	utf8::char_type const * end )
{
	TargetContainer container;

	utf8_to_ucs2(
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
		to_ucs2(
			&source[0],
			&source[0] + source.size() ) );
}

}}}}

#endif //GUARD_EVIPP_STRING_UCS2_DETAIL_TRAITS_IMPL_HPP_INCLUDED

