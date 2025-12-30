// Palindrome Partitioning

// https://leetcode.com/problems/palindrome-partitioning?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s) {              // check palindrome
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}
void partitionHelper(string &s, int idx, vector<string> &temp, vector<vector<string>> &ans) {
    if (idx == s.length()) {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < s.length(); ++i) {
        string curr = s.substr(idx, i - idx + 1);   // get curr subset
        if (!isPalindrome(curr)) continue;

        temp.push_back(curr);
        partitionHelper(s, i + 1, temp, ans);   // partition from next index
        temp.pop_back();
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> temp;
    partitionHelper(s, 0, temp, ans);
    return ans;
}