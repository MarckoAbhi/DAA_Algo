#include <iostream>
#include <vector>
#include <limits> 

void findMinMax(const std::vector<int>& arr, int& min, int& max) {
    min = std::numeric_limits<int>::max();
    max = std::numeric_limits<int>::min();

    for (int num : arr) {
        if (num < min) {
            min = num; 
        }
        if (num > max) {
            max = num; 
        }
    }
}

int main() {
    std::vector<int> arr = {12, 3, 5, 7, 19, -1, 0};

    int min, max;
    findMinMax(arr, min, max);

    std::cout << "Minimum value: " << min << std::endl;
    std::cout << "Maximum value: " << max << std::endl;

    return 0;
}