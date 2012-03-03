#ifndef GUARD_PREPROCESSOR_MESSAGE_HPP_INCLUDED
#define GUARD_PREPROCESSOR_MESSAGE_HPP_INCLUDED

#include <evipp/config/compiler.hpp>

#if defined(EVIPP_COMPILER_MSVC)
#define EVIPP_MESSAGE(x) message("")
#else
#error "Please set up a way to print a message to the compiler output"
#endif

#endif //GUARD_PREPROCESSOR_MESSAGE_HPP_INCLUDED

