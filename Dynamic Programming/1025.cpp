// Divisor Game

// https://leetcode.com/problems/divisor-game?envType=problem-list-v2&envId=v1lnxa5h

/*
Constraints:
    1 <= n <= 1000
*/

#include<bits/stdc++.h>

using namespace std;

bool f(int n, bool chance, vector<vector<int>> &dp) {
    if (n == 1) 
        return !chance;          // true for alice, false for bob
    if (dp[n][chance] != -1)
        return dp[n][chance];

    return dp[n][chance] = f(n - 1, !chance, dp);
}
bool divisorGame(int n) {
    vector<vector<int>> dp(n + 1, vector<int> (2, -1));
    return f(n, true, dp);
}

// Alice wins if and only if N is even.

// Most Optimized
bool divisorGame(int n) {
    return ((n & 1) == 0);      // if 
}