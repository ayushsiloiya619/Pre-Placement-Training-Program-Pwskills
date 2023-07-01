#include <vector>

using namespace std;

vector<vector<int>> multiplySparseMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    // Create the transpose of mat2
    vector<vector<int>> mat2T(n, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            mat2T[j][i] = mat2[i][j];
        }
    }

    // Initialize the result matrix with zeros
    vector<vector<int>> result(m, vector<int>(n, 0));

    // Multiply the matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int p = 0; p < k; p++) {
                if (mat1[i][p] != 0 && mat2T[j][p] != 0) {
                    sum += mat1[i][p] * mat2T[j][p];
                }
            }
            result[i][j] = sum;
        }
    }

    return result;
}
