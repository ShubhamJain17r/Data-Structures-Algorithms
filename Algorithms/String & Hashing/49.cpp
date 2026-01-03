// Group Anagrams

// https://leetcode.com/problems/group-anagrams?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= strs.length <= 10^4
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> hash;
    int idx = 0;
    for (string s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        if (hash.count(t) == 0) {
            ans.push_back({s});
            hash[t] = idx;
            idx++;
        }
        else {
            int i = hash[t];
            ans[i].push_back(s);
        }
    }
    return ans;
}