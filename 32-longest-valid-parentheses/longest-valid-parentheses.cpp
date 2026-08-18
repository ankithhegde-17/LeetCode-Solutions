#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int max_len = 0;
        std::stack<int> st;
        st.push(-1); // Base index to handle edge cases and length calculations
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // If the stack is empty, use the current index as the new base
                    st.push(i);
                } else {
                    // Calculate the length of the valid parentheses substring
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};