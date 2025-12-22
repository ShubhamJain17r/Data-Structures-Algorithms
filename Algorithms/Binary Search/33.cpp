// Search in Rotated Sorted Array

// https://leetcode.com/problems/search-in-rotated-sorted-array?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    1 <= nums.length <= 5000
    -10^4 <= nums[i], target <= 10^4
    all values of nums are unique
    nums is an ascending array that is possibly rotated

Important : 
    return index of target if found else return -1
    You must write an algorithm with O(log n) runtime complexity.
*/

#include<bits/stdc++.h>
using namespace std;

// {1,2,3,4,5,6,7,8,9,10}   ->   0 rotations
// {3,4,5,6,7,8,9,10,1,2}   ->   k rotations
// mid == 7
// left half of 7 is sorted

// {9,10,1,2,3,4,5,6,7,8}
// right half of mid is sorted

int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int mid = nums[m];
        if (mid == target)  return m;

        // if left half of mid is sorted
        if (mid >= nums[l]) {
            if (nums[l] <= target && mid > target)
                r = m - 1;
            else
                l = m + 1;
        }

        // right half is sorted
        else {
            if (nums[r] >= target && mid < target)
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
}