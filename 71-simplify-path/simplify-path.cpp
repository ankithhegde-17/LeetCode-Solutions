class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string s;
        stringstream ss(path);
        
        while (getline(ss, s, '/')) {
            if (s == "..") {
                if (!st.empty()) st.pop_back();
            } else if (!s.empty() && s != ".") {
                st.push_back(s);
            }
        }

        string ans;
        for (auto &x : st) ans += "/" + x;
        return ans.empty() ? "/" : ans;
    }
};