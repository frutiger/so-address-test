#include <dlfcn.h>
#include <iostream>

int main()
{
    void *one = dlopen("1/lib1.so", RTLD_LAZY | RTLD_GLOBAL);
    void *two = dlopen("2/lib2.so", RTLD_LAZY | RTLD_GLOBAL);
    reinterpret_cast<void (*)()>(dlsym(one, "ObjectOne_print"))();
    reinterpret_cast<void (*)()>(dlsym(two, "ObjectTwo_print"))();
    dlclose(one);
    dlclose(two);
}
