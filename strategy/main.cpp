
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortingStrategy() = default;
};

class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override
     {
        for (std::size_t i = 0; i < data.size(); ++i) 
        {
            for (std::size_t j = 0; j + 1 < data.size() - i; ++j) 
            {
                if (data[j] > data[j + 1]) 
                {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

class QuickSort : public SortingStrategy {
private:
    void quickSort(std::vector<int>& data, int low, int high) {
        if (low >= high) return;

        int pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (data[j] < pivot) {
                ++i;
                std::swap(data[i], data[j]);
            }
        }

        std::swap(data[i + 1], data[high]);

        int partitionIndex = i + 1;

        quickSort(data, low, partitionIndex - 1);
        quickSort(data, partitionIndex + 1, high);
    }

public:
    void sort(std::vector<int>& data) override {
        if (data.size() > 1) {
            quickSort(data, 0, static_cast<int>(data.size()) - 1);
        }
    }
};

class MergeSort : public SortingStrategy {
private:
    void merge(std::vector<int>& data, int left, int mid, int right) {
        std::vector<int> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (data[i] <= data[j]) {
                temp.push_back(data[i++]);
            } else {
                temp.push_back(data[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(data[i++]);
        }

        while (j <= right) {
            temp.push_back(data[j++]);
        }

        for (std::size_t k = 0; k < temp.size(); ++k) {
            data[left + static_cast<int>(k)] = temp[k];
        }
    }

    void mergeSort(std::vector<int>& data, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);

        merge(data, left, mid, right);
    }

public:
    void sort(std::vector<int>& data) override {
        if (data.size() > 1) {
            mergeSort(data, 0, static_cast<int>(data.size()) - 1);
        }
    }
};

class Sorter {
private:
    std::unique_ptr<SortingStrategy> strategy;

public:
    explicit Sorter(std::unique_ptr<SortingStrategy> strategy)
        : strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<SortingStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void sort(std::vector<int>& data) {
        if (!strategy) {
            std::cout << "No sorting strategy selected.\n";
            return;
        }

        strategy->sort(data);
    }
};

void printData(const std::vector<int>& data) {
    for (int value : data) {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> numbers = {9, 4, 7, 2, 8, 1, 5, 3, 6};

    Sorter sorter(std::make_unique<BubbleSort>());

    std::cout << "Original data: ";
    printData(numbers);

    std::cout << "\nUsing Bubble Sort:\n";
    sorter.sort(numbers);
    printData(numbers);

    numbers = {9, 4, 7, 2, 8, 1, 5, 3, 6};

    std::cout << "\nUsing Quick Sort:\n";
    sorter.setStrategy(std::make_unique<QuickSort>());
    sorter.sort(numbers);
    printData(numbers);

    numbers = {9, 4, 7, 2, 8, 1, 5, 3, 6};

    std::cout << "\nUsing Merge Sort:\n";
    sorter.setStrategy(std::make_unique<MergeSort>());
    sorter.sort(numbers);
    printData(numbers);

    return 0;
}
