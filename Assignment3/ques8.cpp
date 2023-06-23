#include <iostream>
#include <vector>
#include <algorithm>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    // Sort intervals based on the start time
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    // Check for overlapping intervals
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false; // Overlapping intervals found
        }
    }

    return true; // No overlapping intervals
}

int main() {
    std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    bool canAttendAllMeetings = canAttendMeetings(intervals);

    std::cout << "Output: " << (canAttendAllMeetings ? "true" : "false") << std::endl;

    return 0;
}
