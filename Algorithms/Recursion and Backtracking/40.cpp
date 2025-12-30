// Combination Sum 2

// https://leetcode.com/problems/combination-sum-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/

#include<bits/stdc++.h>

using namespace std;

void combinationSum2Helper(vector<int>& candidates, int target, int idx, vector<int> &temp, vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    if (idx == candidates.size()) return;
    for (int i = idx; i < candidates.size(); ++i) {
        if (i > idx && candidates[i] == candidates[i - 1]) continue;    // avoid duplicates
        int val = candidates[i];
        if (val > target) return;

        temp.push_back(val);
        combinationSum2Helper(candidates, target - val, i + 1, temp, ans);  // move to next index
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combinationSum2Helper(candidates, target, 0, temp, ans);
    return ans;
}