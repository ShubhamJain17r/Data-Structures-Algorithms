// House Robber

// https://leetcode.com/problems/house-robber?envType=problem-list-v2&envId=v1lnxa5h

/*
Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 400

Important:
    Can't rob two adjacent houses
*/

#include<bits/stdc++.h>

using namespace std;

// Brute force method, try every possiblity
int f(vector<int> &nums, int i) {
    if (i == 0)                         // base case
        return nums[0];
    if (i == 1)                         // base case
        return max(nums[0], nums[1]);
    int rob = nums[i] + f(nums, i - 2); // rob and move next to next house
    int not_rob = f(nums, i - 1);       // leave and move to next house
    return max(rob, not_rob);           // get the maximum output of all choices
}
int rob(vector<int>& nums) {
    int n = nums.size();
    return f(nums, n - 1);
}

// Using memoization
int f(vector<int> &nums, int i, vector<int> &dp) {
    if (i == 0)
        return nums[0];
    if (i == 1)
        return max(nums[0], nums[1]);
    if (dp[i] != -1)                        // if this scenario already encountered
        return dp[i];
    int rob = nums[i] + f(nums, i - 2, dp);
    int not_rob = f(nums, i - 1, dp);
    return dp[i] = max(rob, not_rob);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(nums, n - 1, dp);
}

// using tabulation - bottom up approach
// dp[i] stores the maximum amount of money robber upto index i
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        int rob = nums[i] + dp[i - 2];
        int not_rob = dp[i - 1];
        dp[i] = max(rob, not_rob);
    }
    return dp[n - 1];
}

// Space optimized
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        int rob = nums[i] + prev2;
        int not_rob = prev1;

        prev2 = prev1;
        prev1 = max(rob, not_rob);
    }
    return prev1;
}