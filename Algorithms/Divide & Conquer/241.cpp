// Different Ways to Add Parenthesis

// https://leetcode.com/problems/different-ways-to-add-parentheses?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= expression.length <= 20
    expression consists of digits and the operator '+', '-', and '*'.
    All the integer values in the input expression are in the range [0, 99].
    The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
*/

#include<bits/stdc++.h>

using namespace std;

unordered_map<string, vector<int>> memo;

vector<int> solve(string expr) {
    // Memoization
    if (memo.count(expr))
        return memo[expr];

    vector<int> result;

    for (int i = 0; i < expr.size(); i++) {
        char op = expr[i];

        // If operator found, split
        if (op == '+' || op == '-' || op == '*') {
            string leftExpr  = expr.substr(0, i);
            string rightExpr = expr.substr(i + 1);

            vector<int> leftResults  = solve(leftExpr);
            vector<int> rightResults = solve(rightExpr);

            // Combine results
            for (int l : leftResults) {
                for (int r : rightResults) {
                    if (op == '+') result.push_back(l + r);
                    else if (op == '-') result.push_back(l - r);
                    else if (op == '*') result.push_back(l * r);
                }
            }
        }
    }

    // Base case: pure number
    if (result.empty())
        result.push_back(stoi(expr));

    return memo[expr] = result;
}

vector<int> diffWaysToCompute(string expression) {
    return solve(expression);
}