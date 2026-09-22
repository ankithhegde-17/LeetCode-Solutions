#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        std::vector<int> dp(n);
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) {
            int min_cuts = i;
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (i - j <= 1 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    if (j == 0) {
                        min_cuts = 0;
                    } else {
                        min_cuts = std::min(min_cuts, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = min_cuts;
        }
        return dp[n - 1];
    }
};