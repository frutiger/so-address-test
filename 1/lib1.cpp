#include <lib1.h>

#include <factory.h>

void ObjectOne::print()
{
    Value value = Factory::make();
    Factory::printAddress("lib1   ", value.d_function);
}

