#include <iostream>
#include <vector>
#include <algorithm>

int minimumProductSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end(), std::greater<int>());

    int minProductSum = 0;
    for (int i = 0; i < nums1.size(); i++) {
        minProductSum += nums1[i] * nums2[i];
    }

    return minProductSum;
}

int main() {
    std::vector<int> nums1 = {5, 3, 4, 2};
    std::vector<int> nums2 = {4, 2, 2, 5};

    int minProductSum = minimumProductSum(nums1, nums2);

    std::cout << "Minimum product sum: " << minProductSum << std::endl;

    return 0;
}
