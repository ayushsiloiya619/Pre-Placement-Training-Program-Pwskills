#include <iostream>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> indices;

    if (s.empty() || p.empty() || p.length() > s.length()) {
        return indices;
    }

    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);

    // Count the frequencies of characters in p
    for (char c : p) {
        pCount[c - 'a']++;
    }

    int pLength = p.length();
    int sLength = s.length();

    // Initialize the sliding window
    for (int i = 0; i < pLength; i++) {
        sCount[s[i] - 'a']++;
    }

    // Check each window in s for anagram of p
    for (int i = pLength; i <= sLength; i++) {
        if (pCount == sCount) {
            indices.push_back(i - pLength);
        }

        // Slide the window by removing the leftmost character and adding the rightmost character
        if (i < sLength) {
            sCount[s[i] - 'a']++;
            sCount[s[i - pLength] - 'a']--;
        }
    }

    return indices;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    cout << "Start indices of p's anagrams in s: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
