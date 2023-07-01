#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return false;
    }

    int left = 0;
    int right = n - 1;

    while (left < n - 1 && arr[left] < arr[left + 1]) {
        left++;
    }

    while (right > 0 && arr[right] < arr[right - 1]) {
        right--;
    }

    if (left == 0 || right == n - 1 || left == right) {
        return false;
    }

    return true;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    bool isValid = validMountainArray(arr);

    std::cout << (isValid ? "Valid mountain array" : "Not a valid mountain array") << std::endl;

    return 0;
}
