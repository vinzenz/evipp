#ifndef GUARD_EVIPP_CONFIG_COMPILER_CLANG_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_COMPILER_CLANG_HPP_INCLUDED

#include <evipp/config/compiler/clang/text.hpp>
#include <evipp/config/compiler/clang/char_type.hpp>

#define EVIPP_COMPILER_CLANG
#define EVIPP_COMPILER_HAS_PRAGMA
#define EVIPP_PRAGMA(x) _Pragma(#x)

#define EVIPP_HAVE_UTF16_LITERALS
#define EVIPP_HAVE_UTF32_LITERALS
#define EVIPP_HAVE_UTF8_LITERALS

namespace evipp {
namespace config {
namespace compiler {

typedef evipp::config::compiler::clang::char_type char_type;

typedef char	 char8_type;
typedef char16_t char16_type;
typedef char32_t char32_type;

}}}


#endif //GUARD_EVIPP_CONFIG_COMPILER_CLANG_HPP_INCLUDED

