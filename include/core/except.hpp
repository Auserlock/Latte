#ifndef __CORE_EXCEPT_HPP__
#define __CORE_EXCEPT_HPP__

#include <stdexcept>

namespace latte
{
    class out_of_memory : public std::runtime_error {
    public:
        out_of_memory(const std::string &what_arg) : runtime_error{what_arg} {}
    };
} // namespace latte

#endif
