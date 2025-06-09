#include <iostream>
#include <vector>
#include <algorithm> 
std::vector<int> maxSubarray(const std::vector<int>& arr) {
    std::vector<int> result(2);

    int maxCurrent = arr[0];
    int maxGlobal = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        maxCurrent = std::max(arr[i], maxCurrent + arr[i]);
        maxGlobal = std::max(maxGlobal, maxCurrent);
    }
    result[0] = maxGlobal;

    int maxNonContig = 0;
    int maxElement = arr[0]; 
    bool hasPositive = false;

    for (int num : arr) {
        if (num > 0) {
            maxNonContig += num;
            hasPositive = true;
        }
        if (num > maxElement) {
            maxElement = num;
        }
    }

    result[1] = hasPositive ? maxNonContig : maxElement;

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); 

    int t;
    std::cin >> t; 

    while (t--) {
        int n;
        std::cin >> n; 

        std::vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[j]; 
        }

        std::vector<int> result = maxSubarray(arr); 

        std::cout << result[0] << " " << result[1] << std::endl;
    }

    return 0;
}