// Permutations 2

// https://leetcode.com/problems/permutations-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 8
    -10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>

using namespace std;

/*
We used a set to keep track of used numbers
*/

void permuteUniqueHelper(vector<int>& nums, int start, vector<vector<int>> &ans) {
    if (start == nums.size()) {
        ans.push_back(nums);
        return;
    }

    unordered_set<int> used;
    for (int i = start; i < nums.size(); ++i) {
        if (used.count(nums[i])) continue;

        used.insert(nums[i]);
        swap(nums[i], nums[start]);
        permuteUniqueHelper(nums, start + 1, ans);
        swap(nums[start], nums[i]);
    }
}

/*
We recursively send the copy of the array not its reference
*/

// void permuteUniqueHelper(vector<int> nums, int start, vector<vector<int>>& ans){
//     if (start == nums.size()){
//         ans.push_back(nums);
//         return;
//     }

//     for (int i = start; i<nums.size(); ++i){
//         if (i > start && nums[i] == nums[start])continue;

//         swap(nums[i], nums[start]);
//         permuteUniqueHelper(nums, start + 1, ans);
//     }
// }

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, 0, ans);
    return ans;
}