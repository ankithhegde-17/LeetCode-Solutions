class Solution {
public:
    string build(string half, char mid, bool odd) {
        string res = half;
        if (odd) res += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());
        res += rev;

        return res;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int oddCount = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                oddCount++;
                middle = char('a' + i);
            }
        }

        if (oddCount > 1)
            return "";

        int h = n / 2;
        bool odd = n % 2;

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        string ans = "";

        auto check = [&](const string& half) {
            string cur = build(half, middle, odd);
            if (cur > target && (ans.empty() || cur < ans))
                ans = cur;
        };

        vector<int> rem = halfCnt;

        for (int i = 0; i < h; i++) {
            if (i > 0) {
                int x = target[i - 1] - 'a';

                if (rem[x] == 0)
                    break;

                rem[x]--;
            }

            int need = target[i] - 'a';

            for (int c = need + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                vector<int> cur = rem;
                cur[c]--;

                string half = target.substr(0, i);
                half += char('a' + c);

                for (int x = 0; x < 26; x++)
                    half.append(cur[x], char('a' + x));

                check(half);
            }
        }

        rem = halfCnt;
        bool exact = true;

        for (int i = 0; i < h; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                exact = false;
                break;
            }

            rem[x]--;
        }

        if (exact) {
            string half = target.substr(0, h);

            if (!odd) {
                check(half);
            } else {
                check(half);
            }
        }

        return ans;
    }
};