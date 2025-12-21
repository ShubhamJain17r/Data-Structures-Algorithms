// Guess Number Higher or Lower

// https://leetcode.com/problems/guess-number-higher-or-lower?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    1 <= num <= 2^31 - 1
    i <= pick <= n
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include<bits/stdc++.h>

using namespace std;

// helper function API provided by Leet
int guess(int num) {
    int pick = 100; // suppose
    if (num == pick) return 0;
    if (num > pick) return -1;
    return 1;
}

int guessNumber(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int curr = guess(m);
        if (curr == 0) return m;
        if (curr == 1) l = m + 1;
        else           r = m - 1;
    }
    return -1;         // never executed
}