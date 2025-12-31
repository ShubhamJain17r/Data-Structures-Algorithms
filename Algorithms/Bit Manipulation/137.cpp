// Single Number 2

// https://leetcode.com/problems/single-number-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 3 * 10^4
    -2^31 <= nums[i] <= 2^31 - 1
    Each element in nums appears exactly three times except for one element which appears once.
*/

#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (const int &val : nums) {
        ones = ones ^ val & ~twos;
        twos = twos ^ val & ~ones;
    }
    return ones;
}