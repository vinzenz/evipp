#ifndef GUARD_STRING_END_HPP_INCLUDED
#define GUARD_STRING_END_HPP_INCLUDED

#include <evipp/string/type.hpp>

namespace evipp {
namespace string {

inline
type::iterator
end(type & str)
{
	return str.end();
}

inline
type::const_iterator
end(type const & str)
{
	return str.end();
}

}}

#endif //GUARD_STRING_END_HPP_INCLUDED

