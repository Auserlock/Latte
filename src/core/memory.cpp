#include "core/memory.hpp"

std::size_t latte::MemAllocator::round_align(const std::size_t n) const
{
    if (align < 2)
        return n;
    return ((n + align - 1) / align) * align;
}
