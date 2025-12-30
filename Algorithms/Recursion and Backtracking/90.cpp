// Subsets 2

// https://leetcode.com/problems/subsets-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>

using namespace std;

void subsetsWithDupHelper(vector<int>& nums, int idx, vector<vector<int>> &subsets, vector<int> &temp) {
    subsets.push_back(temp);
    for (int i = idx; i < nums.size(); ++i) {
        if (i > idx && nums[i] == nums[i - 1]) continue;    // skip duplicates
        temp.push_back(nums[i]);
        subsetsWithDupHelper(nums, i + 1, subsets, temp);   // move to next index after adding
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subsets;
    vector<int> temp;
    subsetsWithDupHelper(nums, 0, subsets, temp);
    return subsets;
}