#include <lib2.h>

#include <factory.h>

void ObjectTwo_print()
{
    printAddress("lib2 value  ", Factory::get());
    printAddress("lib2 address", &Factory::get);
}

