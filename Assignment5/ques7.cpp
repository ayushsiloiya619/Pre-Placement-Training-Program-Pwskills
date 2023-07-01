#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return nums[left];
}

int main() {
    std::vector<int> nums = {3, 4, 5, 1, 2};

    int minElement = findMin(nums);

    std::cout << "Minimum element: " << minElement << std::endl;

    return 0;
}
