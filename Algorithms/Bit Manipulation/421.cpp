// Maximum XOR of Two Numbers in an Array

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 2 * 10^5
    0 <= nums[i] <= 2^31 - 1
*/

#include<bits/stdc++.h>

using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int mask = 0, ans = 0;

    for (int bit = 31; bit >= 0; bit--) {
        mask |= (1 << bit);

        unordered_set<int> prefixes;
        for (int num : nums) {
            prefixes.insert(num & mask);
        }

        int candidate = ans | (1 << bit);

        for (int p : prefixes) {
            if (prefixes.count(p ^ candidate)) {
                ans = candidate;
                break;
            }
        }
    }
    return ans;
}