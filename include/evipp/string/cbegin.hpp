#ifndef GUARD_EVIPP_STRING_CBEGIN_HPP_INCLUDED
#define GUARD_EVIPP_STRING_CBEGIN_HPP_INCLUDED

#include <evipp/string/type.hpp>

namespace evipp {
namespace string {

inline
type::const_iterator
cbegin(
	type const & str)
{
	return str.begin();
}

}}

#endif //GUARD_STRING_CBEGIN_HPP_INCLUDED

