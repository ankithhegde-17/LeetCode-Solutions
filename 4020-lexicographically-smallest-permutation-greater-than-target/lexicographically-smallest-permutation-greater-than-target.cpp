#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> total(26, 0);
        for (char c : s)
            total[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> used(26, 0);

            for (int j = 0; j < i; j++)
                used[target[j] - 'a']++;

            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (used[c] > total[c]) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            vector<int> rem(26);

            for (int c = 0; c < 26; c++)
                rem[c] = total[c] - used[c];

            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);

                rem[c]--;

                for (int x = 0; x < 26; x++) {
                    while (rem[x] > 0) {
                        ans += char('a' + x);
                        rem[x]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};