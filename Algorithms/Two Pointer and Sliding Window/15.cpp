// 3Sum

// https://leetcode.com/problems/3sum?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5

Important : 
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets.
*/

#include<bits/stdc++.h>

using namespace std;

/*
Move the pointers until new element is encountered to avoid duplicacy.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;
        int target = -nums[i];
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                res.push_back({nums[i], nums[l], nums[r]});
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
    return res;
}