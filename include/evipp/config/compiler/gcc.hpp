#ifndef GUARD_EVIPP_CONFIG_COMPILER_GCC_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_COMPILER_GCC_HPP_INCLUDED

#include <evipp/config/compiler/gcc/text.hpp>
#include <evipp/config/compiler/gcc/char_type.hpp>

#define EVIPP_COMPILER_GCC
#define EVIPP_COMPILER_HAS_PRAGMA
#define EVIPP_PRAGMA(x) _Pragma(#x)

namespace evipp {
namespace config {
namespace compiler {

typedef evipp::config::compiler::gcc::char_type char_type;

typedef char	 char8_type;
typedef char16_t char16_type;
typedef char32_t char32_type;

}}}


#endif //GUARD_EVIPP_CONFIG_COMPILER_GCC_HPP_INCLUDED

