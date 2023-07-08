#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> parentheses;
    stack<char> stars;

    for (char c : s) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == '*') {
            stars.push(c);
        } else {
            if (!parentheses.empty()) {
                parentheses.pop();
            } else if (!stars.empty()) {
                stars.pop();
            } else {
                return false;
            }
        }
    }

    while (!parentheses.empty() && !stars.empty()) {
        if (parentheses.top() > stars.top()) {
            return false;
        }

        parentheses.pop();
        stars.pop();
    }

    return parentheses.empty();
}

int main() {
    string s = "()";
    bool result = isValid(s);
    cout << "Is valid: " << (result ? "true" : "false") << endl;

    return 0;
}
