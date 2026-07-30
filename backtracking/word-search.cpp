class Solution {
public:
    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string word) {
        if (ind == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (board[i][j] != word[ind])
            return false;

        char ch = board[i][j];
        board[i][j] = '#';

        bool found = dfs(i + 1, j, ind + 1, board, word) ||
                     dfs(i - 1, j, ind + 1, board, word) ||
                     dfs(i, j + 1, ind + 1, board, word) ||
                     dfs(i, j - 1, ind + 1, board, word);

        board[i][j] = ch;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};