#include <lib2.h>

#include <factory.h>

void ObjectTwo::print()
{
    Value value = Factory::make();
    Factory::printAddress("lib2   ", value.d_function);
}

