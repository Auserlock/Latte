#ifndef CORE_EXCEPT_HPP
#define CORE_EXCEPT_HPP

#include <stdexcept>

namespace latte
{
    class out_of_memory final : public std::runtime_error {
    public:
        explicit out_of_memory(const std::string& what_arg) : runtime_error(what_arg) {}
    };


}

#endif
