#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int index1 = -1;

    // Find the first pair of adjacent elements where nums[i] < nums[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index1 = i;
            break;
        }
    }

    if (index1 == -1) {
        // If no such pair is found, reverse the entire array
        std::reverse(nums.begin(), nums.end());
        return;
    }

    int index2 = -1;

    // Find the first element nums[j] that is greater than nums[index1]
    for (int j = n - 1; j > index1; j--) {
        if (nums[j] > nums[index1]) {
            index2 = j;
            break;
        }
    }

    // Swap nums[index1] with nums[index2]
    std::swap(nums[index1], nums[index2]);

    // Reverse the portion of the array from index1+1 to the end
    std::reverse(nums.begin() + index1 + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    std::cout << "Output: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
