#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end()); // Sort the array in ascending order

    std::vector<std::vector<int>> result;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicate elements
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    std::vector<std::vector<int>> result = fourSum(nums, target);

    std::cout << "Output: ";
    for (const auto& quadruplet : result) {
        std::cout << "[";
        for (int i = 0; i < 4; i++) {
            std::cout << quadruplet[i];
            if (i != 3)
                std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}
