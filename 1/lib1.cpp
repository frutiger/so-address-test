#include <lib1.h>

#include <factory.h>

void ObjectOne_print()
{
    printAddress("lib1 value  ", Factory::get());
    printAddress("lib1 address", &Factory::get);
}

