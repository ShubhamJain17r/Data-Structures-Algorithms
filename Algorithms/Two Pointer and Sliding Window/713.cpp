// Subaray Product less than K

// https://leetcode.com/problems/subarray-product-less-than-k?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 3 * 10^4
    1 <= nums[i] <= 1000
    0 <= k <= 10^6
*/

#include<bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int cnt = 0;
    int l = 0;
    long long prod = 1;
    for (int r = 0; r < nums.size(); ++r) {
        prod *= nums[r];
        while (l <= r && prod >= k) {
            prod /= nums[l];
            l++;
        }
        if (prod < k) {
            cnt += (r - l + 1);
        }
        // cout<<r<<" "<<cnt<<endl;
    }
    return cnt;
}