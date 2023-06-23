#include <iostream>
#include <vector>
#include <algorithm>

int maximumProduct(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int size = nums.size();

    // Case 1: product of three largest numbers
    int product1 = nums[size - 1] * nums[size - 2] * nums[size - 3];

    // Case 2: product of two smallest negative numbers and the largest positive number
    int product2 = nums[0] * nums[1] * nums[size - 1];

    return std::max(product1, product2);
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    int result = maximumProduct(nums);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
