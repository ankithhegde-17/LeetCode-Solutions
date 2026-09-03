class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int o = 1e9, e = 1e9;
        for (int x : a)
            if (x & 1) o = min(o, x);
            else e = min(e, x);
        return o == 1e9 || e == 1e9 || o < e;
    }
};