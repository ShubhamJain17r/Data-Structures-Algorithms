// Find first and last position of element in sorted array

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    0 <= nums.length <= 10^5
    -10^9 <= nums[i], target <= 10^9
    nums is a non decreasing array

Important :
    If target is not found in the array, return [-1, -1].
    You must write an algorithm with O(log n) runtime complexity.
*/

#include<bits/stdc++.h>

using namespace std;

/*
if number doesn't exist, answer = [-1, -1]
else
    starting index = lower bound of target
    ending index = upper bound of target - 1
*/

int lower_bound(vector<int>& arr, int val) {
    // smallest index such that arr[idx] >= n

    int l = 0, r = arr.size() - 1;
    int lb = arr.size();
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int mid = arr[m];

        if (mid < val)      l = m + 1;
        else {
            lb = m;
            r = m - 1;
        }
    }
    return lb;
}

int upper_bound(vector<int>& arr, int val) {
    // smallest index such that arr[idx] > n

    int l = 0, r = arr.size() - 1;
    int ub = arr.size();
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int mid = arr[m];

        if (mid <= val)      l = m + 1;
        else {
            ub = m;
            r = m - 1;
        }
    }
    return ub;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int si = lower_bound(nums, target);
    if (si == nums.size() || nums[si] != target)  return {-1, -1};
    int ei = upper_bound(nums, target);
    return {si, ei - 1};
}