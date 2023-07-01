#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() != goal.length())
        return false;

    string temp = s + s;
    return temp.find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    bool result = rotateString(s, goal);

    cout << boolalpha << result << endl;

    return 0;
}
