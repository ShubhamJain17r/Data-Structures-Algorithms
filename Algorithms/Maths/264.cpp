// Ugly Number 2

// https://leetcode.com/problems/ugly-number-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= n <= 1690
*/

#include<bits/stdc++.h>

using namespace std;

/*
Keep an iterator on previous calculated ugly numbers.
once a multiply is used on an index it wont be required further so we move the iterator.
sometimes like 2 * 3 and 3 * 2 can give symmetric answers, so we use ifs only
*/

int nthUglyNumber(int n) {
    vector<long long> dp(n, -1);
    dp[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; ++i) {
        long long next2 = dp[i2] * 2;
        long long next3 = dp[i3] * 3;
        long long next5 = dp[i5] * 5;

        dp[i] = min({next2, next3, next5});

        if (dp[i] == next2) i2++;
        if (dp[i] == next3) i3++;
        if (dp[i] == next5) i5++;
    }
    return dp[n - 1];
}