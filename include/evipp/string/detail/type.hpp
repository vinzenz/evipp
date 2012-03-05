#ifndef GUARD_STRING_DETAIL_TYPE_HPP_INCLUDED
#define GUARD_STRING_DETAIL_TYPE_HPP_INCLUDED

#include <evipp/string/size_type.hpp>

#include <vector>
#include <memory>

#include <boost/operators.hpp>

namespace evipp {
namespace string {
namespace detail {

template< 
	typename CharType,
	typename CharTraits = evipp::string::detail::traits<CharType>
>
class type 
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
	static string::size_type const npos = ~string::size_type(0);

	typedef CharTraits			traits;
	typedef CharType			char_type;
	typedef char_type const *	const_pointer;

private:
	struct data {
		data( 
			const_pointer value_, 
			size_type length );

		std::vector<char_type const> const value;
		size_type const character_count;
	};
	std::shared_ptr<data const> value_;

public:
	type();

	type( 
		const_pointer value, 
		string::size_type length );

	type( 
		const_pointer value );
	
	type( 
		type const & other );
	
	type( 
		type const & lhs, 
		type const & rhs );

	type( 
		type && other );

	type &  
		operator=(
			type o);
	
	size_type
		character_count() const;

	size_type 
		size() const;
	const_pointer
		c_str() const;
	bool 
		empty() const;

	friend 
	bool
		operator == (
			type const & lhs,
			type const & rhs
		) 
	{
		return CharTraits::compare(
			lhs.value_->value.data(),
			lhs.value_->value.size(),
			rhs.value_->value.data(),
			rhs.value_->value.size() ) == 0;
	}	

	friend
	bool
		operator < (
			type const & lhs,
			type const & rhs )
	{
		return CharTraits::compare(
			lhs.value_->value.data(),
			lhs.value_->value.size(),
			rhs.value_->value.data(),
			rhs.value_->value.size() ) == 1;
	}
private:	
	static 
	size_type 
		len( 
			const_pointer value );
	
	static
	auto
		join( 
			data const & lhs, 
			data const & rhs 
		) -> std::shared_ptr<data>;

	template< 
		typename OtherType
	>
	static 
	void
		convert(
			OtherType const & other );
};

}}}

#endif //GUARD_STRING_DETAIL_TYPE_HPP_INCLUDED

