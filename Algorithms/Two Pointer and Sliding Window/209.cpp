// Minimum Size Subarray Sum

// https://leetcode.com/problems/minimum-size-subarray-sum?envType=problem-list-v2&envId=vyrqwl9sz

/*
Constraints:
    1 <= target <= 10^9
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^4
*/

#include<bits/stdc++.h>

using namespace std;

// ~O(2n)
int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = INT_MAX;
    int n = nums.size();
    int l = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] >= target) return 1;        // strainght away found answer
        sum += nums[i];
        while (sum >= target) {                 // shrink size of subarray
            minLen = min(minLen, i - l + 1);
            sum -= nums[l++];
        }
    }
    return minLen != INT_MAX ? minLen : 0;      // 0 if not found
}

// helper function for nlogn solution
bool enough(int target, vector<int>& nums, int k) {
    long long sum = 0;
    for (int i = 0; i < k; ++i)
        sum += nums[i];
    if (sum >= target) return true;
    for (int r = k; r < nums.size(); ++r) {
        sum += nums[r];
        sum -= nums[r - k];
        if (sum >= target) return true;
    }
    return false;
}

// O(n logn)
int minSubArrayLenLogn(int target, vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    int minLen = INT_MAX;
    while (l <= r) {
        int m = l + ((r - l) >> 1);         // subarray size
        if (enough(target, nums, m)) {
            minLen = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return minLen != INT_MAX ? minLen : 0;
}