// Restore IP Address

// https://leetcode.com/problems/restore-ip-addresses?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= s.length <= 20
    s consists of digits only.

Important:
    A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
    Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/

#include<bits/stdc++.h>

using namespace std;

bool isValid(string &s) {       // check validity of ip address section
    int z = stoi(s);
    if (z == 0) return s.length() == 1;
    if (z > 255 || (int)log10(z) + 1 != s.length()) return false;
    return true;
}
void restoreIpAddressesHelper(string &s, int idx, vector<string> &temp, vector<string> &ans) {
    if (idx == s.length()) {            // traversed 
        if (temp.size() == 4) {         // correct ip address found
            string ipAdd = "";
            for (const string &s : temp)
                ipAdd = ipAdd + s + '.';
            ipAdd.pop_back();       // remove last .
            ans.push_back(ipAdd);
        }
        return;
    }
    if (temp.size() >= 4) return;       // incomplete string used

    for (int i = idx; i < idx + 3 && i < s.length(); ++i) {
        string curr = s.substr(idx, i - idx + 1);
        if (!isValid(curr)) continue;
        temp.push_back(curr);
        restoreIpAddressesHelper(s, i + 1, temp, ans);
        temp.pop_back();
    }
}
vector<string> restoreIpAddresses(string s) {
    int n = s.length();
    if (n < 4) return {};

    // string curr = "255";     // testing isValid function
    // cout<<isValid(curr);

    vector<string> ans;
    vector<string> temp;

    restoreIpAddressesHelper(s, 0, temp, ans);

    return ans;
}