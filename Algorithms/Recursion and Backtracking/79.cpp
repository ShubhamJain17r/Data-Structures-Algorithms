// Word Search

// https://leetcode.com/problems/word-search?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.
*/

#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j) {
    if (idx == word.length()) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) return false;

    char c = board[i][j];
    board[i][j] = '#';
    if (dfs(board, word, idx + 1, i + 1, j)) return true;
    if (dfs(board, word, idx + 1, i - 1, j)) return true;
    if (dfs(board, word, idx + 1, i, j + 1)) return true;
    if (dfs(board, word, idx + 1, i, j - 1)) return true;
    board[i][j] = c;
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
    }
    return false;
}