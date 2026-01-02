// Multiply Strings

// https://leetcode.com/problems/multiply-strings?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= num1.length, num2.length <= 200
    num1 and num2 consist of digits only.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include<bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2) {
    int n = num1.length(), m = num2.length();
    if (m > n) multiply(num2, num1);

    if (num1 == "0" || num2 == "0") return "0";

    string ans = "";
    for (int i = 0; i < m + n; ++i)
        ans.push_back('0');
    int j = m - 1;
    while (j >= 0) {
        int i = n - 1;
        int carry = 0;
        int a = num2[j] - '0';
        while (i >= 0) {
            int b = num1[i] - '0';
            int idx = i + j + 1;
            int mul = a * b + carry + ans[idx] - '0';
            ans[idx] = (mul % 10) + '0';
            carry = mul / 10;
            i--;
        }
        ans[j] = carry + '0';
        j--;
    }
    int i = 0;
    for (; i < ans.length() && ans[i] == '0'; i++);
    return i == ans.length() ? "0" : ans.substr(i);
}