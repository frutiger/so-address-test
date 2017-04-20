#ifndef _WIN32
#include <dlfcn.h>
#else
#include <windows.h>
#endif

int main()
{
#ifndef _WIN32
    void *one = dlopen("1/lib1.so", RTLD_LAZY | RTLD_GLOBAL);
    void *two = dlopen("2/lib2.so", RTLD_LAZY | RTLD_GLOBAL);
    reinterpret_cast<void (*)()>(dlsym(one, "ObjectOne_print"))();
    reinterpret_cast<void (*)()>(dlsym(two, "ObjectTwo_print"))();
    dlclose(one);
    dlclose(two);
#else
    HMODULE one = ::LoadLibrary("1/lib1.dll");
    HMODULE two = ::LoadLibrary("2/lib2.dll");
    reinterpret_cast<void (*)()>(::GetProcAddress(one, "ObjectOne_print"))();
    reinterpret_cast<void (*)()>(::GetProcAddress(two, "ObjectTwo_print"))();
    ::FreeLibrary(one);
    ::FreeLibrary(two);
#endif
}
