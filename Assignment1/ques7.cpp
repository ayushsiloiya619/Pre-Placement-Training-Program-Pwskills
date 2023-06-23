#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 0;

    while (right < n) {
        if (nums[right] != 0) {
            std::swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    std::cout << "Output: [";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
