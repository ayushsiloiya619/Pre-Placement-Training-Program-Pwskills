#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;
    int num = 1;

    while (num <= n * n) {
        // Fill top row
        for (int col = colStart; col <= colEnd; col++) {
            matrix[rowStart][col] = num++;
        }
        rowStart++;

        // Fill rightmost column
        for (int row = rowStart; row <= rowEnd; row++) {
            matrix[row][colEnd] = num++;
        }
        colEnd--;

        // Fill bottom row
        for (int col = colEnd; col >= colStart; col--) {
            matrix[rowEnd][col] = num++;
        }
        rowEnd--;

        // Fill leftmost column
        for (int row = rowEnd; row >= rowStart; row--) {
            matrix[row][colStart] = num++;
        }
        colStart++;
    }

    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 4;
    std::vector<std::vector<int>> matrix = generateMatrix(n);
    printMatrix(matrix);

    return 0;
}
