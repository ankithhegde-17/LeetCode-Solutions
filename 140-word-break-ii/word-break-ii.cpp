class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> dp;
    string s;

    vector<string> dfs(int i) {
        if (dp.count(i)) return dp[i];
        if (i == s.size()) return {""};

        vector<string> res;
        for (int j = i; j < s.size(); j++) {
            string w = s.substr(i, j - i + 1);
            if (!st.count(w)) continue;

            for (auto& x : dfs(j + 1))
                res.push_back(w + (x.empty() ? "" : " " + x));
        }
        return dp[i] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(0);
    }
};