#include <iostream>
#include <vector>

int fibonacci(int n) {
    std::vector<int> dp(n + 1, 0); 
    dp[0] = 0; 
    dp[1] = 1; 

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; 
    }

    return dp[n];
}

int main() {
    int n = 10; 
    std::cout << "Fibonacci number " << n << " is " << fibonacci(n) << std::endl;
    return 0;
}