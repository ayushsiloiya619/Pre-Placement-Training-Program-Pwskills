#include <iostream>
#include <unordered_set>

using namespace std;

bool buddyStrings(string s, string goal) {
    int n = s.length();
    int m = goal.length();

    // If lengths are not equal or either string is empty, return false
    if (n != m || n == 0 || m == 0) {
        return false;
    }

    // If s and goal are equal, check if there are duplicate characters in s
    if (s == goal) {
        unordered_set<char> seen;
        for (char c : s) {
            if (seen.count(c)) {
                return true;
            }
            seen.insert(c);
        }
        return false;
    }

    // Find the first pair of indices where s[i] != goal[i] and s[j] != goal[j]
    int firstDiff = -1;
    int secondDiff = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            if (firstDiff == -1) {
                firstDiff = i;
            } else if (secondDiff == -1) {
                secondDiff = i;
            } else {
                // If there are more than two differences, return false
                return false;
            }
        }
    }

    // Check if swapping the characters at firstDiff and secondDiff makes s equal to goal
    if (secondDiff != -1 && s[firstDiff] == goal[secondDiff] && s[secondDiff] == goal[firstDiff]) {
        return true;
    }

    return false;
}

int main() {
    string s = "ab";
    string goal = "ba";
    bool result = buddyStrings(s, goal);

    cout << "Can swap two letters: " << (result ? "true" : "false") << endl;

    return 0;
}
