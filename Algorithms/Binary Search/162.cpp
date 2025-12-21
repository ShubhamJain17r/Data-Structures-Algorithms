// Find Peak Element

// https://leetcode.com/problems/find-peak-element?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    1 <= nums.length <= 1000
    -2^31 <= nums[i] <= 2^31 - 1
    nums[i] != nums[i + 1] for all valid i.
Important : 
    Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
    You may imagine that nums[-1] = nums[n] = INT_MIN. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
    You must write an algorithm that runs in O(log n) time
*/

#include<bits/stdc++.h>

using namespace std;

/*
upward slope    : arr[i - 1] < arr[i] < arr[i + 1]
downward slope  : arr[i - 1] > arr[i] > arr[i + 1]
peak            : arr[i - 1] < arr[i] > arr[i + 1]
valley          : arr[i - 1] > arr[i] < arr[i + 1]

always move towards peak
if in valley move to either side
*/

int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;                // as nums[-1] == INT_MIN
    if (nums[n - 2] < nums[n - 1]) return n - 1;    // as nums[n] == INT_MIN

    int l = 1, r = n - 2;

    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int mid = nums[m];
        if (nums[m - 1] < mid && mid > nums[m + 1])         return m;
        if (nums[m - 1] < nums[m] && nums[m] < nums[m + 1]) l = m + 1;
        else                                                r = m - 1;
    }
    return -1;  // never executed
}