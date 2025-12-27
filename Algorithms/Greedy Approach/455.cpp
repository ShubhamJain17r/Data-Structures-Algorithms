// Assign Cookies

// https://leetcode.com/problems/assign-cookies?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= g.length <= 3 * 10^4
    0 <= s.length <= 3 * 10^4
    1 <= g[i], s[j] <= 2^31 - 1

Important :
    Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
*/

#include<bits/stdc++.h>

using namespace std;

/*
This problem can be solved by greedily sorting the greed factor and size arrays.
*/

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    
    int cnt = 0;
    int i = 0;
    int j = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {     // if the size enough to satisfy
            cnt++;
            i++;                // check for next greed factor
        }
        j++;                    // always move to next size
    }
    return cnt;
}