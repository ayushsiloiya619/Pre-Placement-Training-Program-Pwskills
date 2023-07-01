#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n <= 2) {
        return true;  // If there are 2 or fewer points, they always form a straight line
    }

    // Calculate the slope between the first two points
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];
    int slopeX = x1 - x0;
    int slopeY = y1 - y0;

    // Check if all other points lie on the same line
    for (int i = 2; i < n; i++) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];

        // Calculate the slope between the current point and the first point
        int currentSlopeX = x - x0;
        int currentSlopeY = y - y0;

        // If the slopes are not equal, the points do not lie on the same line
        if (slopeX * currentSlopeY != slopeY * currentSlopeX) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

    bool result = checkStraightLine(coordinates);

    cout << boolalpha << result << endl;

    return 0;
}
