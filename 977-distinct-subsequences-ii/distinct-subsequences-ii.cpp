
#include <string>
#include <vector>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        int n = s.length();
        long long mod = 1e9 + 7;
        std::vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        std::vector<int> last(26, -1);
        
        for (int i = 1; i <= n; ++i) {
            int x = s[i - 1] - 'a';
            dp[i] = (2 * dp[i - 1]) % mod;
            if (last[x] != -1) {
                dp[i] = (dp[i] - dp[last[x]] + mod) % mod;
            }
            last[x] = i - 1;
        }
        
        return (dp[n] - 1 + mod) % mod;
    }
};