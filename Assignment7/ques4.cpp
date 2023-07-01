#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string reverseWords(string s) {
    istringstream iss(s);
    string word;
    string result;

    while (iss >> word) {
        reverse(word.begin(), word.end());
        result += word + " ";
    }

    result.pop_back();  // Remove the trailing space

    return result;
}

int main() {
    string s = "Let's take LeetCode contest";

    string reversed = reverseWords(s);

    cout << reversed << endl;

    return 0;
}
