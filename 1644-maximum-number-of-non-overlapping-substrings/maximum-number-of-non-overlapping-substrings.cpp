class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, n), r(26, -1);
        for (int i = 0; i < n; ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        auto get = [&](int i) {
            int start = l[s[i] - 'a'], end = r[s[i] - 'a'];
            for (int j = start; j <= end; ++j) {
                if (l[s[j] - 'a'] < start) return -1;
                end = max(end, r[s[j] - 'a']);
            }
            return end;
        };
        vector<vector<int>> ivs;
        for (int i = 0; i < n; ++i) {
            if (i == l[s[i] - 'a']) {
                int end = get(i);
                if (end != -1) ivs.push_back({end, i});
            }
        }
        sort(ivs.begin(), ivs.end());
        vector<string> res;
        int last = -1;
        for (auto& iv : ivs) {
            if (iv[1] > last) {
                res.push_back(s.substr(iv[1], iv[0] - iv[1] + 1));
                last = iv[0];
            }
        }
        return res;
    }
};