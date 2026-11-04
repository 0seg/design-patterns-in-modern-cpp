
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

// Target: interface expected by the client.
class AudioPlayer {
public:
    virtual void play(const std::string& filename) = 0;
    virtual ~AudioPlayer() = default;
};

// Adaptee: external library with an incompatible interface.
class LegacyAudioLibrary {
public:
    std::string playAudioFile(const std::string& filename) {
        std::cout << "Loading audio file: " << filename << '\n';

        return "Audio data from " + filename;
    }
};

// Adapter: translates the interface and caches processed files.
class AudioAdapter : public AudioPlayer {
private:
    LegacyAudioLibrary library_;
    std::unordered_map<std::string, std::string> cache_;

public:
    void play(const std::string& filename) override {
        auto it = cache_.find(filename);

        if (it == cache_.end()) {
            std::cout << "[Cache Miss] " << filename << '\n';

            std::string audioData = library_.playAudioFile(filename);

            it = cache_.emplace(filename, std::move(audioData)).first;
        } else {
            std::cout << "[Cache Hit] " << filename << '\n';
        }

        std::cout << "Playing: " << it->second << "\n\n";
    }
};

// Client: depends only on the Target interface.
void playTrack(const AudioPlayer& player, const std::string& filename) {
    const_cast<AudioPlayer&>(player).play(filename);
}

int main() {
    std::unique_ptr<AudioPlayer> player =
        std::make_unique<AudioAdapter>();

    playTrack(*player, "song.mp3");
    playTrack(*player, "music.wav");
    playTrack(*player, "song.mp3");

    return 0;
}
