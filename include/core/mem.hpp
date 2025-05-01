#ifndef LATTE_MEM_HPP
#define LATTE_MEM_HPP

#include <vector>

namespace latte
{
    class MemAllocator {
    public:
        explicit MemAllocator(const int align):
            align{align}
        {
        }

    private:
        const int align;
    };
}

#endif
