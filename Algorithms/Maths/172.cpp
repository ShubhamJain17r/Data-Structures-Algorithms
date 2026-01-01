// Factorial Trailing Zeroes

// https://leetcode.com/problems/factorial-trailing-zeroes?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= n <= 10^4
*/

#include<bits/stdc++.h>

using namespace std;

/*
A zero can appear only if 2*5 appears in the multiplication. when taking factorial we get 2's a lot so the count of 5's is always less than the count of 2's. Number of zeroes = min(count(2), count(5)) in prime factorization of each number in factorial.
we only need to count the fives for our answer.

*/

int trailingZeroes(int n) {
    int fives = 0;
    for (int i = 5; i <= n; i += 5) {   // iterate only on the multiples of 5
        int x = i;
        while (x % 5 == 0) {
            fives++;
            x /= 5;
        }
    }
    return fives;
}