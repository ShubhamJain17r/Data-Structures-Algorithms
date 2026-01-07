// Min Cost Climbing Stairs

// https://leetcode.com/problems/min-cost-climbing-stairs?envType=problem-list-v2&envId=v1lnxa5h

/*
Constraints:
    2 <= cost.length <= 1000
    0 <= cost[i] <= 999
*/

#include<bits/stdc++.h>

using namespace std;

// Tabulation code
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n == 1) return cost[0];                 // single element in cost array element in cost array
    vector<int> dp(n, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for (int i = 2; i < n; ++i) {               // dp[i] = min cost to reach the ith stair
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    // for (const int &v : dp) 
    //     cout<<v<<" ";
    // cout<<endl;
    return min(dp[n - 1], dp[n - 2]);           // min cost stair to choose to reach the top
}

// Space optimized
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n == 1) return cost[0];
    int prev2 = cost[0];
    int prev1 = cost[1];
    
    for (int i = 2; i < n; ++i) {
        int curr = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}
