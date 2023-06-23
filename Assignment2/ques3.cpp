#include <iostream>
#include <vector>
#include <unordered_map>

int findLHS(std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    int maxLength = 0;

    // Count the frequency of each number
    for (int num : nums) {
        count[num]++;
    }

    // Check each number and its complement
    for (auto it = count.begin(); it != count.end(); ++it) {
        int num = it->first;
        int freq = it->second;

        if (count.find(num + 1) != count.end()) {
            int complementFreq = count[num + 1];
            maxLength = std::max(maxLength, freq + complementFreq);
        }
    }

    return maxLength;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    int result = findLHS(nums);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
