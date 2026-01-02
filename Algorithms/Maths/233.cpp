// Number of Digit One

// https://leetcode.com/problems/number-of-digit-one?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= n <= 10^9
*/

#include<bits/stdc++.h>

using namespace std;

int countDigitOne(int n) {
    long long count = 0;
    long long factor = 1;   // 1, 10, 100, ...

    while (factor <= n) {
        long long lower = n % factor;
        long long curr  = (n / factor) % 10;
        long long higher = n / (factor * 10);

        if (curr == 0) {
            count += higher * factor;
        } else if (curr == 1) {
            count += higher * factor + (lower + 1);
        } else { // curr > 1
            count += (higher + 1) * factor;
        }

        factor *= 10;
    }

    return (int)count;
}
