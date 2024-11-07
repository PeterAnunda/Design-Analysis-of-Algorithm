#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void analyzeSearchPerformance() {
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; ++i) {
        arr[i] = i;
    }

    // Measure best-case scenario
    auto start = std::chrono::high_resolution_clock::now();
    binarySearch(arr, arr[arr.size() / 2]);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Best case time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds" << std::endl;

    // Measure worst-case scenario (target not present)
    start = std::chrono::high_resolution_clock::now();
    binarySearch(arr, -1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Worst case time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds" << std::endl;

    // Measure average-case scenario (random target)
    start = std::chrono::high_resolution_clock::now();
    binarySearch(arr, arr[arr.size() / 3]);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Average case time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds" << std::endl;
}

int main() {
    analyzeSearchPerformance();
    return 0;
}
