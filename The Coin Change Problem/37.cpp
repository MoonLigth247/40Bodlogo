#include <iostream>
#include <vector>
#include <numeric> 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; 
    int m; 

    std::cin >> n >> m;

    std::vector<int> coins(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> coins[i];
    }

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1; 

    for (int coin : coins) {
        for (int amount = coin; amount <= n; ++amount) {
            dp[amount] += dp[amount - coin];
        }
    }

    std::cout << dp[n] << std::endl;

    return 0;
}