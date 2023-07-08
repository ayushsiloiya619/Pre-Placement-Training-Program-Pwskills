#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> strStack;
    string currentStr = "";
    int currentCount = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currentCount = currentCount * 10 + (c - '0');
        } else if (isalpha(c)) {
            currentStr += c;
        } else if (c == '[') {
            countStack.push(currentCount);
            strStack.push(currentStr);
            currentCount = 0;
            currentStr = "";
        } else if (c == ']') {
            int repeatCount = countStack.top();
            countStack.pop();

            string decodedStr = "";
            for (int i = 0; i < repeatCount; i++) {
                decodedStr += currentStr;
            }

            string prevStr = strStack.top();
            strStack.pop();

            currentStr = prevStr + decodedStr;
        }
    }

    return currentStr;
}

int main() {
    string s = "3[a]2[bc]";
    string decodedString = decodeString(s);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
