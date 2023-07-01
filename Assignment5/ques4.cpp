#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> findDisappearedNumbers(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    std::vector<std::vector<int>> answer(2);

    for (int num : set1) {
        if (set2.find(num) == set2.end()) {
            answer[0].push_back(num);
        }
    }

    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
            answer[1].push_back(num);
        }
    }

    return answer;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    std::vector<std::vector<int>> answer = findDisappearedNumbers(nums1, nums2);

    std::cout << "Distinct numbers in nums1 not present in nums2: ";
    for (int num : answer[0]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Distinct numbers in nums2 not present in nums1: ";
    for (int num : answer[1]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
