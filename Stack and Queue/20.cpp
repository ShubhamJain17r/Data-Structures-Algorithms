// Valid Parenthesis

// 

/*

*/

#include<bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    int n = s.length();
    if (n & 1 == 1) return false;   // if odd always invalid

    stack<char> st;
    for (const char &c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else if (c == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();       // found its matching pair
        }
        else if (c == '}') {
            if (st.empty() || st.top() != '{') return false;
            st.pop();       // found its matching pair
        }
        else {
            if (st.empty() || st.top() != '[') return false;
            st.pop();       // found its matching pair
        }
    }
    return st.empty();      // not enough closing parenthesis
}