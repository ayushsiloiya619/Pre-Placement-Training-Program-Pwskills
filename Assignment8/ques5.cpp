#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;
    int count = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && chars[i] == chars[i - 1]) {
            count++;
        } else {
            chars[idx++] = chars[i - 1];
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[idx++] = c;
                }
            }
            count = 1;
        }
    }

    return idx;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);

    cout << "New length: " << newLength << endl;
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
