// Valid Anagrams

// https://leetcode.com/problems/valid-anagram?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= s.length, t.length <= 5 * 10^4
    s and t consist of lowercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    int n = s.length(), m = t.length();
    if (n != m) return false;

    int hash[26] = {0};
    for (int i = 0; i < n; ++i) {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i)
        if (hash[i] != 0) return false;
    
    return true;
}