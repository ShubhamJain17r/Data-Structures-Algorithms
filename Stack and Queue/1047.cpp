// Remove all Adjacent Duplicates in String

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string?envType=problem-list-v2&envId=v1lwf7tc

/*
Constraints:
    1 <= s.length <= 10^5
    s consists of lowercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

string removeDuplicates(string s) {
    int i = 0;
    stack<char> st;

    while (i != s.length()) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
        i++;
    }

    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    if (ans.length() > 0) 
        reverse(ans.begin(), ans.end());

    return ans;
}