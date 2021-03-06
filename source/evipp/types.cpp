// Soley purpose of this file is to ensure that all types headers are compilable

// Signed types
#include <evipp/types/int8.hpp>
#include <evipp/types/int16.hpp>
#include <evipp/types/int32.hpp>
#include <evipp/types/int64.hpp>

// Unsigned types
#include <evipp/types/uint8.hpp>
#include <evipp/types/uint16.hpp>
#include <evipp/types/uint32.hpp>
#include <evipp/types/uint64.hpp>

#include <evipp/types/byte.hpp>
#include <evipp/types/word.hpp>
#include <evipp/types/dword.hpp>
#include <evipp/types/qword.hpp>

// Other types
#include <evipp/types/size_type.hpp>
#include <evipp/types/char_type.hpp>

#include <evipp/algorithm/append.hpp>
#include <evipp/string/detail/type.hpp>
#include <evipp/string/detail/type_impl.hpp>

struct test_traits 
{
	static 
	size_t 
		len( 
			wchar_t const * value );
	
	template< 
		typename Container 
	>
	static
	Container
		combine( 
			Container const & lhs,
			Container const & rhs );

	template<
		typename TargetContainer,
		typename SourceContainer
	>
	static 
	TargetContainer
		convert(
			SourceContainer const & source );
	
	static
	size_t
		character_count(
		wchar_t const * value,
		size_t count );

	static
	int
		compare(
			wchar_t const * lhs,
			size_t lhs_count,
			wchar_t const * rhs,
			size_t rhs_count
		);
};

inline
size_t
test_traits::len( 
	wchar_t const * value )
{
	return std::wcslen( value );
}

template<
	typename Container
>
inline
Container
test_traits::combine( 
	Container const & lhs, 
	Container const & rhs )
{
	Container result((lhs));
	
	result.pop_back();
	
	evipp::algorithm::append(
		result, 
		rhs);
	
	return std::move( result );
}

template<
	typename TargetContainer,
	typename SourceContainer
>
inline
TargetContainer
	test_traits::convert(
		SourceContainer const & source )
{
	return TargetContainer();
}

inline
size_t
	test_traits::character_count(
	wchar_t const *,
	size_t count )
{
	return count;
}

inline
int
	test_traits::compare(
		wchar_t const * lhs,
		size_t lhs_count,
		wchar_t const * rhs,
		size_t rhs_count
	)
{
	return std::wcscmp( lhs, rhs );
}

void test()
{
	typedef
	evipp::string::detail::type< 
		wchar_t, 
		test_traits >
		str;

	str test_value(L"test_value");
	str other_value(L"other_value");
	str length_known_value(L"length_known_value", 18);
	str appended(test_value, other_value);
	str move_source(L"move_source");
	str moved_target = std::move(move_source);

	size_t char_count = test_value.character_count();
	size_t buffer_size = test_value.size();
	bool empty = test_value.empty();
	wchar_t const * value = test_value.c_str();

	test_value == test_value;
	test_value != other_value;
	test_value > other_value;
	test_value >= other_value;
}
