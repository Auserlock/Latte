#include <core/except.hpp>
#include <core/mem.hpp>

#include <mm_malloc.h>

#include <cstring>
#include <format>
#include <iostream>

namespace latte
{
    void *CPUAllocator::malloc(size_t size)
    {
        void *ptr = _mm_malloc(size, align);
        if (!ptr) {
            std::cerr << std::format("CPU Memory allocation failded: size={}, align={}", size, align) << std::endl;
            throw latte::out_of_memory("CPU Memory allocation failed");
        }
        return ptr;
    }

    void CPUAllocator::free(void *ptr)
    {
        if (ptr) {
            _mm_free(ptr);
        }
    }

    void CPUAllocator::init(void *ptr, size_t size) { memset(ptr, 0, size); }

    void *SharedAllocator::malloc(size_t size)
    {
        // !TODO: Implement shared memory allocation
    }
} // namespace latte
