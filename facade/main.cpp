
#include <iostream>
#include <string>

// Subsystem
class VideoFile {
public:
    explicit VideoFile(const std::string& filename)
        : filename_(filename) {}

    std::string name() const {
        return filename_;
    }

private:
    std::string filename_;
};

// Subsystem
class VideoDecoder {
public:
    void decode(const VideoFile& file) {
        std::cout << "Decoding " << file.name() << '\n';
    }
};

// Subsystem
class VideoProcessor {
public:
    void process() {
        std::cout << "Processing video frames\n";
    }
};

// Subsystem
class AudioProcessor {
public:
    void process() {
        std::cout << "Processing audio\n";
    }
};

// Subsystem
class VideoEncoder {
public:
    void encode(const std::string& output) {
        std::cout << "Encoding video to " << output << '\n';
    }
};

// Facade
class VideoConverter {
public:
    void convert(const std::string& filename) {
        VideoFile file(filename);

        decoder_.decode(file);
        videoProcessor_.process();
        audioProcessor_.process();
        encoder_.encode("converted_" + filename);
    }

private:
    VideoDecoder decoder_;
    VideoProcessor videoProcessor_;
    AudioProcessor audioProcessor_;
    VideoEncoder encoder_;
};

int main() {
    VideoConverter converter;

    converter.convert("movie.mp4");

    return 0;
}
