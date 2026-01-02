// Divide Two Integers

// https://leetcode.com/problems/divide-two-integers?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0

Important:
    Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
*/

#include<bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {
    long long d = abs(1LL * dividend);      // abs to avoid cases of negative number, long long to avoid error converting -2^31 to integer type
    long long n = abs(1LL * divisor);

    bool negative = false;                  // to know whether our answer is -ve or not
    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) negative = true;

    if (dividend == 0) return 0;
    if (d == n) return negative ? -1 : 1;
    if (n > d) return 0;

    long long q = 0;
    while (d >= n) {
        int cnt = 1;
        while ((n << cnt) < d) cnt++;      
        q += (1 << (cnt - 1));             // increment according to powers of 2
        d = d - (n << (cnt - 1));
    }
    if (negative) {
        if (q > INT_MAX)
            return INT_MIN;
        return ~q + 1;
    }
    return q >= INT_MAX ? INT_MAX : q;
}