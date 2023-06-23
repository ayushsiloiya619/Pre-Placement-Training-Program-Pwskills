#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();

    // Start from the least significant digit
    for (int i = n - 1; i >= 0; i--) {
        // Increment the digit by 1
        digits[i]++;

        // If the digit is less than 10, no carry needed
        if (digits[i] < 10) {
            return digits;
        }

        // Carry occurs, set the digit to 0 and continue
        digits[i] = 0;
    }

    // If the loop completes, it means all digits were 9 and carried to 0
    // Insert a new most significant digit of 1
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    std::vector<int> digits = {1, 2, 3};

    std::vector<int> result = plusOne(digits);

    std::cout << "Output: ";
    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}
