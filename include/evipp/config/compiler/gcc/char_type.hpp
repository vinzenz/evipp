#ifndef GUARD_EVIPP_CONFIG_COMPILER_GCC_CHAR_TYPE_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_COMPILER_GCC_CHAR_TYPE_HPP_INCLUDED

namespace evipp {
namespace config {
namespace compiler {
namespace gcc {

#if defined(EVIPP_UNICODE_UTF16)
typedef char16_t 	char_type;
#elif defined(EVIPP_UNICODE_UTF32)
typedef char32_t 	char_type
#elif defined(EVIPP_UNICODE_WCHART)
typedef wchar_t 	char_type;
#else
typedef char 		char_type;
#endif


}}}}

#endif //GUARD_EVIPP_CONFIG_COMPILER_GCC_CHAR_TYPE_HPP_INCLUDED

