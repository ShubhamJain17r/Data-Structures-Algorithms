// Climbing Stairs

// https://leetcode.com/problems/climbing-stairs?envType=problem-list-v2&envId=v1lnxa5h

/*
Constraints:
    1 <= n <= 45

Important:
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include<bits/stdc++.h>

using namespace std;

/*
Intution : at the nth stair, how many steps do i need to reach at 0th of 1st stair.
*/

// Recursive Code
int climbStairs(int n) {
    if (n <= 1) 
        return 1;           // base case
    return climbStairs(n - 1) + climbStairs(n - 2);     // from nth stair we can make 2 either go one starir down or 2. we have to return the total ways to reach bottom to add them up
}

// Memoization - dp[n] stores at nth stair how many ways are there to reach bottom
int f(int n, vector<int>& dp) {
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return f(n, dp);
}

// The above two code we of top down approach, where we start from the end goal to find keeping the known base cases as ending point.

// Tabulation - we start from known base cases and move ahead using the previous computed cases.
// Bottom up approach
int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;              // base case
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimized  - we dont require full dp array for comutation, we only require the previous two states
int climbStairs(int n) {
    int prev1 = 1, prev2 = 1;   // similar to dp[i - 1],  dp[i - 2];
    int curr = 0;
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2;   // dp[i] = dp[i - 1] + dp[i - 2]
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}