#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') pos.push_back(i);
        }

        if ((int)pos.size() < k) return "";

        int bestLen = INT_MAX;
        string ans;

        for (int i = 0; i + k - 1 < (int)pos.size(); ++i) {
            int l = pos[i];
            int r = pos[i + k - 1];
            int len = r - l + 1;
            string cur = s.substr(l, len);

            if (len < bestLen || (len == bestLen && cur < ans)) {
                bestLen = len;
                ans = cur;
            }
        }

        return ans;
    }
};