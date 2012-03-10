#ifndef GUARD_EVIPP_CONFIG_OS_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_OS_HPP_INCLUDED

#if \
		defined(linux) \
	||	defined(__linux) \
	||	defined(__linux__) \
	||	defined(__GNU__) \
	||	defined(__GLIBC__) \
	&&  !defined(_CRAYC)

#include <evipp/config/os/linux.hpp>

#elif \
		defined(WIN32) \
	||	defined(_WIN32) \
	||	defined(__WIN32)

#include <evipp/config/os/windows.hpp>

#elif \
		defined(macintosh) \
	||	defined(__APPLE__) \
	||	defined(__APPLE_CC__)

#	include <evipp/config/os/darwin.hpp>

#else
#	error	"Please configure your operating system"
#endif

#endif //GUARD_EVIPP_CONFIG_OS_HPP_INCLUDED

