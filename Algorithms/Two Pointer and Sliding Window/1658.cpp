// Minimum Operation to Reduce X to 0

// 

/*

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