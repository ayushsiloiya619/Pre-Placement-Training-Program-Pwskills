#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findErrorNums(std::vector<int>& nums) {
    std::vector<int> result(2, 0);
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int index = std::abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result[0] = std::abs(nums[i]);
        } else {
            nums[index] *= -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result[1] = i + 1;
            break;
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 4};

    std::vector<int> result = findErrorNums(nums);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
