// Permutations

// https://leetcode.com/problems/permutations?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.
*/

#include<bits/stdc++.h>

using namespace std;

/*
for a fixed index, swap that element with every index ahead of it. ans swap back when backtracking

*/

void permuteHelper(vector<int>& nums, int i, vector<vector<int>> &ans) {
    if (i == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int idx = i; idx < nums.size(); ++idx) {
        swap(nums[i], nums[idx]);
        // for (const int &v : nums)
        //     cout<<v<<" ";
        // cout<<endl;
        permuteHelper(nums, i + 1, ans);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    permuteHelper(nums, 0, ans);
    return ans;
}