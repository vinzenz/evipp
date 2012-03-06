#ifndef GUARD_STRING_DETAIL_TYPE_HPP_INCLUDED
#define GUARD_STRING_DETAIL_TYPE_HPP_INCLUDED

#include <evipp/string/size_type.hpp>

#include <vector>
#include <memory>

#include <boost/operators.hpp>

namespace evipp {
namespace string {
namespace detail {

template< typename T >
bool operator==( T const &, T const & );

/// @brief Implementation of the basic string class template
///
/// @tparam CharType	type to be used as character element
/// @tparam CharTraits  character traits to be used as implementation for the string class
template< 
	typename CharType,
	typename CharTraits // = evipp::string::detail::traits<CharType>
>
class type 
	// will implement operators <, != for us
	: boost::totally_ordered<
		type<
			CharType, 
			CharTraits
		>, 
		type<
			CharType, 
			CharTraits 
		> 
	> 
{
public:
	
	/// @brief string traits
	typedef CharTraits			traits;
	/// @brief character type
	typedef CharType			char_type;
	/// @brief string value representation type
	typedef char_type const *	const_pointer;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:
	static char_type empty_string[1];
private:
	struct data {
		data( 
			const_pointer value_, 
			size_type length );

		std::vector<char_type> value;
		size_type const character_count;

		void check_null_extend();
	};
	std::shared_ptr<data const> value_;
#endif // DOXYGEN_SHOULD_SKIP_THIS

public:
	
	/// @brief Default constructor
	type();

   
	/// @brief Constructor
	///
	/// @param value	pointer to a string which does not need to be null terminated
	/// @param length   length of the buffer in elements
	type( 
		const_pointer value, 
		string::size_type length );

	/// @brief Constructor
	///
	/// @param value	pointer to a null terminated string
	type( 
		const_pointer value );
	
	/// @brief Copy constructor
	///
	/// @param other The object to be copied
	type( 
		type const & other );
	
	/// @brief Combine constructor
	///
	/// By using this constructor you can initialize 
	/// this string as combination of two strings
	///
	/// @param lhs  string where rhs gets appended to
	/// @param rhs  string which will be appended to lhs
	type( 
		type const & lhs, 
		type const & rhs );

	/// @brief Move constructor
	type( 
		type && other );

	/// @brief assignment operator
	///
	/// @param o	object to be copied
	///
	/// @return	 *this
	type &  
		operator=(
			type o);
	
	
	/// @brief returns the number of characters in the string (Note: it's not necessarily the count of elements)
	///
	/// @return number of characters in the string
	size_type
		character_count() const;

	/// @brief 
	///
	/// @return 
	size_type 
		size() const;
		
	/// @brief returns a zero terminated sequence of characters
	///
	///	Example: if char_type is char and the string is empty it would return an equivalent to ""
	///
	/// @return zero terminated sequence of characters
	const_pointer
		c_str() const;


	/// @brief returns true if the string is empty
	///
	/// @return true if the string is empty
	bool 
		empty() const;

	/// @brief equality operator
	bool 
	operator == (
			type<CharType, CharTraits> const & rhs ) const;

	/// @brief less than operator
	bool
		operator < (
			type<CharType, CharTraits> const & rhs ) const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:	
	
	/// @brief strlen for this class
	///
	/// @param value a pointer to a zero terminated sequence of char_type
	///
	/// @return size in elements
	static 
	size_type 
		len( 
			const_pointer value );
	
	
	/// @brief Combines two strings
	///
	/// @param lhs	the string which will be on the left
	/// @param rhs	the string which will be on the right
	///
	/// @return combined string in internal representation
	static
	std::shared_ptr<data>
		combine( 
			data const & lhs, 
			data const & rhs 
		);

	
	/// @brief Converts from a source encoding to the target encoding
	///
	/// @tparam OtherType 	type with different type traits
	/// @param other		an instance of OtherType to convert from
	template< 
		typename OtherType
	>
	static 
	void
		convert(
			OtherType const & other );
#endif //DOXYGEN_SHOULD_SKIP_THIS
};

}}}

#endif //GUARD_STRING_DETAIL_TYPE_HPP_INCLUDED

