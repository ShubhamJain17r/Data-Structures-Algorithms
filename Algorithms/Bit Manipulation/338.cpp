// Counting Bits

// https://leetcode.com/problems/counting-bits?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= n <= 10^5
*/

#include<bits/stdc++.h>

using namespace std;

// suppose a number x has n 1 bits, then its double 2x will have (n + 1) 1 bits. and n + 2 if it is odd i.e. 2x + 1 as (2x + 1) / 2 = x

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}