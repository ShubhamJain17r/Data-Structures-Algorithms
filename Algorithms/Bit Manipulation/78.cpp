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

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsets = 1 << n;

    vector<vector<int>> res(subsets);
    for (int i = 0; i < subsets; ++i) {
        for (int bit = 0; bit < nums.size(); ++bit) {
            int num = 1 << bit;
            if (i & num)
                res[i].push_back(nums[bit]);
        }
    }
    return res;
}