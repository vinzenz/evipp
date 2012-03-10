#ifndef GUARD_EVIPP_PREPROCESSOR_MESSAGE_HPP_INCLUDED
#define GUARD_EVIPP_PREPROCESSOR_MESSAGE_HPP_INCLUDED

#include <evipp/preprocessor/pragma.hpp>
#include <evipp/preprocessor/stringize.hpp>

#define EVIPP_LINE EVIPP_STRINGIZE(__LINE__)
#define EVIPP_LOCATION "[" __FILE__ ":" EVIPP_LINE "] MSG: "
#define EVIPP_FILE_LINE_STRING(x) EVIPP_LOCATION##x

#define EVIPP_MESSAGE(x) EVIPP_PRAGMA(message (EVIPP_FILE_LINE_STRING(x)))

#endif //GUARD_EVIPP_PREPROCESSOR_MESSAGE_HPP_INCLUDED

