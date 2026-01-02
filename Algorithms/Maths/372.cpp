// Super Pow

// https://leetcode.com/problems/super-pow?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= a <= 2^31 - 1
    1 <= b.length <= 2000
    0 <= b[i] <= 9
    b does not contain leading zeros.
*/

#include<bits/stdc++.h>

using namespace std;

/*
a^(b1b2...bn) = ((1 * (a^b1)^10 * a^b2)^10 * a^b3 ... )
*/

static const int MOD = 1337;
int modPow(int a, int k) {
    int res = 1;
    a %= MOD;
    while (k > 0) {
        if (k & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        k >>= 1;
    }
    return res;
}

int superPow(int a, vector<int>& b) {
    int result = 1;
    a %= MOD;

    for (const int &digit : b) {
        result = modPow(result, 10);
        result = (result * modPow(a, digit)) % MOD;
    }

    return result;
}