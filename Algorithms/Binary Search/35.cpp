// Search insert Position

// https://leetcode.com/problems/search-insert-position?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    1 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    numscontains distinct values sorted in ascending order
    -10^4 <= target <= 10^4

Important :
    return the index if the target is found, if not return the index where it would be if it were inserted in order.
    You must write an algorithm with O(log n) runtime complexity.
*/

#include<bits/stdc++.h>

using namespace std;

/*
ans = minimum index where arr[idx] >= target

use lower bound logic
*/

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int lb = nums.size();             // if target > nums[last]
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int mid = nums[m];
        if (mid < target)   l = m + 1;
        else {
            lb = m;         // insert position
            r = m - 1;
        }
    }
    return lb;

    // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}