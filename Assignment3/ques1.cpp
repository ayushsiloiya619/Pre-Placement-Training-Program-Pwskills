#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int threeSumClosest(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end()); // Sort the array in ascending order

    int closestSum = INT_MAX; // Initialize closestSum to a large value
    int minDiff = INT_MAX; // Initialize minDiff to a large value

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);

            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return target; // Exact match found
            }
        }
    }

    return closestSum;
}

int main() {
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = threeSumClosest(nums, target);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
