#ifndef GUARD_STRING_UTF32_DETAIL_TRAITS_IMPL_HPP_INCLUDED
#define GUARD_STRING_UTF32_DETAIL_TRAITS_IMPL_HPP_INCLUDED

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
	typename TargetContainer 
>
TargetContainer
to_utf32(
	utf16::char_type const * begin,
	utf16::char_type const * end )
{
	TargetContainer container;

	::utf8::utf16to32(
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
static
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

#endif //GUARD_STRING_UTF32_DETAIL_TRAITS_IMPL_HPP_INCLUDED

