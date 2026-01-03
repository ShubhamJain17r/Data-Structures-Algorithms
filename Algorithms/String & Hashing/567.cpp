// Permutation in String

// https://leetcode.com/problems/permutation-in-string?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2) {     // brute force O(m.n)
    int n = s1.length(), m = s2.length();
    if (n > m) return false;

    int hash1[26] = {0};
    for (const char &c : s1)
        hash1[c - 'a']++;

    for (int j = n; j <= m; ++j) {
        int hash2[26] = {0};
        // cout<<s2.substr(j - n, n)<<endl;
        for (int i = j - n; i < j; ++i) 
            hash2[s2[i] - 'a']++;
        bool flag = true;
        for (int i = 0; i < 26 && flag; ++i) {
            if (hash1[i] != hash2[i]) 
                flag = false;
        }
        if (flag)
            return true;
    }
    return false;
}

// O(m)
bool checkInclusion(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    if (n > m) return false;

    int hash1[26] = {0};
    int hash2[26] = {0};
    for (int i = 0; i < n; ++i) {
        hash1[s1[i] - 'a']++;
        hash2[s2[i] - 'a']++;
    }
    for (int j = n; j <= m; ++j) {
        // cout<<s2.substr(j - n, n)<<endl;
        bool flag = true;
        for (int i = 0; i < 26 && flag; ++i) {
            if (hash1[i] != hash2[i]) 
                flag = false;
        }
        if (flag)
            return true;
        if (j == m) return false;
        hash2[s2[j - n] - 'a']--;
        hash2[s2[j] - 'a']++;
    }
    return false;
}