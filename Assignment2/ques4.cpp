#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    int i = 0;

    while (i < size) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            count++;

            if (count >= n) {
                return true;
            }
        }

        i++;
    }

    return false;
}

int main() {
    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    bool result = canPlaceFlowers(flowerbed, n);

    std::cout << "Output: " << std::boolalpha << result << std::endl;

    return 0;
}
