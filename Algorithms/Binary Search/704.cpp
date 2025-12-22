// Binary Search

// https://leetcode.com/problems/binary-search?envType=problem-list-v2&envId=vyrqwl9s

/*
constraints : 
    1 <= nums.length <= 10^4
    -10^4 < numss[i], target < 10^4
    all the integers in nums are unique
    nums is sorted in ascending order

Important : 
    if number does not exist, return -1
    if number exist return its index.
    you must write an algorithm with O(log n) runtime complexity.
*/

#include<bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);     // ( >> works as division by 2)
        int mid = nums[m];
        if (mid == target) return m;    // element found
        if (mid <  target) l = m + 1;   // element does not exist in the left half of m
        else               r = m - 1;   // element does not exist in the right half of m
    }
    return -1;                          // element not found
}