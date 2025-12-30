// N-Queens 2

// https://leetcode.com/problems/n-queens-ii?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= n <= 9
*/

#include<bits/stdc++.h>

using namespace std;

bool isValid(vector<int> &board, int row, int col) {
    // col search
    for (int r = 0; r < row; ++r)
        if (board[r] == col) return false;
    
    // top left diag
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
        if (board[r] == c) return false;
    
    // top right diag
    for (int r = row - 1, c = col + 1; r >= 0 && c < board.size(); r--, c++)
        if (board[r] == c) return false;
    return true;
}
int totalNQueensHelper(int n, int row, vector<int> &board) {
    if (row == n) return 1;

    int count = 0;
    for (int i = 0; i < n; ++i) {           
        if (!isValid(board, row, i)) continue;
        board[row] = i;
        count += totalNQueensHelper(n, row + 1, board);
        board[row] = -1;
    }
    return count;
}
int totalNQueens(int n) {
    vector<int> board(n, -1);           // board, each index i represent row and its value represent the column in which queen is present
    return totalNQueensHelper(n, 0, board);
}

int main() {
    for (int i = 1; i <= 9; ++i) {
        int ans = totalNQueens(i);
        cout<<i<<" : "<<ans<<endl;
    }
}