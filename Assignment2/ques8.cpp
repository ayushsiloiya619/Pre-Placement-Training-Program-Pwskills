#include <iostream>
#include <vector>
#include <algorithm>

int minimumScore(std::vector<int>& nums, int k) {
    int n = nums.size();
    int minNum = *std::min_element(nums.begin(), nums.end());
    int maxNum = *std::max_element(nums.begin(), nums.end());

    if (maxNum - minNum <= 2 * k) {
        return 0;
    }

    int option1 = maxNum - k - (minNum + k);
    int option2 = maxNum - (minNum - k + k);

    return std::min(option1, option2);
}

int main() {
    std::vector<int> nums = {1};
    int k = 0;

    int result = minimumScore(nums, k);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
