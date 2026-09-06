class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> h(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;

            vector<int> st;
            for (int j = 0; j <= m; j++) {
                while (!st.empty() && (j == m || h[st.back()] > h[j])) {
                    int x = h[st.back()];
                    st.pop_back();
                    int l = st.empty() ? -1 : st.back();
                    ans = max(ans, x * (j - l - 1));
                }
                st.push_back(j);
            }
        }

        return ans;
    }
};