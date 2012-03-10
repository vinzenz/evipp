#ifndef GUARD_STRING_UTF16_TYPE_HPP_INCLUDED
#define GUARD_STRING_UTF16_TYPE_HPP_INCLUDED

#include <evipp/string/detail/type.hpp>
#include <evipp/string/utf16/detail/traits.hpp>

namespace evipp {
namespace string {
namespace utf16 {

typedef evipp::string::detail::type< 
	evipp::string::utf16::char_type,
	evipp::string::utf16::detail::traits
> type;

}}}

#endif //GUARD_STRING_UTF16_TYPE_HPP_INCLUDED

