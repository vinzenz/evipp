#ifndef GUARD_EVIPP_CONFIG_COMPILER_MSVC_CHAR_TYPE_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_COMPILER_MSVC_CHAR_TYPE_HPP_INCLUDED

namespace evipp {
namespace config {
namespace compiler {
namespace msvc {

#if defined(EVIPP_UNICODE_UTF16)
// We use wchar_t also for UTF16
typedef wchar_t 	char_type;
#elif defined(EVIPP_UNICODE_UTF32)
#	error "UTF32 is not supported yet by Microsoft Visual C++"
#elif defined(EVIPP_UNICODE_WCHART)
typedef wchar_t 	char_type;
#else
typedef char 		char_type;
#endif

}}}}

#endif //GUARD_EVIPP_CONFIG_COMPILER_MSVC_CHAR_TYPE_HPP_INCLUDED

