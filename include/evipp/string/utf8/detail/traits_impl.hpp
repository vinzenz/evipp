#ifndef GUARD_STRING_UTF8_DETAIL_TRAITS_IMPL_HPP_INCLUDED
#define GUARD_STRING_UTF8_DETAIL_TRAITS_IMPL_HPP_INCLUDED

#include <evipp/string/utf8/detail/traits.hpp>
#include <evipp/algorithm/append.hpp>

namespace evipp {
namespace string {
namespace utf8 {
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
	typename TargetContainer,
typename SourceContainer
>
TargetContainer
traits::convert(
	SourceContainer const & source )
{
	//TODO: Implement conversion
	return TargetContainer();	
}

}}}}

#endif //GUARD_STRING_UTF8_DETAIL_TRAITS_IMPL_HPP_INCLUDED

