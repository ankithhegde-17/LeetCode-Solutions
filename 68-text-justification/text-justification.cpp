class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int len = 0;

            while (j < n) {
                int newLen = len + words[j].size() + (j > i ? 1 : 0);
                if (newLen > maxWidth) break;
                len = newLen;
                ++j;
            }

            int wordCount = j - i;
            string line;

            if (j == n || wordCount == 1) {
                for (int k = i; k < j; ++k) {
                    if (k > i) line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int wordLen = 0;
                for (int k = i; k < j; ++k) {
                    wordLen += words[k].size();
                }

                int spaces = maxWidth - wordLen;
                int gaps = wordCount - 1;
                int extra = spaces / gaps;
                int rem = spaces % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int cnt = extra + (k - i < rem ? 1 : 0);
                        line += string(cnt, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};