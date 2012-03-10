#ifndef GUARD_EVIPP_STRING_CEND_HPP_INCLUDED
#define GUARD_EVIPP_STRING_CEND_HPP_INCLUDED

#include <evipp/string/type.hpp>

namespace evipp {
namespace string {

inline
type::const_iterator
end(
	type const & str)
{
	return str.end();
}

}}

#endif //GUARD_EVIPP_STRING_CEND_HPP_INCLUDED

