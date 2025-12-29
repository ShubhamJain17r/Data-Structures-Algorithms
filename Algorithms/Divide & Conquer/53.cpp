// Maximum Subarray

// https://leetcode.com/problems/maximum-subarray?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:

    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
*/

#include<bits/stdc++.h>

using namespace std;

int maxCrossingSum(vector<int>& nums, int l, int m, int r) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += nums[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += nums[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArrayHelper(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];

    int mid = l + (r - l) / 2;

    int left = maxSubArrayHelper(nums, l, mid);
    int right = maxSubArrayHelper(nums, mid + 1, r);
    int cross = maxCrossingSum(nums, l, mid, r);

    return max({left, right, cross});
}

int maxSubArray(vector<int>& nums) {
    return maxSubArrayHelper(nums, 0, nums.size() - 1);
}


// Kadane's Algorithm
// int maxSubArray(vector<int>& nums) {
//     int currSum = nums[0];
//     int maxSum = nums[0];

//     for (int i = 1; i < nums.size(); i++) {
//         currSum = max(nums[i], currSum + nums[i]);
//         maxSum = max(maxSum, currSum);
//     }
//     return maxSum;
// }
