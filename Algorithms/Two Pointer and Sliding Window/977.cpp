// Squares of a Sorted Array

// https://leetcode.com/problems/squares-of-a-sorted-array?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    nums is sorted in non-decreasing order.
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    int r = 0;
    for (; r < n; ++r) {
        if (nums[r] >= 0) break;                // find first occurance of non negative number
    }
    int l = r - 1;                              // largest -ve number is at this index.
    // if no negative number in array then l = -1
    
    while (l >= 0 || r < n) {
        int ls = l >= 0 ? nums[l] * nums[l] : INT_MAX;  // if valid index
        int rs = r < n  ? nums[r] * nums[r] : INT_MAX;

        if (rs < ls) {                          // add smaller number
            res.push_back(rs);
            r++;
        }
        else {
            res.push_back(ls);
            l--;
        }
    }
    return res;
}