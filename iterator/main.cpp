#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstddef>


template <typename T>
class Iterator {
private:
    const std::vector<T>& collection;
    std::size_t position = 0;

public:
    explicit Iterator(const std::vector<T>& data)
        : collection(data) {}

    bool hasNext() const {
        return position < collection.size();
    }

    const T& next() {
        if (!hasNext()) {
            throw std::out_of_range("No more elements");
        }

        return collection[position++];
    }
};



int main() {

    // Integer collection
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    Iterator<int> intIterator(numbers);

    std::cout << "Integer collection:\n";

    while (intIterator.hasNext()) {
        std::cout << intIterator.next() << '\n';
    }

    // String collection
    std::vector<std::string> names = {
        "Alice", "Bob", "Charlie", "David"
    };

    Iterator<std::string> stringIterator(names);

    std::cout << "\nString collection:\n";

    while (stringIterator.hasNext()) {
        std::cout << stringIterator.next() << '\n';
    }

    return 0;
}
