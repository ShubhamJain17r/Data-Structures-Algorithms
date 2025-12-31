// Missing Number

// https://leetcode.com/problems/missing-number?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    n == nums.length
    1 <= n <= 10^4
    0 <= nums[i] <= n
    All the numbers of nums are unique
*/

#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
    int XOR = 0;
    for (const int &val : nums)
        XOR ^= val;
    int n = nums.size();
    if (n % 4 == 0) return n ^ XOR;
    if (n % 4 == 1) return 1 ^ XOR;
    if (n % 4 == 2) return (n + 1) ^ XOR;
    return XOR;
}