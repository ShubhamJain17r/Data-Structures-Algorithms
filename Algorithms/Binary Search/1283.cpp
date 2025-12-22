// Find Smallest Divisor Given a Threshold

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 5 * 10^4
    1 <= nums[i] <= 10^6
    nums.length <= threshold <= 10^6
*/

#include<bits/stdc++.h>

using namespace std;

int divisorSum(vector<int> &nums, int divisor) {
    int sum = 0;
    for (const int &num : nums)
        sum += static_cast<int>(ceil(num / static_cast<double>(divisor)));
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (divisorSum(nums, m) > threshold) l = m + 1;
        else                                 r = m - 1;
    }
    return l;
}