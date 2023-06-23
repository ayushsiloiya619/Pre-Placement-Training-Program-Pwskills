#include <iostream>
#include <vector>

std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::string> result;

    long long next = lower;  // Use long long to handle potential integer overflow

    for (int num : nums) {
        if (num > next) {
            result.push_back(getRange(next, num - 1));
        }
        next = (long long)num + 1;
    }

    if (next <= upper) {
        result.push_back(getRange(next, upper));
    }

    return result;
}

std::string getRange(int start, int end) {
    return (start == end) ? std::to_string(start) : std::to_string(start) + "->" + std::to_string(end);
}

int main() {
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    std::vector<std::string> result = findMissingRanges(nums, lower, upper);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
