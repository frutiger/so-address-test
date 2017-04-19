#include <lib1.h>

#include <factory.h>

void ObjectOne::print()
{
    printAddress("lib1", &Factory::noop);
}

extern "C" void ObjectOne_print()
{
    ObjectOne::print();
}

