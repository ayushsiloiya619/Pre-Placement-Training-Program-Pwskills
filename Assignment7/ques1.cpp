#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> charMap;
    unordered_set<char> mappedChars;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (charMap.find(c1) == charMap.end()) {
            if (mappedChars.find(c2) != mappedChars.end()) {
                return false;
            }
            charMap[c1] = c2;
            mappedChars.insert(c2);
        } else {
            if (charMap[c1] != c2) {
                return false;
            }
        }
    }

    return true;
}
