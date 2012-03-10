#ifndef GUARD_EVIPP_STRING_UCS2_TYPE_HPP_INCLUDED
#define GUARD_EVIPP_STRING_UCS2_TYPE_HPP_INCLUDED

#include <evipp/string/detail/type.hpp>
#include <evipp/string/ucs2/detail/traits.hpp>

namespace evipp {
namespace string {
namespace ucs2 {

typedef evipp::string::detail::type< 
	evipp::string::ucs2::char_type,
	evipp::string::ucs2::detail::traits
> type;

}}}

#endif //GUARD_EVIPP_STRING_UCS2_TYPE_HPP_INCLUDED

