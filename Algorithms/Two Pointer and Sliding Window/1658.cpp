// Minimum Operation to Reduce X to 0

// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^4
    1 <= x <= 10^9
*/

#include<bits/stdc++.h>

using namespace std;

/*
We redefined ou problem for finding totalSum - x
question is similar to find max subarray with sum (TS - x)
*/

int minOperations(vector<int>& nums, int x) {
    int n = nums.size();

    long long totalSum = 0;
    for (const int &v : nums) totalSum += v;

    if (totalSum < x) return -1;    // not possible to find
    if (totalSum == x) return n;

    long long target = totalSum - x;

    int l = 0;
    int sum = 0;
    int maxLen = -1;
    for (int r = 0; r < n; ++r) {       // max Subarray target sum
        sum += nums[r];
        while (sum > target) {
            sum -= nums[l];
            l++;
        }
        if (sum == target)
            maxLen = max(maxLen, r - l + 1);
    }
    if (maxLen == -1) return -1;
    return n - maxLen;
}