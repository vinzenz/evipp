#ifndef GUARD_STRING_UTF32_TYPE_HPP_INCLUDED
#define GUARD_STRING_UTF32_TYPE_HPP_INCLUDED

#include <evipp/string/detail/type.hpp>
#include <evipp/string/utf32/detail/traits.hpp>

namespace evipp {
namespace string {
namespace utf32 {

typedef evipp::string::detail::type< 
	evipp::string::utf32::char_type,
	evipp::string::utf32::detail::traits
> type;

}}}

#endif //GUARD_STRING_UTF32_TYPE_HPP_INCLUDED

