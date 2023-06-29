#include <iostream>
#include <vector>

int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
    int minA = m;
    int minB = n;

    for (const auto& op : ops) {
        minA = std::min(minA, op[0]);
        minB = std::min(minB, op[1]);
    }

    return minA * minB;
}

int main() {
    int m = 3;
    int n = 3;
    std::vector<std::vector<int>> ops = {{2, 2}, {3, 3}};

    int maxIntegers = maxCount(m, n, ops);

    std::cout << "Number of maximum integers: " << maxIntegers << std::endl;

    return 0;
}
