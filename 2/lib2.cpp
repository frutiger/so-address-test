#include <lib2.h>

#include <factory.h>

void ObjectTwo::print()
{
    printAddress("lib2", &Factory::noop);
}

extern "C" void ObjectTwo_print()
{
    ObjectTwo::print();
}

