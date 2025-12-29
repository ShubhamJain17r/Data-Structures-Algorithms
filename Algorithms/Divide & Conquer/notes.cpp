#include<bits/stdc++.h>

using namespace std;

/*
====================================================
DIVIDE & CONQUER — NOTES (C++)
====================================================

This file contains:
- General D&C template
- Common combine patterns
- Classic problem snippets
- Interview-ready comments

----------------------------------------------------
1️⃣ GENERAL DIVIDE & CONQUER TEMPLATE
----------------------------------------------------
*/

// ResultType solve(InputType input) {
//     // 1. Base Case
//     if (isSmallest(input)) {
//         return baseAnswer(input);
//     }

//     // 2. Divide
//     auto leftPart  = splitLeft(input);
//     auto rightPart = splitRight(input);

//     // 3. Conquer
//     ResultType leftResult  = solve(leftPart);
//     ResultType rightResult = solve(rightPart);

//     // 4. Combine
//     return combine(leftResult, rightResult);
// }

/*
----------------------------------------------------
2️⃣ PATTERN A: CHOOSE BEST (Max / Min)
----------------------------------------------------
Used in: Maximum Subarray
*/

int maxSubArrayDC(vector<int>& a, int l, int r) {
    if (l == r) return a[l];

    int mid = (l + r) / 2;

    int left = maxSubArrayDC(a, l, mid);
    int right = maxSubArrayDC(a, mid + 1, r);

    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return max({left, right, leftSum + rightSum});
}

/*
----------------------------------------------------
3️⃣ PATTERN B: AGREEMENT CHECK
----------------------------------------------------
Used in: Majority Element
*/

int majorityElementDC(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];

    int mid = (l + r) / 2;

    int left = majorityElementDC(nums, l, mid);
    int right = majorityElementDC(nums, mid + 1, r);

    if (left == right) return left;

    int countL = 0, countR = 0;
    for (int i = l; i <= r; i++) {
        if (nums[i] == left) countL++;
        if (nums[i] == right) countR++;
    }

    return countL > countR ? left : right;
}

/*
----------------------------------------------------
4️⃣ PATTERN C: CARTESIAN PRODUCT
----------------------------------------------------
Used in: Different Ways to Add Parentheses
*/

unordered_map<string, vector<int>> memo;

vector<int> compute(string expr) {
    if (memo.count(expr)) return memo[expr];

    vector<int> result;

    for (int i = 0; i < expr.size(); i++) {
        char op = expr[i];
        if (op == '+' || op == '-' || op == '*') {
            auto left = compute(expr.substr(0, i));
            auto right = compute(expr.substr(i + 1));

            for (int l : left)
                for (int r : right) {
                    if (op == '+') result.push_back(l + r);
                    if (op == '-') result.push_back(l - r);
                    if (op == '*') result.push_back(l * r);
                }
        }
    }

    if (result.empty())
        result.push_back(stoi(expr));

    return memo[expr] = result;
}

/*
----------------------------------------------------
5️⃣ PATTERN D: MERGE
----------------------------------------------------
Used in: Merge Sort, Count Inversions
*/

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r)
        temp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];
}

/*
----------------------------------------------------
FINAL NOTE
----------------------------------------------------

Key Interview Insight:
"Fix the last operation, recursion solves the rest."

If recursion feels hard:
- Identify split
- Define subproblem
- Write base case
- Combine answers

Everything else is implementation.
====================================================
*/
