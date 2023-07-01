#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(std::vector<int>& changed) {
    std::vector<int> original;
    std::unordered_map<int, int> countMap;

    // Count the occurrences of each element in the changed array
    for (int num : changed) {
        countMap[num]++;
    }

    // Iterate through the changed array
    for (int num : changed) {
        // Check if the current element is divisible by 2 and its half value is present in the map
        if (num % 2 == 0 && countMap[num] > 0 && countMap[num / 2] > 0) {
            original.push_back(num / 2);
            countMap[num]--;
            countMap[num / 2]--;
        }
    }

    // If the map is empty, the changed array is a valid doubled array
    if (countMap.empty()) {
        return original;
    } else {
        return {}; // Return an empty array if the changed array is not a valid doubled array
    }
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};

    std::vector<int> original = findOriginalArray(changed);

    std::cout << "Original array: ";
    for (int num : original) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
