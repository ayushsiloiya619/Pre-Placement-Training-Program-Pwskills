#include <iostream>
#include <vector>
#include <string>

std::vector<int> reconstructPermutation(std::string s) {
    std::vector<int> perm;
    int low = 0;
    int high = s.size();

    for (char ch : s) {
        if (ch == 'I') {
            perm.push_back(low);
            low++;
        } else if (ch == 'D') {
            perm.push_back(high);
            high--;
        }
    }

    perm.push_back(low); // or perm.push_back(high)

    return perm;
}

int main() {
    std::string s = "IDID";

    std::vector<int> perm = reconstructPermutation(s);

    std::cout << "Permutation: ";
    for (int num : perm) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
