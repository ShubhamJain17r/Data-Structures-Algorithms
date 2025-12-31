// Single Number

// https://leetcode.com/problems/single-number?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 3 * 10^4
    -3 * 10^4 <= nums[i] <= 3 * 10^4
    Each element in the array appears twice except for one element which appears only once.
*/

#include<bits/stdc++.h>

using namespace std;

/*
This code works on properties of XOR operator.
a ^ a = 0       // every number appears twice, so they cancel out
a ^ 0 = a       
a ^ b ^ a = b   // single number remains last
*/

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (const int &val : nums)
        ans ^= val;
    return ans;
}