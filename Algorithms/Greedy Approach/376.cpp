// Wiggle Subsequence

// https://leetcode.com/problems/wiggle-subsequence?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 1000
    0 <= nums[i] <= 1000
*/

#include<bits/stdc++.h>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;

    int up = 1, down = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {            // going toward peak, require down + 1 to form wiggle seq
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }

    return max(up, down);
}