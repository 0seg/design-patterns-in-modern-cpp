#include "file_system.hpp"

#include <utility>

// File

File::File(const std::string& name, std::size_t size)
    : name_(name), size_(size) {}

std::string File::name() const {
    return name_;
}

std::size_t File::size() const {
    return size_;
}

// Folder

Folder::Folder(const std::string& name)
    : name_(name) {}

std::string Folder::name() const {
    return name_;
}

std::size_t Folder::size() const {
    std::size_t total = 0;

    for (const auto& child : children_) {
        total += child->size();
    }

    return total;
}

void Folder::add(std::unique_ptr<FileSystemComponent> component) {
    children_.push_back(std::move(component));
}