// Find a Peak element 2

// https://leetcode.com/problems/find-a-peak-element-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 500
    1 <= mat[i][j] <= 105
    No two adjacent cells are equal.

Important :
    You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
    You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

#include<bits/stdc++.h>

using namespace std;

/*
if the element is max in the column no need to check vertically.
if the left element is greater than the max col elemt of the curr. then the left one is already greater than all of the element in curr col.
*/

int findMaxCol(vector<vector<int>>& mat, int col) {
    int maxi = 0;
    int idx = -1;
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        if (mat[i][col] > maxi) {
            maxi = mat[i][col];
            idx = i;
        }
    }
    return idx;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        int maxIdx = findMaxCol(mat, mid);

        int midEl = mat[maxIdx][mid];

        int left = (mid - 1 >= 0) ? mat[maxIdx][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[maxIdx][mid + 1] : -1;

        if (midEl > left && midEl > right) return {maxIdx, mid};
        if (midEl < left)                  r = mid - 1;
        else                               l = mid + 1;
    }
    return {-1, -1};
}