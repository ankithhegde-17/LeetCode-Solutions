#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        // Sort the array lexicographically
        std::sort(strs.begin(), strs.end());
        
        // The common prefix of the whole array must be a common prefix 
        // of the first and the last strings in the sorted array.
        std::string first = strs.front();
        std::string last = strs.back();
        std::string result = "";
        
        for (size_t i = 0; i < first.length(); ++i) {
            if (i < last.length() && first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }
        
        return result;
    }
};