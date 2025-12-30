// N-Queens

// https://leetcode.com/problems/n-queens?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= n <= 9
*/

#include<bits/stdc++.h>

using namespace std;

bool isValid(vector<string> &board, int row, int col) {
    // col check
    for (int r = 0; r < row; ++r)
        if (board[r][col] == 'Q') return false;

    // top left side diag
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) 
        if (board[r][c] == 'Q') return false;

    // top right side diag
    for (int r = row - 1, c = col + 1; r >= 0 && c < board.size(); r--, c++)
        if (board[r][c] == 'Q') return false;
    return true;
}

void nQueensHelper(int n, int row, vector<string> &board, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; ++i) {           // try to fill the row by checking each cell
        if (!isValid(board, row, i)) continue;
        board[row][i] = 'Q';
        nQueensHelper(n, row + 1, board, ans);
        board[row][i] = '.';
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    nQueensHelper(n, 0, board, ans);
    return ans;
}

int main() {
    for (int i = 1; i <= 9; ++i) {
        vector<vector<string>> ans = solveNQueens(i);
        cout<<i<<" : "<<ans.size()<<endl;
    }
}