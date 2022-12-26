#include "v8.h"

#include "./src/wd.hpp"

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    auto *wd = new Wd();
    std::unique_ptr<v8::Platform> platform =
        wd->initializeV8(argc, argv);

    wd->initializeVM();
    wd->InitializeProgram(filename);
    wd->Shutdown();

    return 0;
}