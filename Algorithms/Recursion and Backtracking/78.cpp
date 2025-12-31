// Subsets

// https://leetcode.com/problems/subsets?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/

#include<bits/stdc++.h>

using namespace std;

void subsetsHelper(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &ans) {
    ans.push_back(temp);
    for (int i = idx; i < nums.size(); ++i) {
        temp.push_back(nums[i]);
        subsetsHelper(nums, i + 1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    subsetsHelper(nums, 0, temp, ans);
    return ans;
}