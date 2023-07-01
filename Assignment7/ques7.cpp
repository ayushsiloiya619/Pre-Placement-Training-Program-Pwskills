#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool backspaceCompare(string s, string t) {
    return processString(s) == processString(t);
}

string processString(string str) {
    stack<char> stack;

    for (char c : str) {
        if (c != '#') {
            stack.push(c);
        } else if (!stack.empty()) {
            stack.pop();
        }
    }

    string processedStr;
    while (!stack.empty()) {
        processedStr += stack.top();
        stack.pop();
    }

    reverse(processedStr.begin(), processedStr.end());

    return processedStr;
}

int main() {
    string s = "ab#c";
    string t = "ad#c";

    bool result = backspaceCompare(s, t);

    cout << boolalpha << result << endl;

    return 0;
}
