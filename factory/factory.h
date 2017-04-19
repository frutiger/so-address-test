#ifndef INCLUDED_FACTORY
#define INCLUDED_FACTORY

#ifndef INCLUDED_CSTDIO
#include <cstdio>
#define INCLUDED_CSTDIO
#endif

#ifndef INCLUDED_CSTDDEF
#include <cstddef>
#define INCLUDED_CSTDDEF
#endif

struct Factory {
    Factory();
    static Factory *get();
};

template <class T>
void printAddress(const char *label, const T& value)
{
    std::printf("%s: 0x%016lx\n", label, (std::ptrdiff_t)(value));
}

#endif

