// Number of 1 Bits

// https://leetcode.com/problems/number-of-1-bits?envType=problem-list-v2&envId=vyrqwl9s

/*
constraints:
    1 <= n <= 2^31 - 1
*/

#include<bits/stdc++.h>

using namespace std;

int hammingWeight(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt += (n & 1);     // if first bit equal to 1;
        n >>= 1;
    }
    return cnt;

    // return __builtin_popcount(n);
}