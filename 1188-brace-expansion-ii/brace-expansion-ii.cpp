class Solution {
    int i = 0;

    set<string> merge(set<string> a, set<string> b) {
        a.insert(b.begin(), b.end());
        return a;
    }

    set<string> combine(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (const string& x : a)
            for (const string& y : b)
                res.insert(x + y);
        return res;
    }

    set<string> parse(string& s) {
        set<string> res, cur = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                res = merge(res, cur);
                cur = {""};
                i++;
            } else {
                set<string> part;

                if (s[i] == '{') {
                    i++;
                    part = parse(s);
                    i++;
                } else {
                    part = {string(1, s[i])};
                    i++;
                }

                cur = combine(cur, part);
            }
        }

        return merge(res, cur);
    }

public:
    vector<string> braceExpansionII(string expression) {
        set<string> ans = parse(expression);
        return vector<string>(ans.begin(), ans.end());
    }
};