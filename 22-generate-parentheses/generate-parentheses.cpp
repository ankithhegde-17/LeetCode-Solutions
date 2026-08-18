#include <vector>
#include <string>

class Solution {
private:
    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int n) {
        // Base case: if the string length is 2 * n, we have a complete valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // We can add an open parenthesis if we haven't reached the limit n
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // We can add a close parenthesis if there are unclosed open parentheses
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};