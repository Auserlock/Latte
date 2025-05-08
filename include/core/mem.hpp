#ifndef __CORE_MEM_HPP__
#define __CORE_MEM_HPP__

#include <vector>

namespace latte
{
    struct MemAllocator {
        explicit MemAllocator(const int &align) : align{align} {}
        MemAllocator(const MemAllocator &) = delete;
        MemAllocator &operator=(const MemAllocator &) = delete;
        virtual ~MemAllocator() = default;
        virtual void *malloc(size_t size) = 0;
        virtual void free(void *ptr) = 0;
        virtual void init(void *ptr, size_t size) = 0;

        inline size_t round_up_align(size_t size) const
        {
            if (align < 2)
                return size;
            return (size + align - 1) & ~(align - 1);
        }

        const int align;
    };

    struct CPUAllocator : public MemAllocator {
        explicit CPUAllocator(const int &align = 32) : MemAllocator(align) {}
        void *malloc(size_t size) override;
        void free(void *ptr) override;
        void init(void *ptr, size_t size) override;
    };

    struct SharedAllocator : public MemAllocator {
        explicit SharedAllocator(const int &align = 32) : MemAllocator(align) {}
        void *malloc(size_t size) override;
        void free(void *ptr) override;
        void init(void *ptr, size_t size) override;
    };
} // namespace latte

#endif
