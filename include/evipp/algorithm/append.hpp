#ifndef GUARD_EVIPP_ALGORITHM_APPEND_HPP_INCLUDED
#define GUARD_EVIPP_ALGORITHM_APPEND_HPP_INCLUDED

namespace evipp {
namespace algorithm {

template<
	typename Container
>
Container &
append(
	Container & target,
	Container const & source )
{
	target.insert( 
		target.end(), 
		source.begin(), 
		source.end() );
	return target;
}

}}

#endif //GUARD_EVIPP_ALGORITHM_APPEND_HPP_INCLUDED

