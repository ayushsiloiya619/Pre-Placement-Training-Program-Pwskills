#include <iostream>

int arrangeCoins(int n) {
    int row = 0;
    while (n >= row + 1) {
        row++;
        n -= row;
    }

    return row;
}

int main() {
    int n = 8;
    std::cout << arrangeCoins(n) << std::endl; // Output: 3

    return 0;
}
