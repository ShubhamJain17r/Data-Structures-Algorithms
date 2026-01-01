// Happy Number

// https://leetcode.com/problems/happy-number?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= n <= 231 - 1

*/

#include<bits/stdc++.h>

using namespace std;

bool isHappy(int n) {
    unordered_set<int> hash;
    while (n != 1 && (hash.count(n) == 0)) {
        int sumOfSquare = 0;
        hash.insert(n);
        while (n > 0) {
            int rem = n % 10;
            sumOfSquare += (rem * rem);
            n /= 10;
        }
        n = sumOfSquare;
    }
    return n == 1;
}