// Nth - Tribonacci Number

// https://leetcode.com/problems/n-th-tribonacci-number?envType=problem-list-v2&envId=v1lnxa5h

/*
Constraints:
    0 <= n <= 37
    The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1

*/

#include<bits/stdc++.h>

using namespace std;

// int f(int n) {
//     if (n == 0) return 0;
//     if (n == 1 || n == 2) return 1;

//     return f(n - 1) + f(n - 2) + f(n - 3);
// }
// int tribonacci(int n) {
//     return f(n);
// }
// -----------------------------------------------------------------------------
// int f(int n, vector<int> &dp) {
//     if (n == 0) return 0;
//     if (n == 1 || n == 2) return 1;

//     if (dp[n] != -1) return dp[n];

//     return dp[n] = f(n - 1, dp) + f(n - 2, dp) + f(n - 3, dp);
// }
// int tribonacci(int n) {
//     vector<int> dp(n + 1, -1);
//     return f(n, dp);
// }
// --------------------------------------------------------------------------------
// int tribonacci(int n) {
//     if (n == 0) return 0;
//     if (n == 1 || n == 2) return 1;

//     vector<int> dp(n + 1, 0);
//     dp[0] = 0, dp[1] = 1, dp[2] = 1;

//     for (int i = 3; i <= n; ++i) {
//         dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//     }
//     return dp[n];
// }
// ------------------------------------------------------------------------------
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int prev3 = 0, prev2 = 1, prev1 = 1;

    for (int i = 3; i <= n; ++i) {
        int curr = prev1 + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}