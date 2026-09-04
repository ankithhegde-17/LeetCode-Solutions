class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0), have(128, 0);
        int required = t.size();

        for (char c : t)
            need[c]++;

        int left = 0, best = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            have[c]++;

            if (have[c] <= need[c])
                required--;

            while (required == 0) {
                if (right - left + 1 < best) {
                    best = right - left + 1;
                    start = left;
                }

                have[s[left]]--;

                if (have[s[left]] < need[s[left]])
                    required++;

                left++;
            }
        }

        return best == INT_MAX ? "" : s.substr(start, best);
    }
};