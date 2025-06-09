#include <iostream>
#include <vector>
#include <algorithm> 
long long stockMaximize(const std::vector<int>& prices) {
    long long profit = 0;
    int maxPrice = 0; 
    for (int i = prices.size() - 1; i >= 0; --i) {
        if (prices[i] >= maxPrice) {
            maxPrice = prices[i];
        } else {
            profit += static_cast<long long>(maxPrice) - prices[i];
        }
    }

    return profit;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; 
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> prices[i];
        }

        std::cout << stockMaximize(prices) << std::endl;
    }

    return 0;
}