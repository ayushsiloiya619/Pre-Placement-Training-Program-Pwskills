#include <vector>

std::vector<std::vector<int>> convertTo2DArray(std::vector<int>& original, int m, int n) {
    int size = original.size();
    if (size != m * n) {
        return {}; // Return empty 2D array if it is impossible
    }

    std::vector<std::vector<int>> result(m, std::vector<int>(n));

    for (int i = 0; i < size; i++) {
        int row = i / n;
        int col = i % n;
        result[row][col] = original[i];
    }

    return result;
}
