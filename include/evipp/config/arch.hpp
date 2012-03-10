#ifndef GUARD_EVIPP_CONFIG_ARCH_HPP_INCLUDED
#define GUARD_EVIPP_CONFIG_ARCH_HPP_INCLUDED

namespace evipp {
namespace config {
namespace arch {
	enum type {
		x86,
		amd64,
		itanium
	};
}}};

#if \
		defined(_M_X86) \
	||	defined(__i386__) \
	||	defined(_M_IX86)
#	define EVIPP_ARCH_X86
#	define EVIPP_ARCH_APPLICATION evipp::config::arch::x86
#include <evipp/config/arch/x86.hpp>
#elif \
		defined(_M_X64) \
	||	defined(__amd64) \
	||	defined(__amd64__) \
	||	defined(_M_AMD64) \
	||	defined(__x86_64) \
	||	defined(__x86_64__)
#	define EVIPP_ARCH_AMD64
#	define EVIPP_ARCH_APPLICATION evipp::config::arch::amd64
#include <evipp/config/arch/amd64.hpp>
#elif \
		defined(__ia64__) \
	||	defined(_M_IA64)
#	define EVIPP_ARCH_ITANIUM
#	define EVIPP_ARCH_APPLICATION evipp::config::arch::itanium
#include <evipp/config/arch/ia64.hpp>
#else
#	error "Unknown architecture. Please set up the architecture for your CPU"
#endif

#endif //GUARD_CONFIG_ARCH_HPP_INCLUDED

