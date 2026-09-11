#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            // Check single digit validity
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Check two digit validity
            int two_digit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};