#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> findOriginalArray(std::vector<int>& changed) {
    std::unordered_set<int> seen;
    std::sort(changed.begin(), changed.end());

    std::vector<int> original;

    for (int num : changed) {
        if (seen.count(num / 2)) {
            seen.erase(num / 2);
            original.push_back(num / 2);
        } else {
            seen.insert(num);
        }
    }

    if (!seen.empty()) {
        return std::vector<int>(); // Return empty array if changed is not a doubled array
    }

    return original;
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};
    std::vector<int> original = findOriginalArray(changed);

    if (original.empty()) {
        std::cout << "Empty array: changed is not a doubled array" << std::endl;
    } else {
        std::cout << "Original array:";
        for (int num : original) {
            std::cout << " " << num;
        }
        std::cout << std::endl;
    }

    return 0;
}
