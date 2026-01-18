// Integer Break

// https://leetcode.com/problems/integer-break?envType=problem-list-v2&envId=v1lnxa5h

/*
Constraints:
    2 <= n <= 58
*/

#include<bits/stdc++.h>

using namespace std;

// int integerBreak(int n) {
//     if (n <= 3) return n - 1;
//     vector<int> dp(n + 1, 1);
//     for (int i = 3; i <= n; ++i) {
//         if (i < 6) {
//             dp[i] = (i - 2) * 2;
//         }
//         else if (i == 6) {
//             dp[i] = (i - 3) * 3;
//         }
//         else {
//             dp[i] = dp[i - 3] * 3;
//         }
//     }
//     return dp[n];
// }
int integerBreak(int n) {
    if (n <= 3) return n - 1;
    int res = 1;
    while (n > 4) {
        res *= 3;
        n -= 3;
    }
    return res * n;
}