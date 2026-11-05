#include "FileSystem.h"

#include <iostream>
#include <memory>
#include <utility>

int main() {
    Folder root("Root");

    root.add(std::make_unique<File>("main.cpp", 20));
    root.add(std::make_unique<File>("README.md", 10));

    auto src = std::make_unique<Folder>("src");

    src->add(std::make_unique<File>("Matrix.cpp", 30));
    src->add(std::make_unique<File>("Matrix.h", 15));

    root.add(std::move(src));

    std::cout << root.name() << " size: "
              << root.size() << " KB\n";

    return 0;
}