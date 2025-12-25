// Longest Substring without repeating characters

// https://leetcode.com/problems/longest-substring-without-repeating-characters?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.
*/

#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> seen(256, -1);                      // last seen
    int maxLen = 0, l = 0;

    for (int r = 0; r < s.length(); ++r) {
        if (seen[s[r]] != -1 && seen[s[r]] >= l)    // if already seen upgrade l to its next of last seen
            l = seen[s[r]] + 1;
        maxLen = max(maxLen, r - l + 1);
        seen[s[r]] = r;                             // upgrade seen
    }
    return maxLen;
}