#include <iostream>

int arrangeCoins(int n) {
    long long left = 0;
    long long right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sum = (mid * (mid + 1)) / 2;

        if (sum == n) {
            return mid;  // Found the exact number of complete rows
        } else if (sum < n) {
            left = mid + 1;  // Move to the right half
        } else {
            right = mid - 1;  // Move to the left half
        }
    }

    return right;  // Return the largest number of complete rows
}

int main() {
    int n = 5;

    int completeRows = arrangeCoins(n);

    std::cout << "Number of complete rows: " << completeRows << std::endl;

    return 0;
}
