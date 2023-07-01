#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int index = std::abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        } else {
            result.push_back(index + 1);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    std::vector<int> result = findDuplicates(nums);

    std::cout << "Integers that appear twice: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
