// Longest Substring with at most k Distinct Characters

#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.length();
    if (n == 0 || k == 0) return 0;
    unordered_map<char, int> m;
    int maxLen = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        m[s[r]]++;
        while (m.size() > k) {
            m[s[l]]--;
            if (m[s[l]] == 0)
                m.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
