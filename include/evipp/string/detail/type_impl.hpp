#ifndef GUARD_STRING_DETAIL_TYPE_IMPL_HPP_INCLUDED
#define GUARD_STRING_DETAIL_TYPE_IMPL_HPP_INCLUDED

#include <boost/tr1/memory.hpp>
#include <cassert>

namespace evipp {
namespace string {
namespace detail {

template<
	typename CharType,
	typename CharTraits
>
typename type<
	CharType, 
	CharTraits 
>::char_type 
type<
	CharType, 
	CharTraits 
>::empty_string[1] = {};

template<
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits 
>::data::data( 
	const_pointer _value, 
	size_type _length 
)
: value( 
	_value, 
	_value + _length )
, character_count(
	CharTraits::character_count(
		value.data(), 
		value.size() ) )
{
	check_null_extend();
}

template<
	typename CharType,
	typename CharTraits
>
void
type<
	CharType, 
	CharTraits 
>::data::check_null_extend()
{
	value.push_back( 0 );
}

template<
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits
>::type()
	: value_()
{
}

template<
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits
>::type( 
	const_pointer value, 
	string::size_type length )
	: value_( 
		std::make_shared<data>(
			value, 
			length ) )
{

}

template<
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits
>::type( 
	const_pointer value)
	: value_( 
		std::make_shared<data>(
			value, 
			type::len( 
				value ) ) )
{

}

template<
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits
>::type( 
	type const & other )
	: value_(
		other.value_
	)
{

}

template<
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits
>::type( 
	type const & lhs, 
	type const & rhs )
	: value_()
{

}

template< 
	typename CharType,
	typename CharTraits
>
type<
	CharType, 
	CharTraits
>::type( 
	type && other )
	: value_( other.value_ )
{

}

template<
	typename CharType,
	typename CharTraits
>
type< 
	CharType, 
	CharTraits 
> &
type< 
	CharType, 
	CharTraits 
>::operator=(
	type other )
{
	value_.swap( other.value_ );
	return *this;
}

template<
	typename CharType,
	typename CharTraits
>
type< 
	CharType, 
	CharTraits 
> &
type< 
	CharType, 
	CharTraits 
>::operator=(
	const_pointer value )
{
	return operator=( 
		std::move( 
			type( 
				value ) ) );
}


template<
	typename CharType,
	typename CharTraits
>
size_type 
type<
	CharType, 
	CharTraits
>::character_count() const
{
	if( empty() )
	{
		return 0;
	}
	return value_->character_count;
}

template<
	typename CharType,
	typename CharTraits
>
size_type 
type<
	CharType, 
	CharTraits
>::size() const
{
	if( value_.use_count() == 0 )
	{
		return 0;
	}

	// This must be minimum 1
	assert( value_->value.size() > 0 );

	if( value_->value.size() )
	{
		return value_->value.size() - 1;
	}

	return 0;
}

template< 
	typename CharType,
	typename CharTraits
>
bool
type<
	CharType, 
	CharTraits
>::empty() const
{
	return size() == 0;
}


template<
	typename CharType,
	typename CharTraits
>
auto
type<
	CharType, 
	CharTraits
>::c_str() const 
-> const_pointer
{
	if( empty() )
	{
			return empty_string;
	}
	return value_->value.data();
}

template<
	typename CharType,
	typename CharTraits
>
bool
type<
	CharType, 
	CharTraits
>::operator == (	
	type const & rhs ) const
{
	if ( empty() ) 
	{
		// In case rhs is empty both must be empty here
		return rhs.empty();
	}

	// If rhs is empty here they cannot be equal
	if ( rhs.empty() )
	{
		return false;
	}

	// Precondition: rhs and lhs are not empty
	// if lhs or rhs is empty this would cause a crash
	assert( 
			!empty() 
		&& 	!rhs.empty() );

	return CharTraits::compare(
		value_->value.data(),
		value_->value.size(),
		rhs.value_->value.data(),
		rhs.value_->value.size() ) == 0;
}

template<
	typename CharType,
	typename CharTraits
>
bool
type<
	CharType, 
	CharTraits
>::operator < (
	type const & rhs ) const
{
	if ( empty() )
	{
		// If lhs is empty and rhs is not lhs < rhs == true
		return !rhs.empty();
	}
	
	// If rhs is empty and lhs is not lhs < rhs == false
	if ( rhs.empty() )
	{
		return false;
	}

	// Precondition: rhs and lhs are not empty
	// if lhs or rhs is empty this would cause a crash
	assert( 
			!empty() 
		&& 	!rhs.empty() );

	return CharTraits::compare(
		value_->value.data(),
		value_->value.size(),
		rhs.value_->value.data(),
		rhs.value_->value.size() ) == 1;
}
	
template<
	typename CharType,
	typename CharTraits
>
size_type
type<
	CharType, 
	CharTraits
>::len( 
	const_pointer value )
{
	return traits::len( 
		value );
}

template<
	typename CharType,
	typename CharTraits
>
std::shared_ptr<
	typename type<
		CharType,
		CharTraits
	>::data
>
type<
	CharType, 
	CharTraits
>::combine( 
	data const & lhs, 
	data const & rhs
)
{
	return std::make_shared<
		data>( 
			traits::combine( 
				lhs.value, 
				rhs.value ) );
}

template< 
	typename CharType,
	typename CharTraits
>
template< 
	typename OtherType
>
void
type<
	CharType,
	CharTraits
>::convert(
	OtherType const & other )
{
	if( other.empty() )
	{
		return type();
	}
	
	return CharTraits::template convert< 
		type >(
			other );
}

}}}

#endif //GUARD_STRING_DETAIL_TYPE_IMPL_HPP_INCLUDED
