
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

    ~RealImage() override {
        std::cout << "Destroying " << filename_ << '\n';
    }
};

// Virtual Proxy
class ImageProxy : public Image {
private:
    std::string filename_;
    std::unique_ptr<RealImage> image_;

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

// Demonstrates shared_ptr and weak_ptr
class ImageCache {
private:
    std::shared_ptr<RealImage> image_;

public:
    explicit ImageCache(const std::string& filename)
        : image_(std::make_shared<RealImage>(filename)) {}

    std::shared_ptr<RealImage> getImage() const {
        return image_;
    }
};

int main() {
    std::cout << "=== UNIQUE POINTER: VIRTUAL PROXY ===\n";

    {
        std::unique_ptr<Image> image =
            std::make_unique<ImageProxy>("photo.jpg");

        std::cout << "Proxy created.\n";

        image->display();

        std::cout << "\nDisplaying again:\n";
        image->display();

        std::cout << "\nLeaving scope...\n";
    }

    std::cout << "\n=== SHARED POINTER ===\n";

    std::weak_ptr<RealImage> observer;

    {
        ImageCache cache("shared-photo.jpg");

        std::shared_ptr<RealImage> image1 = cache.getImage();
        std::shared_ptr<RealImage> image2 = image1;

        observer = image1;

        std::cout << "Owners: " << image1.use_count() << '\n';

        image1->display();
        image2->display();

        std::cout << "Weak pointer expired: "
                  << std::boolalpha << observer.expired() << '\n';

        std::cout << "\nLeaving shared scope...\n";
    }

    std::cout << "Weak pointer expired: "
              << observer.expired() << '\n';

    if (auto image = observer.lock()) {
        image->display();
    } else {
        std::cout << "Image no longer exists.\n";
    }

    return 0;
}
