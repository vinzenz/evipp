#ifndef GUARD_STRING_UTF8_TYPE_HPP_INCLUDED
#define GUARD_STRING_UTF8_TYPE_HPP_INCLUDED

#include <evipp/string/detail/type.hpp>
#include <evipp/string/utf8/detail/traits.hpp>

namespace evipp {
namespace string {
namespace utf8 {

typedef evipp::string::detail::type< 
	evipp::string::utf8::char_type,
	evipp::string::utf8::detail::traits
> type;

}}}

#endif //GUARD_STRING_UTF8_TYPE_HPP_INCLUDED

