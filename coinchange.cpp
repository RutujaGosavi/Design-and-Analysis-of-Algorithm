/*
Implement Coin Change problem.
STATEMENT- Given an integer array of coins[] of size N representing     different types of currency and an integer sum, The task is     to find the number of ways to make sum by using different       combinations from coins[].
Note: Assume that you have an infinite supply ofeach type of coin
*/

#include <iostream>
using namespace std;

// Function to find the number of ways to make the sum using n coins of different denominations
int countsum(int coins[], int n, int sum) {
    // Create a 2D dp table of size (n+1) x (sum+1)
    int dp[n + 1][sum + 1];

    // Initialize all dp[i][0] = 1
    //because there's exactly one way to make a sum of 0: choose no coins
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Initialize all dp[0][j] = 0 for j > 0 
    //because there's no way to make any positive sum without any coins
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = 0;
    }

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
    // Include the number of ways to make the sum without using the i-th coin
            dp[i][j] = dp[i - 1][j];

            // If the coin can be used (i.e., its value is less than or equal to the current sum)
            if (coins[i - 1] <= j) {
                // Add the number of ways to make the sum by using the i-th coin
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    // Return the value in dp[n][sum], which contains the answer
    return dp[n][sum];
}

int main() {
    int coins[] = {2,5,3,6};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 10;

    cout << "Number of ways to make Sum " << sum << " is : " << countsum(coins, n, sum) << endl;

    return 0;
}