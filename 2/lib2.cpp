#include <lib2.h>

#include <factory.h>
#include <bslma_sharedptrrep.h>

void ObjectTwo::print()
{
    Factory::print();
    Factory::printAddress(&BloombergLP::bslma::SharedPtrRep::managedPtrDeleter);
}

