class Solution {
    int dp[30][30][31];

    bool f(string& a, string& b, int i, int j, int len) {
        int& r = dp[i][j][len];
        if (r != -1) return r;
        if (a.substr(i, len) == b.substr(j, len)) return r = 1;

        int c[26] = {};
        for (int k = 0; k < len; k++) {
            c[a[i + k] - 'a']++;
            c[b[j + k] - 'a']--;
        }
        for (int x : c) if (x) return r = 0;

        for (int k = 1; k < len; k++)
            if (f(a, b, i, j, k) && f(a, b, i + k, j + k, len - k) ||
                f(a, b, i, j + len - k, k) && f(a, b, i + k, j, len - k))
                return r = 1;

        return r = 0;
    }

public:
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return f(s1, s2, 0, 0, s1.size());
    }
};