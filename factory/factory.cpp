#include <factory.h>

Factory::Factory()
{
    printf("Hello world\n");
}

Factory *Factory::get()
{
    static Factory *factory = nullptr;
    if (!factory) {
        static Factory factoryInstance;
        factory = &factoryInstance;
    }
    return factory;
}

