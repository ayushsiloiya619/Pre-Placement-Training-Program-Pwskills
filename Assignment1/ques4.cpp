#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    int carry = 1;

    for (int i = n - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0) {
            break;
        }
    }

    if (carry != 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main() {
    std::vector<int> digits = {1, 2, 3};

    std::vector<int> result = plusOne(digits);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
