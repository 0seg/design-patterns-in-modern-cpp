#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;

    virtual std::string name() const = 0;
    virtual std::size_t size() const = 0;
};

class File : public FileSystemComponent {
private:
    std::string name_;
    std::size_t size_;

public:
    File(const std::string& name, std::size_t size);

    std::string name() const override;
    std::size_t size() const override;
};

class Folder : public FileSystemComponent {
private:
    std::string name_;
    std::vector<std::unique_ptr<FileSystemComponent>> children_;

public:
    Folder(const std::string& name);

    std::string name() const override;
    std::size_t size() const override;

    void add(std::unique_ptr<FileSystemComponent> component);
};