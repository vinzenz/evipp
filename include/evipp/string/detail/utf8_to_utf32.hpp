#ifndef GUARD_STRING_DETAIL_UTF8_TO_UTF32_HPP_INCLUDED
#define GUARD_STRING_DETAIL_UTF8_TO_UTF32_HPP_INCLUDED

#include <evipp/string/utf8/char_type.hpp>
#include <evipp/string/utf32/char_type.hpp>
#include <evipp/string/size_type.hpp>

namespace evipp {
namespace string {
namespace detail {

class utf8_to_utf32 {
public:
	typedef evipp::string::utf8::char_type	utf8_t;
	typedef utf8_t const *					utf8_constpointer;
	typedef evipp::string::utf32::char_type	utf32_t;
	typedef utf32_t const *					utf32_constpointer;
	typedef evipp::string::size_type		size_type;
private:
	utf8_constpointer begin_;
	utf8_constpointer current_;
	utf8_constpointer end_;
public:
	utf8_to_utf32( 
		utf8_constpointer begin, 
		utf8_constpointer end );

	bool end() const;
	utf32_t next();

	static 
	size_type 
		character_count( 
			utf8_constpointer value, 
			size_type element_count );
};

}}}

#endif // GUARD_STRING_DETAIL_UTF8_TO_UTF32_HPP_INCLUDED
