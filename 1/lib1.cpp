#include <lib1.h>

#include <factory.h>

void ObjectOne::print()
{
    Value value = Factory::make();
    Factory::printAddress("lib1 address   ", &Factory::noop);
    Factory::printAddress("lib1 value     ", value.d_function);
}

