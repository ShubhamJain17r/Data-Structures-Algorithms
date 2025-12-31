// Bitwise AND of Number range

// https://leetcode.com/problems/bitwise-and-of-numbers-range?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= left <= right <= 2^31 - 1
*/

#include<bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int left, int right) {
    while (right > left) {
        right = right & (right - 1);
    }
    return right;
}