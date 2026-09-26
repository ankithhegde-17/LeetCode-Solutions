class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string w, ans;
        
        while (ss >> w) v.push_back(w);
        
        for (int i = v.size() - 1; i >= 0; i--) {
            ans += v[i];
            if (i) ans += ' ';
        }
        
        return ans;
    }
};