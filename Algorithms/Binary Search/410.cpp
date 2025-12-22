// Split Array Largest Sum

// https://leetcode.com/problems/split-array-largest-sum?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 1000
    0 <= nums[i] <= 10^6
    1 <= k <= min(50, nums.length)

Important : 
    Return the minimized largest sum of the split.
    A subarray is a contiguous part of the array.
*/

#include<bits/stdc++.h>

using namespace std;

bool enough(vector<int>& nums, int k, int subArrraySum) {
    int sum = 0;
    int K = 1;
    for (const int &val : nums) {
        sum += val;
        if (sum > subArrraySum) {
            K++;
            sum = val;
        }
    }
    return K <= k;
}

int splitArray(vector<int>& nums, int k) {
    int l = *max_element(nums.begin(), nums.end());
    int r = l * 2;
    while (!enough(nums, k, r)) r = r * 2;
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        if (enough(nums, k, m)) r = m - 1;
        else                    l = m + 1;
    }
    return l;
}
