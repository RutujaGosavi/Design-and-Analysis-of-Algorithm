/*
Implement Subset Sum Problem.
STATEMENT- Given a set of non-negative integers and a value sum, the task is to check if there is a subset of the given set whose sum is equal to the given sum.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to determine if there exists a subset of set[]
// whose sum is equal to the given 'sum'
bool isSubsetSum(int set[], int n, int sum)
{
    // Create a 2D array `subset` where subset[i][j] will be true
    // if there is a subset of set[0..i-1] with sum equal to 'j'
    bool subset[n + 1][sum + 1];

    // If the sum is 0, then the subset is always true (empty subset)
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If the set is empty but sum is not 0, no subset can form the sum
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table using the bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If the current element is greater than the sum,
            // exclude it from the subset
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            // Otherwise, check if the sum can be obtained either by:
            // 1. Excluding the current element
            // 2. Including the current element and checking the remaining sum
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    // Return the result whether a subset with the given sum exists or not
    return subset[n][sum];
}

// Driver code to test the function
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 }; // Input set of numbers
    int sum = 30;                        // Target sum
    int n = sizeof(set) / sizeof(set[0]); // Number of elements in the set
    
    // Output whether a subset with the given sum exists
    if (isSubsetSum(set, n, sum))
        cout << "Found a subset with given sum!!!!";
    else
        cout << "No subset with given sum";
    
    return 0;
}
