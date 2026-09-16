class Solution {
public:
    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int m = 2 * k;
        long long dp[2005][2005] = {0};
        long long mod = 1e9 + 7;
        for (int i = 0; i <= total; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= i && j <= m; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
        return dp[total][m];
    }
};