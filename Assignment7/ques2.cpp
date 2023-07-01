#include <unordered_map>

using namespace std;

bool isStrobogrammatic(string num) {
    unordered_map<char, char> strobogrammaticDigits = {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}
    };

    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        if (strobogrammaticDigits.find(num[left]) == strobogrammaticDigits.end() ||
            strobogrammaticDigits[num[left]] != num[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
