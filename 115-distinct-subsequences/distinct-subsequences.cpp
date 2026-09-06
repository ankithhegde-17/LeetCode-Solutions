class Solution {
public:
    int numDistinct(string s, string t) {
        const int M = INT_MAX;
        vector<int> dp(t.size() + 1);
        dp[0] = 1;

        for (char c : s)
            for (int j = t.size() - 1; j >= 0; --j)
                if (c == t[j])
                    dp[j + 1] = min<long long>(M, (long long)dp[j + 1] + dp[j]);

        return dp[t.size()];
    }
};