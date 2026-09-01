class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));
        int sr = 0, sc = 0, k = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        if (k == 0) return 0;

        int full = (1 << k) - 1;

        vector<vector<vector<int>>> best(
            1 << k,
            vector<vector<int>>(m, vector<int>(n, -1))
        );

        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[0][sr][sc] = energy;

        int moves = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, rem] = q.front();
                q.pop();

                if (mask == full) return moves;

                if (rem == 0) continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int nmask = mask;
                    int nrem = rem - 1;

                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    if (classroom[nr][nc] == 'R') {
                        nrem = energy;
                    }

                    if (nrem <= best[nmask][nr][nc]) continue;

                    best[nmask][nr][nc] = nrem;
                    q.push({nr, nc, nmask, nrem});
                }
            }

            ++moves;
        }

        return -1;
    }
};