// Letter Combinations of a Phone Number

// https://leetcode.com/problems/letter-combinations-of-a-phone-number?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9']
*/

#include<bits/stdc++.h>

using namespace std;

// mapping              0   1    2      3      4      5      6       7      8       9
vector<string> mapp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinationsHelper(string digits, int idx, string &temp, vector<string> &ans) {
    if (idx == digits.length()) {
        ans.push_back(temp);
        return;
    }

    int digit = digits[idx] - '0';
    for (const char &c : mapp[digit]) {
        temp.push_back(c);
        letterCombinationsHelper(digits, idx + 1, temp, ans);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string temp;
    letterCombinationsHelper(digits, 0, temp, ans);
    return ans;
}