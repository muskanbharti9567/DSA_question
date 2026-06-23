class Solution {
public:
    int n, m;
    vector<int> di{-1, 1, 0, 0};
    vector<int> dj{0, 0, 1, -1};
    bool found;

    void search(vector<vector<char>>& board, string& word, pair<int, int> pos, int len) {
        auto [i, j] = pos;
        
        if (len == word.size())
            found = true;

        if (found)
            return;

        char temp = board[i][j];
        board[i][j] = '*';

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            bool in_bounds = ni >= 0 && ni < n && nj >= 0 && nj < m;
            
            if (in_bounds && board[ni][nj] == word[len]) {
                search(board, word, {ni, nj}, len + 1);
            }
        }

        board[i][j] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); m = board[0].size();
        found = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    search(board, word, {i, j}, 1);
                    
                    if (found)
                        return true;
                }
            }
        }

        return false;
    }
};