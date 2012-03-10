#ifndef GUARD_EVIPP_PREPROCESSOR_STRINGIZE_HPP_INCLUDED
#define GUARD_EVIPP_PREPROCESSOR_STRINGIZE_HPP_INCLUDED

#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/wstringize.hpp>

#define EVIPP_STRINGIZE(x)	BOOST_PP_STRINGIZE(x)
#define EVIPP_WSTRINGIZE(x) BOOST_PP_WSTRINGIZE(x)

#if defined(EVIPP_WIDE_STRING)
#	define EVIPP_TSTRINGIZE(x) BOOST_PP_WSTRINGIZE(x)
#else 
#	define EVIPP_TSTRINGIZE(x) BOOST_PP_STRINGIZE(x)
#endif

#endif //GUARD_EVIPP_PREPROCESSOR_STRINGIZE_HPP_INCLUDED

