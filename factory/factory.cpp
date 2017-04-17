#include <factory.h>

Value Factory::make()
{
    Value result;
    result.d_function = &Factory::noop;
    printAddress("factory address", &Factory::noop);
    printAddress("factory value  ", result.d_function);
}

void Factory::noop()
{
}
