class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                q.push({m - 1, j});
            }
        }

        int d[5] = {1, 0, -1, 0, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + d[k];
                int nc = c + d[k + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i][j] == '#' ? 'O' : 'X';
    }
};