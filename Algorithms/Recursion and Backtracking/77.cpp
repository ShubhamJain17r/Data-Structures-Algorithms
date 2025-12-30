// Combinations

// https://leetcode.com/problems/combinations?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= n <= 20
    1 <= k <= n
*/

#include<bits/stdc++.h>

using namespace std;

void combineHelper(int n, int k, int idx, vector<vector<int>> &ans, vector<int> &temp) {
    if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }

    for (int i = idx; i <= n; ++i) {
        temp.push_back(i);
        combineHelper(n, k, i + 1, ans, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    combineHelper(n, k, 1, ans, temp);
    return ans;
}