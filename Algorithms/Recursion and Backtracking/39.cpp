// Combination Sum

// https://leetcode.com/problems/combination-sum?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40
*/

#include<bits/stdc++.h>

using namespace std;

void combinationSumHelper(vector<int> &candidates, int target, int idx, vector<int> &temp, vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    if (idx == candidates.size()) return;

    for (int i = idx; i < candidates.size(); i++) {
        int val = candidates[i];
        if (val > target) return;
        temp.push_back(val);
        combinationSumHelper(candidates, target - val, i, temp, ans);   // can reuse the same index
        temp.pop_back();
    }

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combinationSumHelper(candidates, target, 0, temp, ans);
    return ans;
}

int main() {
    vector<int> candidates = {2,2,3,3,6,7};     // used this test case for testing effect on duplicates. useful for combination sum 2


    int target = 7;
    // int target = 8;

    // vector<int> candidates;
    // for (int i = 0; i < 30; ++i) {
    //     candidates.push_back(i + 2);
    // }
    // int target = 40;
    vector<vector<int>> ans = combinationSum(candidates, target);

    for (const auto &vec : ans) {
        for (const int &val : vec) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<candidates.size()<<endl;
}