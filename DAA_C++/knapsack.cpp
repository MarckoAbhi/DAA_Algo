#include <iostream>
#include <vector>

int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; 
}

int main() {
    int W = 50; 
    std::vector<int> weights = {10, 20, 30}; 
    std::vector<int> values = {60, 100, 120}; 
    int n = values.size(); 

    int maxValue = knapsack(W, weights, values, n);
    std::cout << "Maximum value in the knapsack: " << maxValue << std::endl;

    return 0;
}