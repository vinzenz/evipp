#ifndef GUARD_EVIPP_CONFIG_COMPILER_MSVC_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_COMPILER_MSVC_HPP_INCLUDED

#include <evipp/config/compiler/msvc/text.hpp>
#include <evipp/config/compiler/msvc/char_type.hpp>
#include <evipp/types/uint32.hpp>

#define EVIPP_COMPILER_MSVC
#define EVIPP_COMPILER_HAS_PRAGMA
#define EVIPP_PRAGMA(x) __pragma(x)

#define EVIPP_HAVE_UTF16_LITERALS
// #define EVIPP_HAVE_UTF32_LITERALS
#define EVIPP_HAVE_UTF8_LITERALS

namespace evipp {
namespace config {
namespace compiler {

typedef evipp::config::compiler::msvc::char_type char_type;

typedef char	 				char8_type;
typedef wchar_t  				char16_type;
typedef evipp::types::uint32 	char32_type;

}}}

#endif //GUARD_EVIPP_CONFIG_COMPILER_MSVC_HPP_INCLUDED
