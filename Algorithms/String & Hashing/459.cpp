// Repeated Substring Pattern

// https://leetcode.com/problems/repeated-substring-pattern?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= s.length <= 10^4
    s consists of lowercase English letters
*/

#include<bits/stdc++.h>

using namespace std;

bool repeatedSubstringPattern(string s) {
    string t = s + s;
    return t.substr(1, t.size() - 2).find(s) != string::npos;
}