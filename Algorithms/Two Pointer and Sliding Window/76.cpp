// Minimum Window Substring

// https://leetcode.com/problems/minimum-window-substring?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

// TC : O(m + n)
string minWindow(string s, string t) {
    if (t.length() > s.length()) return "";
    if (t == s)                  return s;

    vector<int> freq(128, 0);
    for (const char &c : t)
        freq[c]++;                          // set the freq of required characters
    
    int minLen = INT_MAX;
    int idx = -1;

    int l = 0;
    int cnt = 0;
    for (int r = 0; r < s.length(); ++r) {
        char c = s[r];
        freq[c]--;

        if (freq[c] >= 0)                   // this character is present in t if not freq[c] <= -1
            cnt++;
        // cout<<r<<" "<<cnt<<endl;
        while (cnt == t.length()) {         // all characters are found
            if (minLen >= (r - l + 1)) {    // update minLen
                minLen = (r - l + 1);
                idx = l;
            }
            freq[s[l]]++;                   // remove last Character
            if (freq[s[l]] == 1)            // if any character of t is removed
                cnt--;                      // start search of that
            l++;
        }
    }
    return idx == -1 ? "" : s.substr(idx, minLen);      // idx = -1 if not found
}