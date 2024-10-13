/*Implement Check if it is possible to transform one string to 
another.
Statement Given two strings s1 and s2 (all letters in uppercase). 
Check if it is possible to convert s1 to s2 by performing following 
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
*/

#include<iostream>
using namespace std;

// Function to check if string s1 can be transformed into string s2
bool check(string s1, string s2)
{
    // Get the length of both strings
    int n = s1.length();
    int m = s2.length();
    
    // Create a 2D array dp where dp[i][j] is true if it is possible
    // to convert the first i characters of s1 to the first j characters of s2
    bool dp[n + 1][m + 1];
    
    // Initialize the dp array to false initially
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = false;
        }
    }

    // Mark dp[0][0] as true since an empty string can be converted to another empty string
    dp[0][0] = true;

    // Traverse through the dp array and fill it based on conditions
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            // If dp[i][j] is true, we can proceed with further transformations
            if(dp[i][j]) {
                
                // Case 1: If characters match (either directly or by making lowercase uppercase)
                if(j < s2.length() && (toupper(s1[i]) == s2[j])) {
                    dp[i+1][j+1] = true; // Mark the next position as true
                }

                // Case 2: If s1[i] is a lowercase letter, we can "delete" it and move to the next
                if(!isupper(s1[i])) {
                    dp[i+1][j] = true;
                }
            }
        }
    }

    // The result is whether we can fully transform s1 into s2
    return dp[n][m];
}

int main()
{
    string s1 = "argaju"; // Input string s1
    string s2 = "RAJ";   // Input string s2

    // Output whether s1 can be transformed into s2
    if(check(s1, s2))
        cout << "YES!!!!!" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
