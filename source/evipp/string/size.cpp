#include <evipp/string/size.hpp>

namespace evipp {
namespace string {

evipp::string::size_type const &
size(
	evipp::string::type const & object)
{
	return object.size();
}

}}

