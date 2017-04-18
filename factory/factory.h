#ifndef INCLUDED_FACTORY
#define INCLUDED_FACTORY

#ifndef INCLUDED_IOMANIP
#include <iomanip>
#endif

#ifndef INCLUDED_IOSTREAM
#include <iostream>
#endif

struct Value
{
    typedef void (*Function)();
    Function d_function;
    virtual int constant();
};

struct Value2 : Value
{
    int constant() override;
};

struct Factory
{
    static Value *make();
    static void noop();

    template <class TYPE>
    static void printAddress(const char *label, const TYPE& value);
};

template <class TYPE>
void Factory::printAddress(const char *label, const TYPE& value)
{
    std::cout << label << ": ";
    auto asBuffer = reinterpret_cast<const unsigned char *>(&value);
    for (int i = sizeof(size_t) - 1; i >= 0; --i) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex
                  << static_cast<int>(asBuffer[i]);
    }
    std::cout << '\n';
}

#endif

