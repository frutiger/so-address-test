#include <factory.h>

int Value::constant()
{
    return -1;
}

int Value2::constant()
{
    return -42;
}

Value *Factory::make()
{
    Value2 *result = new Value2;
    result->d_function = &Factory::noop;
    printAddress("factory address", &Factory::noop);
    printAddress("factory value  ", result->d_function);
    return result;
}

void Factory::noop()
{
}
