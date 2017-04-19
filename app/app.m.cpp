#include <dlfcn.h>
#include <iostream>

int main()
{
    void *one = dlopen("1/lib1.so", RTLD_LAZY | RTLD_GLOBAL);
    void *onePrint = dlsym(one, "ObjectOne_print");
    void *two = dlopen("2/lib2.so", RTLD_LAZY | RTLD_GLOBAL);
    void *twoPrint = dlsym(two, "ObjectTwo_print");
    reinterpret_cast<void (*)()>(onePrint)();
    reinterpret_cast<void (*)()>(twoPrint)();
    dlclose(one);
    dlclose(two);
}
