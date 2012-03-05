#ifndef GUARD_STRING_BEGIN_HPP_INCLUDED
#define GUARD_STRING_BEGIN_HPP_INCLUDED

#include <evipp/string/type.hpp>

namespace evipp {
namespace string {

inline
type::iterator
begin(
	type & str)
{
	return str.begin();
}

inline
type::const_iterator
begin(
	type const & str)
{
	return str.begin();
}

}}


#endif //GUARD_STRING_BEGIN_HPP_INCLUDED

