#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid) {
        constexpr int kMod = 12345;
        const int m = grid.size();
        const int n = grid[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        std::vector<long long> prefix{1};
        long long suffix = 1;
        for (const auto& row : grid)
            for (const int num : row)
                prefix.push_back((prefix.back() * num) % kMod);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                ans[i][j] = (prefix[i * n + j] * suffix) % kMod;
                suffix = (suffix * grid[i][j]) % kMod;
            }
        }
        return ans;
    }
};