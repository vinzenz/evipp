#ifndef GUARD_CONFIG_COMPILER_HPP_INCLUDED
#define GUARD_CONFIG_COMPILER_HPP_INCLUDED

#if defined(__clang__)
#	include <evipp/config/compiler/clang.hpp>
#elif defined(__GNUC__)
#	include <evipp/config/compiler/gcc.hpp>
#elif defined(_MSC_VER)
#	include <evipp/config/compiler/msvc.hpp>
#else
#	error Compiler not supported
#endif

#endif //GUARD_CONFIG_COMPILER_HPP_INCLUDED

