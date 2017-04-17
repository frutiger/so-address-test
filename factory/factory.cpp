#include <factory.h>

Value Factory::make()
{
    Value result;
    result.d_function = &Factory::noop;
    printAddress("factory", result.d_function);
}

void Factory::noop()
{
}
