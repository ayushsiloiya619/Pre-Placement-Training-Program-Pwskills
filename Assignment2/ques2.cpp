#include <iostream>
#include <vector>
#include <unordered_set>

int distributeCandies(std::vector<int>& candyType) {
    std::unordered_set<int> uniqueCandies;

    for (int candy : candyType) {
        uniqueCandies.insert(candy);
    }

    int maxCandies = candyType.size() / 2;
    int numUniqueCandies = uniqueCandies.size();

    return std::min(maxCandies, numUniqueCandies);
}

int main() {
    std::vector<int> candyType = {1, 1, 2, 2, 3, 3};

    int result = distributeCandies(candyType);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
