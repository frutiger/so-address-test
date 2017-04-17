#ifndef INCLUDED_FACTORY
#define INCLUDED_FACTORY

#ifndef INCLUDED_BSL_IOMANIP
#include <bsl_iomanip.h>
#endif

#ifndef INCLUDED_BSL_IOSTREAM
#include <bsl_iostream.h>
#endif

struct Factory
{
    static void print();

    template <class TYPE>
    static void printAddress(const TYPE& value);
};

template <class TYPE>
void Factory::printAddress(const TYPE& value)
{
    auto asBuffer = reinterpret_cast<const unsigned char *>(&value);
    for (int i = sizeof(size_t) - 1; i >= 0; --i) {
        bsl::cout << bsl::setw(2) << bsl::setfill('0') << bsl::hex
                  << static_cast<int>(asBuffer[i]);
    }
    bsl::cout << '\n';
}

#endif

