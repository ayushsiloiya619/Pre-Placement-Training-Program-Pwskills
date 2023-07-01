#include <algorithm>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    int carry = 0;
    string result;

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        result.push_back(digit + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}
