#include <iostream>
#include <string>

using namespace std;

string reverseStr(string s, int k) {
    int n = s.length();

    for (int i = 0; i < n; i += 2 * k) {
        int left = i;
        int right = min(i + k - 1, n - 1);

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;

    string reversed = reverseStr(s, k);

    cout << reversed << endl;

    return 0;
}
