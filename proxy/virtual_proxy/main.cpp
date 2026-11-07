
#include <iostream>
#include <memory>
#include <string>

// Subject
class Image {
public:
    virtual void display() const = 0;
    virtual ~Image() = default;
};

// RealSubject
class RealImage : public Image {
private:
    std::string filename_;

    void loadFromDisk() const {
        std::cout << "Loading " << filename_ << '\n';
    }

public:
    explicit RealImage(const std::string& filename)
        : filename_(filename) {
        loadFromDisk();
    }

    void display() const override {
        std::cout << "Displaying " << filename_ << '\n';
    }
};

// Virtual Proxy
class ImageProxy : public Image {
private:
    std::string filename_;
    mutable std::unique_ptr<RealImage> image_;

public:
    explicit ImageProxy(const std::string& filename)
        : filename_(filename) {}

    void display() const override {
        if (!image_) {
            image_ = std::make_unique<RealImage>(filename_);
        }

        image_->display();
    }
};

int main() {
    std::cout << "=== VIRTUAL PROXY ===\n\n";

    std::unique_ptr<Image> image1 =
        std::make_unique<ImageProxy>("photo1.jpg");

    std::unique_ptr<Image> image2 =
        std::make_unique<ImageProxy>("photo2.jpg");

    std::unique_ptr<Image> image3 =
        std::make_unique<ImageProxy>("photo3.jpg");

    std::cout << "Three proxies created.\n";
    std::cout << "No images loaded yet.\n";

    std::cout << "\nOpening second image:\n";
    image2->display();

    std::cout << "\nDisplaying second image again:\n";
    image2->display();

    std::cout << "\nOpening first image:\n";
    image1->display();

    std::cout << "\nOnly two images were loaded.\n";

    return 0;
}
