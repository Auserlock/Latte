#ifndef CORE_MEMORY_HPP
#define CORE_MEMORY_HPP

#include <cstddef>

namespace latte
{
    class MemAllocator {
    public:
        explicit MemAllocator(const int align) : align(align) {}
        MemAllocator &operator=(const MemAllocator &) = delete;
        MemAllocator(const MemAllocator &) = delete;
        virtual ~MemAllocator() = default;
        virtual void *alloc(std::size_t n) = 0;
        virtual void free(void *mem) = 0;
        virtual void zero(void *p, std::size_t n) = 0;
        [[nodiscard]] inline std::size_t round_align(std::size_t n) const;

    private:
        const int align;
    };

    class CPUAllocator final : public MemAllocator {
    public:
        CPUAllocator() : MemAllocator(64) {}
        void *alloc(std::size_t n) override;
        void free(void *mem) override;
        void zero(void *p, std::size_t n) override;
    };

    class SharedAllocator final : public MemAllocator {
    public:
        SharedAllocator() : MemAllocator(64) {}
        void *alloc(std::size_t n) override;
        void free(void *mem) override;
        void zero(void *p, std::size_t n) override;
    };

#if USE_DEVICE
    class GPUAllocator final : public MemAllocator {
    public:
        GPUAllocator() : MemAllocator(256) {}
        void *alloc(std::size_t n) override;
        void free(void *mem) override;
        void zero(void *p, std::size_t n) override;
    };
#endif
} // namespace latte

#endif
