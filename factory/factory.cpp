#include <factory.h>

#include <bslma_sharedptrrep.h>

void Factory::print()
{
    printAddress(&BloombergLP::bslma::SharedPtrRep::managedPtrDeleter);
}
