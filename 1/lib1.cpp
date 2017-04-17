#include <lib1.h>

#include <factory.h>
#include <bslma_sharedptrrep.h>

void ObjectOne::print()
{
    Factory::print();
    Factory::printAddress(&BloombergLP::bslma::SharedPtrRep::managedPtrDeleter);
}

