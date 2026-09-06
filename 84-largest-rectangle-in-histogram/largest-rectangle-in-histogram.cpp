class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> st;
        int ans = 0, n = h.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || h[st.back()] > h[i])) {
                int height = h[st.back()];
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                ans = max(ans, height * (i - left - 1));
            }
            st.push_back(i);
        }

        return ans;
    }
};