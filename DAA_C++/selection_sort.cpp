#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum is the first element of the unsorted part
        int minIndex = i;
        
        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    
    std::cout << "Original array: ";
    printArray(arr);
    
    selectionSort(arr);
    
    std::cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}