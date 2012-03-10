#ifndef GUARD_EVIPP_STRING_UCS2_DETAIL_TRAITS_HPP_INCLUDED
#define GUARD_EVIPP_STRING_UCS2_DETAIL_TRAITS_HPP_INCLUDED

#include <evipp/string/ucs2/char_type.hpp>
#include <evipp/string/ucs2/char_type.hpp>
#include <evipp/string/ucs2/size_type.hpp>

namespace evipp {
namespace string {
namespace ucs2 {
namespace detail {

class traits 
{
public:
	typedef evipp::string::ucs2::char_type 		char_type;
	typedef char_type const *					const_pointer;
	typedef evipp::string::ucs2::size_type		size_type;

	static
	size_type
		len(
			const_pointer value );

	template< 
		typename Container
	>
	static
	Container
		combine(
			Container const & lhs,
			Container const & rhs );

	template<
		typename TargetContainer,
		typename SourceContainer
	>
	static
	TargetContainer
		convert(
			SourceContainer const & source );

	static
	size_type
		character_count(
			const_pointer value,
			size_type element_count );

	static
	int
		compare(
			const_pointer lhs,
			size_type lhs_element_count,
			const_pointer rhs,
			size_type rhs_element_count );

};

}}}}

#endif //GUARD_EVIPP_STRING_UCS2_DETAIL_TRAITS_HPP_INCLUDED

