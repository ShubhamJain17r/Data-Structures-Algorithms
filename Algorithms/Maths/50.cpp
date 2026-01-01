// Pow(x, n)

// https://leetcode.com/problems/powx-n?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:

    -100.0 < x < 100.0
    -2^31 <= n <= 2^31-1
    n is an integer.
    Either x is not zero or n > 0.
    -10^4 <= x^n <= 10^4
*/

#include<bits/stdc++.h>

using namespace std;

/*
x^n = (x^2)^(n/2)   (if n is even)
x ^ n = x * x^(n - 1)  (if n is odd) this x we multiply to ans 
*/

double myPow(double x, int n) {
    if (x == 1) return x;
    if (n == INT_MIN) return x == -1;
    if (n == 0) return 1;

    int n_ = n;
    n = abs(n);

    double ans = 1;

    while (n > 0) {
        if (n & 1 == 1) {
            ans *= x;
            n--;
        }
        else {
            x *= x;
            n >>= 1;
        }
    }

    if (n_ < 0) return 1 / ans;
    return ans;
}