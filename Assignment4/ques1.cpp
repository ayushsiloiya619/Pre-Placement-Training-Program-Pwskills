#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> commonElements(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
    std::unordered_set<int> set1(arr1.begin(), arr1.end());
    std::unordered_set<int> set2(arr2.begin(), arr2.end());
    std::vector<int> result;

    for (int num : arr3) {
        if (set1.count(num) && set2.count(num)) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {1, 2, 5, 7, 9};
    std::vector<int> arr3 = {1, 3, 4, 5, 8};

    std::vector<int> common = commonElements(arr1, arr2, arr3);

    std::cout << "Common elements: ";
    for (int num : common) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
