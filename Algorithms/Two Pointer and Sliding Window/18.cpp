// 4Sum

// https://leetcode.com/problems/4sum?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 200
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9

Important : 
    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
        0 <= a, b, c, d < n
        a, b, c, and d are distinct.
        nums[a] + nums[b] + nums[c] + nums[d] == target
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;

            int l = j + 1, r = n - 1;
            while (l < r) {
                long long sum = static_cast<long long>(nums[i] + nums[j]) + nums[l] + nums[r];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++, r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (sum < target) {
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
                else {
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
    }
    return res;
}