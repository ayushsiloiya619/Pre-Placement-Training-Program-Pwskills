#include <iostream>
#include <vector>

std::vector<int> shuffleArray(std::vector<int>& nums, int n) {
    std::vector<int> result;
    result.reserve(nums.size());

    for (int i = 0; i < n; i++) {
        result.push_back(nums[i]);
        result.push_back(nums[n + i]);
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    std::vector<int> shuffled = shuffleArray(nums, n);

    std::cout << "Shuffled array: ";
    for (int num : shuffled) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
