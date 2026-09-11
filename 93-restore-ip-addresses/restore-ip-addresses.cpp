#include <vector>
#include <string>

class Solution {
private:
    bool isValid(const std::string& s) {
        if (s.empty() || s.length() > 3) return false;
        if (s[0] == '0' && s.length() > 1) return false;
        int val = std::stoi(s);
        return val >= 0 && val <= 255;
    }

    void backtrack(const std::string& s, int startIndex, int dots, std::string currentIP, std::vector<std::string>& result) {
        if (dots == 3) {
            if (isValid(s.substr(startIndex))) {
                result.push_back(currentIP + s.substr(startIndex));
            }
            return;
        }
        
        for (int i = 1; i <= 3 && startIndex + i < s.length(); ++i) {
            std::string segment = s.substr(startIndex, i);
            if (isValid(segment)) {
                backtrack(s, startIndex + i, dots + 1, currentIP + segment + ".", result);
            }
        }
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        backtrack(s, 0, 0, "", result);
        return result;
    }
};